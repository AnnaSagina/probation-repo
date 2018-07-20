#include <iostream>
#include <fstream>
#include "Input_Metod.h"
#include "rectangle.h"

using namespace std;

void main(int argc,char **argv)
{
	int continuation_check = 1;//1 - continue , 2 - exid
	char *select_parametr = new char[11]; // Square,Perimetr,Both
	int a = 0,b = 0;
	rectangle my_rectangle(a,b);
	while(continuation_check == 1)
	{
		Data_recording(argc,argv,select_parametr,my_rectangle);
		
		if (correct_input_flag)
		{
			Ñomputation_output(select_parametr,my_rectangle);
		}		
		
		argc = 1;
		cout <<"1.continue"<<endl;
		cout <<"2.exit"<<endl;
		a_recording = 0;
		b_recording = 0;
		ps_recording = 0;
		cin >> continuation_check;
	
	}
}