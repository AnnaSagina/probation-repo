#ifndef LOGGER_H
#define LOGGER_H

#include <cstdlib>
#include <iostream>
#include <fstream>

std::mutex _lock1;

class Logger
{
private:
	std::string AllRec = "";
	Logger() { }
	~Logger() { }
	Logger(Logger const&);

public:
	static Logger& Instance(std::string rec)
	{
		static Logger s;
		s.AllRec += rec + "\n";
		return s;
	}
	void ClearRec()
	{
		AllRec = "";
	}
	std::string GetAllRec()
	{
		return AllRec;
	}
	void AddAllRec()
	{
		
		while (1)
		{
			if (GetAllRec() != "")
			{
				_lock1.lock();
				std::ofstream out("C:/Users/amalova/Documents/Visual Studio 2010/Projects/MyServer/log/logger.txt", std::ios::app);
				if (out.is_open())
				{
					out << GetAllRec();
					ClearRec();
				}
				out.close();
				_lock1.unlock();
			}
		}
	}
};
#endif