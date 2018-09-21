#ifndef LOGGER_H
#define LOGGER_H

#include <cstdlib>
#include <iostream>
#include <fstream>

std::mutex _lock1;

class Logger
{
private:
	std::string AllRec;
	Logger() { }
	~Logger() { }
	Logger(Logger const&);
	Logger& operator= (Logger const&);
public:
	static Logger& Instance()
	{
		static Logger s;
		return s;
	}
	void AddStr(std::string rec)
	{
		_lock1.lock();
		AllRec += rec + "\n";
		_lock1.unlock();
	}
	void AddAllRec()
	{
		while (1)
		{
			Sleep(5000);
			if (AllRec != "")
			{
				
				std::ofstream out("C:/Users/amalova/Documents/Visual Studio 2010/Projects/MyServer/log/logger.txt", std::ios::app);
				if (out.is_open())
				{
					_lock1.lock();
					out << AllRec;
					AllRec = "";
					_lock1.unlock();
				}
				out.close();
			}
		}
	}
};
#endif