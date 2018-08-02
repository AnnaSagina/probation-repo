#include "Handler.h"
#include <cmath>

using namespace std;

Handler::Handler(bitset<4> _config)
{
	config = _config;
}

void Handler::Set_config(bitset<4> _config)
{
	config = _config;
}

bitset<4> Handler::Get_config()
{
	return config;	
}

double Handler::Calculate_square(Rectangle _rectangle)
{
	return (_rectangle.Get_height() * _rectangle.Get_width());
}

double Handler::Calculate_perimetr(Rectangle _rectangle)
{
	return 2*(_rectangle.Get_height() + _rectangle.Get_width());	
}

Rectangle Handler::Reduce_by_two(Rectangle _rectangle)
{
	_rectangle.Set_height(_rectangle.Get_height() / sqrt(2.0));
	_rectangle.Set_width(_rectangle.Get_width() / sqrt(2.0));
	return _rectangle;
}

Rectangle Handler::Increase_by_two(Rectangle _rectangle)
{
	_rectangle.Set_height(_rectangle.Get_height() * sqrt(2.0));
	_rectangle.Set_width(_rectangle.Get_width() * sqrt(2.0));
	return _rectangle;
}

Rectangle Handler::Stretch_rectangle_to_square(Rectangle _rectangle)
{
	if (_rectangle.Get_height() > _rectangle.Get_width())
		_rectangle.Set_width(_rectangle.Get_height());
	else
		_rectangle.Set_height(_rectangle.Get_width());
	return _rectangle;
}

Rectangle Handler::Squeeze_rectangle_to_square(Rectangle _rectangle)
{
	if (_rectangle.Get_height() < _rectangle.Get_width())
			_rectangle.Set_width(_rectangle.Get_height());
	else
			_rectangle.Set_height(_rectangle.Get_width());
	return _rectangle;
}

double Handler::Calculate_radius_inscribed_circle(Rectangle _rectangle)
{
	if (_rectangle.Get_width() != _rectangle.Get_height())
	{
		return -1;
	}
	else
		return _rectangle.Get_height() / 2;

}

double Handler::Calculate_radius_described_circle(Rectangle _rectangle)
{
	double diagonal = sqrt((double)(pow(_rectangle.Get_height(),2)+pow(_rectangle.Get_width(),2)));
	return diagonal/2;
}

 struct_for_Handler Handler::main_func_of_handler(Rectangle rectangle)
{
	struct_for_Handler my_handler;

	if (config[3] == 1)
		my_handler.Perimetr_or_square = Calculate_square(rectangle);
	else
		my_handler.Perimetr_or_square =  Calculate_perimetr(rectangle);

	if (config[2] == 1)
	{
		my_handler.Square = Stretch_rectangle_to_square(rectangle);
	}
	else
	{
		my_handler.Square = Squeeze_rectangle_to_square(rectangle);		
	}
	if (config[1] == 1)
	{
		my_handler.ResizeRec = Increase_by_two(rectangle);
	}
	else
	{
		my_handler.ResizeRec = Reduce_by_two(rectangle);
	}

	if (config[0] == 1)
	{
		my_handler.radius = Calculate_radius_inscribed_circle(rectangle);
	}
	else
	{	
		my_handler.radius = Calculate_radius_described_circle(rectangle);
	}
	return my_handler;
 }

 void Handler::printstruct(map<string,struct_for_Handler> MapForHandler, string str_st)
 {
	auto i = MapForHandler.find(str_st);
	cout << "Perimetr or Square: ";
	cout << (*i).second.Perimetr_or_square << endl;
	cout << "Square:" << endl;
	(*i).second.Square.Print_rectangle();
	cout << "Resize:" << endl;
	(*i).second.ResizeRec.Print_rectangle();
	cout << "Radius: ";
	cout << (*i).second.radius << endl;
 }