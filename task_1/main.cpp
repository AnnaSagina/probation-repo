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
		if (Data_recording(argc,argv,select_parametr,my_rectangle))
		{
				if (strcmp(select_parametr,"-s") == 0)
					cout <<"Square = "<< Calculate_square(my_rectangle) << endl;
				else if  (strcmp(select_parametr,"-p") == 0)
					cout <<"Perimetr = "<< Calculate_perimetr(my_rectangle) << endl;
				else if (strcmp(select_parametr,"-ps") == 0)
				{
					cout <<"Square = "<< Calculate_square(my_rectangle) << endl;
					cout <<"Perimetr = "<< Calculate_perimetr(my_rectangle) << endl;
				}
				else
					cout <<INCORR_DATA_MESSEGE<< endl; // по сути это тоже плохой ввод, но отличается от ввода а и б
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