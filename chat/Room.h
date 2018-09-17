#ifndef ROOM_H
#define ROOM_H
#include <cstdlib>
#include <iostream>
#include <vector>
#include<list>
#include<map>
#include<queue>
#include<ctime>
#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include "json.hpp"

using boost::asio::ip::tcp;
using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;
using json = nlohmann::json;

map<std::string, shared_ptr<queue<string>>> MessegeQueueMap;
std::mutex _lock;
class Room
{
private:
	std::vector<json>  room;
public:
	Room(){}
	void SendSomebody(json j_mes)
	{
		(MessegeQueueMap.find(j_mes["whom"])->second)->push(j_mes.dump());
	}
	void SendUpdate()
	{
		for (auto it = MessegeQueueMap.begin(); it != MessegeQueueMap.end(); ++it)
		{
			(it->second)->push(ReturnLast());
		}
	}
	void AddInRoom(json j_mes)
	{
		_lock.lock();
		if (j_mes["whom"] == "all")
		{		
			room.push_back(j_mes);
			SendUpdate();
		}
		_lock.unlock();
	}
	void Clear()
	{
		room.clear();
	}
	std::string ReturnLast()
	{
		return room.back().dump();
	}
	std::string ReturnHistory()
	{
		std::string TenMES = "";
		if (room.size() < 10)
			for (int i = 0; i < room.size(); i++)
			{
				TenMES += room[i].at("nick").get<string>() + + ":" + room[i].at("text").get<string>();
			}
		else
			for (int i = 0; i < 10; i++)
			{
				int j = room.size() - 10 + i;
				TenMES += room[j].at("nick").get<string>() + +":" + room[j].at("text").get<string>();
			}
		return TenMES;
	}
};
#endif


