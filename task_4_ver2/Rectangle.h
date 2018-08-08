#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <bitset>
 

using namespace std;
#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

class Rectangle
{
private:
	double height ;
	double width ;
public:
	Rectangle(double a = 0, double b = 0)
	{
		height = a;
		width = b;
	}
	Rectangle(Rectangle &object)
	{
		height = object.height;
		width = object.width;
	}
	double Get_height()
	{
		return height;
	}
	double Get_width()
	{
		return width;
	}
	void Set_height(double a)
	{
		height = a;
	}
	void Set_width(double b)
	{
		width = b;
	}
	void Print_rectangle()
	{
		cout << " Height a = " << this->Get_height()<< endl;
		cout << " Width b = " << this->Get_width() << endl;
	}
};
#endif