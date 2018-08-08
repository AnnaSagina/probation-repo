#include "Rectangle.h"


using namespace std;

class Handler
{
public:
	void MainFuncHandler(Rectangle my_rectangle)
	{
		cout << "Resize :" <<endl;
		this->Resize_in_2(my_rectangle).Print_rectangle();
		cout << "Square :" <<endl;
		this->Make_a_square(my_rectangle).Print_rectangle();
		cout << "Radius : " ;
		cout << this->Circle_radius(my_rectangle)<< endl;;	
	}

	virtual Rectangle Resize_in_2(Rectangle my_rectangle) = 0;
	virtual Rectangle Make_a_square(Rectangle my_rectangle) = 0;
	virtual double Circle_radius(Rectangle my_rectangle) = 0;

};

class HandlerSmall:public Handler
{
public:
	Rectangle Resize_in_2(Rectangle my_rectangle)
	{ 
		my_rectangle.Set_height(my_rectangle.Get_height() / sqrt(2.0));
		my_rectangle.Set_width(my_rectangle.Get_width() / sqrt(2.0));	
		return my_rectangle;
	};

	Rectangle Make_a_square(Rectangle my_rectangle)
	{
		if (my_rectangle.Get_height() < my_rectangle.Get_width())
			my_rectangle.Set_width(my_rectangle.Get_height());
		else
			my_rectangle.Set_height(my_rectangle.Get_width());
		return my_rectangle;
	}

	double Circle_radius(Rectangle my_rectangle)
	{
	
		if (my_rectangle.Get_width() == my_rectangle.Get_height())
			return (my_rectangle.Get_height() / 2);
		else	
		{
			cout << "Indefined for this figure" <<  endl;
			return -1;
		}
	}
	
};

class HandlerBig:public Handler
{
public:
	Rectangle Resize_in_2(Rectangle my_rectangle)
	{ 
		my_rectangle.Set_height(my_rectangle.Get_height() * sqrt(2.0));
		my_rectangle.Set_width(my_rectangle.Get_width() * sqrt(2.0));
		return my_rectangle;
	};

	Rectangle Make_a_square(Rectangle my_rectangle)
	{
		if (my_rectangle.Get_height() > my_rectangle.Get_width())
			my_rectangle.Set_width(my_rectangle.Get_height());
		else
			my_rectangle.Set_height(my_rectangle.Get_width());	
		return my_rectangle;
	}

	double Circle_radius(Rectangle my_rectangle)
	{
		double diagonal = sqrt((double)(pow(my_rectangle.Get_height(),2) + pow(my_rectangle.Get_width(),2)));
		return (diagonal/2);

	}

};