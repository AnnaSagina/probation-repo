#include <iostream>
#include <fstream>

#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__
using namespace std;

class rectangle
{
private:
	int width;
	int height;
public:
	rectangle(int a, int b)
	{
		width = a;
		height = b;
	}
	rectangle(const rectangle &object)
	{
		height = object.height;
		width = object.width;
	}
	int Get_width()
	{
		return width;
	}
	int Get_height()
	{
		return height;
	}
	void Set_width(int a)
	{
		width = a;
	}
	void Set_height(int b)
	{
		height = b;
	}

};
#endif

