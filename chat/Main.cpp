#include<ctime>
#include <boost/thread/thread.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "Room.h"
#include "Logger.h"
#include "TreadForClient.h"
typedef boost::shared_ptr<tcp::socket> socket_ptr;

boost::asio::io_service service;
tcp::acceptor acceptor(service, tcp::endpoint(tcp::v4(), 1234));
void MainFuncTread(socket_ptr sock);
bool FoundNick(string _nick);
std::mutex lock_map;
std::mutex lock_Queue;
Room MyRoom;

string DoingCommand(string data, string _nick, bool &exit)
{
	string command;
	json msg;
	msg["type"] = "1";
	msg["from"] = "server";
	msg["to"] = _nick;
	int pos = data.find(" ");
	if (pos == -1)
		pos = data.size();
	command = data.substr(0, pos);
	if (command == "-history")
	{
		msg["text"] = "Last 10 message: \n" + MyRoom.ReturnTenMes();
	}
	else
	{
		if (command == "-users")
		{
			lock_Queue.lock();
			string str = "connected user :" + to_string(MsgQueueMap.size()) + "\n";		
			for (auto i : MsgQueueMap)
			{
				str += (i.first) + "\n";
			}
			msg["text"] = str;
			lock_Queue.unlock();
		}
		else
		{
			if (command == "-ls")
			{
				int minlength = 10; //-ls+" "+"4 symbol nick"+" "+"1symbol msg"
				if (data.size() < minlength)
				{
					msg["text"] = "Bad command \n";
				}
				else
				{
					data = data.substr(pos + 1, data.size());
					pos = data.find(" ");
					if (pos == -1)
					{
						msg["text"] = "Bad command \n";
					}
					else
					{
						string whom = data.substr(0, pos);
						if (!FoundNick(whom))
						{
							msg["text"] = "Bad command \n";

						}
						else
						{
							data = data.substr(pos + 1, data.size());
							string text = data.substr(0, data.size());
							msg["type"] = "3";
							msg["from"] = _nick;
							msg["to"] = whom;
							msg["text"] = text + "\n";
							if (msg["to"] != msg["from"])
							{
								MyRoom.SendSomebody(msg);
							}
							msg["text"] = " / to " + msg.at("to").get<string>() + " / " + msg.at("text").get<string>();
						}
					}
				}

			}
			else
			{
				if (command == "-exit")
				{
					exit = 1;
					lock_map.lock();
					MsgQueueMap.erase(_nick);		
					lock_map.lock();
					string str = "The user '" + _nick + "' has been disconnected \n";
					Logger::Instance().AddStr(to_simple_string(boost::posix_time::second_clock::local_time()) + ":" + str);
					json msg2 = { {"type","1"},{"from","server"},{"to","all"},{"text", str} };
					MyRoom.AddInRoom(msg2);
					msg["text"] = "Discconected \n";
				}
				else
				{
					if (command == "-download")
					{
						msg["type"] = 4;
						msg["text"] = "Download...\n";

					}
					else
					{
						msg["text"] = "Bad command \n";
					}
				}
			}
		}
	}
	return msg.dump();
}

bool FoundNick(string _nick)
{
	for (auto i : MsgQueueMap)
	{
		if ((i.first) == _nick)
			return 1;
	}
	
	return 0;
}

int main()
{
	boost::thread th(boost::bind(&Logger::AddAllRec, boost::ref(Logger::Instance())));
	while (1)
	{
		try
		{
			boost::asio::streambuf boost_stream;
			socket_ptr sock(new tcp::socket(service));
			acceptor.accept(*sock);
			boost::thread t(boost::bind(MainFuncTread, sock));
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

string SingWithNick(socket_ptr sock)
{
	while (1)
	{
		boost::asio::streambuf boost_stream;
		std::ostream stream(&boost_stream);
		read(*sock, boost_stream, boost::asio::transfer_at_least(1));
		boost::asio::streambuf::const_buffers_type indata = boost_stream.data();
		std::string _nick(boost::asio::buffers_begin(indata), boost::asio::buffers_end(indata));
		stream.clear();
		boost_stream.consume(boost_stream.size());
		if (!FoundNick(_nick))
		{
			stream << "connect";
			write(*sock, boost_stream, boost::asio::transfer_at_least(1));
			return _nick;
		}
		else
		{
			stream << "error1";
			write(*sock, boost_stream, boost::asio::transfer_at_least(1));
		}
	}
}

void MainFuncTread(socket_ptr sock)
{
	try
	{
		string nick = SingWithNick(sock);
		auto QueueMSG = shared_ptr<queue<string>>(new queue<string>);	
		lock_map.lock();
		MsgQueueMap.insert(make_pair(nick, QueueMSG));
		cout << "connected users:" << MsgQueueMap.size() << std::endl;
		Logger::Instance().AddStr(to_simple_string(boost::posix_time::second_clock::local_time()) + ":" + "connected users :" + to_string(MsgQueueMap.size()));
		lock_map.unlock();
		string data = "The user '" + nick + "' has been connected." + "\n";
		json  msg = { {"type","1"},{"from","server"} ,{"to","all"} ,{"text", data} };
		Logger::Instance().AddStr(to_simple_string(boost::posix_time::second_clock::local_time()) + ":" + data);
		MyRoom.AddInRoom(msg);
		boost::asio::streambuf boost_stream;
		while (1)
		{
			lock_Queue.lock();
			if (!QueueMSG->empty())
			{
				boost_stream.consume(boost_stream.size());
				std::ostream stream(&boost_stream);
				stream << QueueMSG->front() << endl;
				stream.clear();
				write(*sock, boost_stream, boost::asio::transfer_at_least(1));
				QueueMSG->pop();
			}
			lock_Queue.unlock();
			if (sock->available() != 0)
			{
				boost_stream.consume(boost_stream.size());
				read(*sock, boost_stream, boost::asio::transfer_at_least(1));
				boost::asio::streambuf::const_buffers_type indata = boost_stream.data();
				std::string data(boost::asio::buffers_begin(indata), boost::asio::buffers_end(indata));
				if (data[0] == '-')
				{
					boost_stream.consume(boost_stream.size());
					std::ostream stream(&boost_stream);
					bool exit = 0;
					string str = DoingCommand(data, nick, exit);
					stream << str;
					Logger::Instance().AddStr(to_simple_string(boost::posix_time::second_clock::local_time()) + ":" + "Has been entered command " + data + " by " + "'" + nick + "'");
					write(*sock, boost_stream, boost::asio::transfer_at_least(1));
					stream.clear();
					if (exit)
					{
						cout << "user " << nick << " disconeted" << endl;
						cout << "connected users: " << MsgQueueMap.size();
						break;
					}
				}
				else
				{
					json  msg = { {"type","2"},{"from",nick} ,{"to","all"} ,{"text", data + "\n"} };
					MyRoom.AddInRoom(msg);
				}
			}
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
