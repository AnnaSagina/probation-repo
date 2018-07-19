#include <iostream>
#include <fstream>

#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__
using namespace std;

class rectangle
{
public:
	int width;
	int height;
	rectangle(int a, int b)
	{
		width = a;
		height = b;
	};
	rectangle(const rectangle &object)
	{
		height = object.height;
		width = object.width;
	};
};
#endif

