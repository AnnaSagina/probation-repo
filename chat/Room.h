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

map<std::string, shared_ptr<queue<string>>> MsgQueueMap;

class Room
{
private:
	std::vector<json>  room;
	std::mutex _lock;
public:
	Room(){}
	void SendSomebody(json j_mes)
	{
		_lock.lock();
		MsgQueueMap.find(j_mes["to"])->second->push(j_mes.dump());
		_lock.unlock();
	}
	void SendUpdate()
	{
		_lock.lock();
		for (auto i : MsgQueueMap)
		{
			(i.second)->push(ReturnLast());
		}
		_lock.unlock();
	}
	void AddInRoom(json j_mes)
	{
		if (j_mes["to"] == "all")
		{
			room.push_back(j_mes);
			SendUpdate();
		}
	}
	std::string ReturnLast()
	{
		return room.back().dump();
	}
	std::string ReturnTenMes()
	{
		std::string TenMES = "";
		_lock.lock();
		if (room.size() < 10)
			for (int i = 0; i < room.size(); i++)
			{
				TenMES += room[i].at("from").get<string>() + + ":" + room[i].at("text").get<string>();
			}
		else
			for (int i = 0; i < 10; i++)
			{
				int j = room.size() - 10 + i;
				TenMES += room[j].at("from").get<string>() + +":" + room[j].at("text").get<string>();
			}
		_lock.unlock();
		return TenMES;
	}
};
#endif


