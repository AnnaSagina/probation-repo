#include "Handler.h"
#include <cmath>

using namespace std;

Handler::Handler(Rectangle object,bitset<4> _config)
{
	rectangle = object ;
	config = _config;
}

void Handler::Set_config(bitset<4> _config)
{
	config = _config;
}

void Handler::Set_data(Rectangle _rectangle)
{
	rectangle = _rectangle;
}

Rectangle Handler::Get_data()
{
	return rectangle;
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
	double diagonal = sqrt((double)(_rectangle.Get_height()*_rectangle.Get_width()));
	return diagonal/2;
}

void Handler::main_func_of_handler()
{
	if (config[3] == 1)
		cout << "Square = " << Calculate_square(this->Get_data()) << endl;
	else
		cout << "Perimetr = " << Calculate_perimetr(this->Get_data()) << endl;

	cout << endl;
	if (config[2] == 1)
	{
		cout << "New rectangle stretched to square:" << endl;
		Stretch_rectangle_to_square(this->Get_data()).Print_rectangle();
	}
	else
	{
		cout << "New rectangle squeezed to square:" << endl;
		Squeeze_rectangle_to_square(this->Get_data()).Print_rectangle();
	}

	cout << endl;
	if (config[1] == 1)
	{
		cout << "New rectangle increased by two:" << endl;
		Increase_by_two(this->Get_data()).Print_rectangle();
	}
	else
	{
		cout << "New rectangle reduced by two:" << endl;
		Reduce_by_two(this->Get_data()).Print_rectangle();
	}
	cout << endl;

	if (config[0] == 1)
	{
		if (Calculate_radius_inscribed_circle(this->Get_data()) == -1)
			cout << "Radius inscribed circle indefined for this figure" << endl;
		else
		cout << "Radius inscribed circle = " << Calculate_radius_inscribed_circle(this->Get_data()) << endl;
	}
	else
	{	
		cout <<"Radius described circle = " <<  Calculate_radius_described_circle(this->Get_data()) << endl;
	}
}