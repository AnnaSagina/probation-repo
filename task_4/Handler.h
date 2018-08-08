#include "Rectangle.h"
#include <bitset>
#include "StructforHandler.h"
#include <map>  
using namespace std;
#ifndef __HANDLER_H__
#define __HANDLER_H__

class Handler
{
private:
	bitset<4> config;

	double Calculate_square(Rectangle _rectangle);//1

	double Calculate_perimetr(Rectangle _rectangle);//0

	Rectangle Squeeze_rectangle_to_square(Rectangle _rectangle);//0

	Rectangle Stretch_rectangle_to_square(Rectangle _rectangle);//1

	Rectangle Increase_by_two(Rectangle _rectangle);//1

	Rectangle Reduce_by_two(Rectangle _rectangle);//0

	double Calculate_radius_inscribed_circle(Rectangle _rectangle);//1

	double Calculate_radius_described_circle(Rectangle _rectangle);//0

public:
	Handler(bitset<4> _config);

	void Set_config(bitset<4> _config);

	bitset<4> Get_config();

	struct_for_Handler main_func_of_handler(Rectangle rectangle);
};

#endif