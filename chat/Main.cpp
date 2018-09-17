#include<ctime>
#include <boost/thread/thread.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "Room.h"
#include "Logger.h"
#include "TreadForClient.h"
typedef boost::shared_ptr<tcp::socket> socket_ptr;
int countclients = 0;
boost::asio::io_service service;
tcp::acceptor acceptor(service, tcp::endpoint(tcp::v4(), 1234));
void MainFuncTread(socket_ptr sock);

Room MyRoom;
Logger& Log = Logger::Instance("");

string DoingCommand(string data,string _nick,bool &exit)
{
	string command;
	json mes;
	mes["type"] = "1";
	mes["nick"] = "server"; 
	mes["whom"] = _nick;
	int i = 0;
	while ((data.size() - 1 >= i) && (data[i] != ' '))
	{
		command += data[i];
		i++;
	}
	if (command == "-history")
	{
		mes["text"] = "Last 10 messenge: \n" + MyRoom.ReturnHistory();
		return (mes.dump());
	}

	if (command == "-users")
	{
		string str = "connected user :" + to_string(countclients) + "\n";
		for (auto it = MessegeQueueMap.begin(); it != MessegeQueueMap.end(); ++it)
		{
			str += (it->first) + "\n";
		}
		mes["text"] = str;
		return mes.dump();
	}

	if (command == "-ls")
	{
		if (data.size() < 10 )
		{
			mes["text"] = "Bad command";
			return mes.dump();
		}
		mes["type"] = "3";
		mes["nick"] = _nick;
		string str = "";
		while (data[i + 1] != ' ')
		{
			str += data[i + 1];
			i++;
		}
		mes["whom"] = str;
		str = "";
		while (data[i + 1] != '\0')
		{
			str += data[i + 1];
			i++;
		}
		mes["text"] = str + "\n";
		if (mes["whom"] != mes["nick"])
		{
			MyRoom.SendSomebody(mes);
		}
		mes["text"] = " / to " + mes.at("whom").get<string>() + " / " + mes.at("text").get<string>();
		return mes.dump();
	}

	if (command == "-exit")
	{
		exit = 1;
		_lock.lock();
		countclients--;
		MessegeQueueMap.erase(_nick);
		_lock.unlock();
		mes["text"] = "Disconnected";
		return mes.dump();	
	}
	mes["text"] = "Bad command \n";
		return mes.dump();
}

bool FoundNick(string _nick)
{
	for (auto it = MessegeQueueMap.begin(); it != MessegeQueueMap.end(); ++it)
	{
		if ((it->first) == _nick)
			return 1;	
	}
	return 0;
}

int main()
{
	boost::thread th(boost::bind(&Logger::AddAllRec ,boost::ref(Log)));
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
			_lock.lock();
			countclients++;
			_lock.unlock();
			cout << "connected users:" << countclients << std::endl;
			Log.Instance(to_simple_string(boost::posix_time::second_clock::local_time()) + ":" + "connected users :" + to_string(countclients));
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
		auto QueueMES = shared_ptr<queue<string>>(new queue<string>);
		MessegeQueueMap.insert(make_pair(nick, QueueMES));
		string data = "The user '" + nick + "' has been connected." + "\n" ;
		json  mes = { {"type","1"},{"nick","server"} ,{"whom","all"} ,{"text", data} };
		Log.Instance(to_simple_string(boost::posix_time::second_clock::local_time()) + ":" + data);
		MyRoom.AddInRoom(mes);	
		boost::asio::streambuf boost_stream;
		while (1)
		{
			if(!QueueMES->empty())
			{
				boost_stream.consume(boost_stream.size());
				std::ostream stream(&boost_stream);			
				stream << QueueMES->front() << endl;
				stream.clear();
				write(*sock, boost_stream, boost::asio::transfer_at_least(1));
				QueueMES->pop();
			}
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
					string str = DoingCommand(data,nick,exit);
					stream << str;
					Log.Instance(to_simple_string(boost::posix_time::second_clock::local_time()) + ":" + "Has been entered command " + data + " by " + "'"+nick+"'");
					write(*sock, boost_stream, boost::asio::transfer_at_least(1));
					stream.clear();
					if (exit)
					{
						cout << "user " << nick << " disconeted" << endl;
						cout << "connected users: " << countclients;
						break;
					}			
				}
				else
				{
					json  mes = { {"type","2"},{"nick",nick} ,{"whom","all"} ,{"text", data + "\n"}};
					MyRoom.AddInRoom(mes);
				}
			}
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
