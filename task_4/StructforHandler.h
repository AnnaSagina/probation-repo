#include "Rectangle.h"

#ifndef __STRACT_FOR_HANDLER_H__
#define __STRACT_FOR_HANDLER_H__

struct struct_for_Handler   
{                  
    Rectangle ResizeRec;       
    Rectangle Square;        
	double Perimetr_or_square;   
    double radius;   

	void print()
	{
		cout << "Resize :" << endl;
		ResizeRec.Print_rectangle();
		cout << "Square :" << endl;
		Square.Print_rectangle(); 
		cout << "Perimetr_or_square:" << Perimetr_or_square << endl;
		cout << "Radius :" << radius << endl; 	
	}
}; 

#endif