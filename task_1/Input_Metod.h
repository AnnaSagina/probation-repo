#include <iostream>
#include <fstream>
#include "rectangle.h"

#ifndef __INPUT_METOD_H__
#define __INPUT_METOD_H__

const char MESSEGE_ABOUT_RAMAINING_DATA[38] = "Please enter remaining data ";
const char INCORR_DATA_MESSEGE[20] = "incorrect data";

bool a_recording = 0; //if data recorded , value 1
bool b_recording = 0;
bool ps_recording = 0;

int width_a, height_b; // auxiliary variables for keyboard reading

void Process_incorect_input() //bad input handling
{
	cout << INCORR_DATA_MESSEGE <<", enter numerics"<<endl;
	cin.clear();
	while(cin.get() != '\n');
}
bool Is_bad_enter() //presence of bad input
{
	if (!cin.good())
	{
		Process_incorect_input();
		return 1;
	}
	return 0;
}
int Calculation_square(char *_select_parametr,rectangle &my_rectangle)
{
	return (my_rectangle.Get_height() * my_rectangle.Get_width());			
}
int Calculation_perimetr(char *select_parametr,rectangle &my_rectangle)//вычисление периметра
{
	return 2*(my_rectangle.Get_height() + my_rectangle.Get_width());	
}
bool Is_not_repeated_flag_cmd(char *str_flag)//check for flag repeat
{
	if ((strcmp(str_flag,"-a") == 0)&&(a_recording == 1))
		return 0;
	if ((strcmp(str_flag,"-b") == 0)&&(b_recording == 1))
		return 0;
	if (((strcmp(str_flag,"-s") == 0)||(strcmp(str_flag,"-p") == 0)||(strcmp(str_flag,"-ps") == 0))&&(ps_recording == 1))
		return 0;
	return 1;
}
bool Is_correct_flag_cmd(char *str_flag)//check of correctness of a flag
{
	if (((strcmp(str_flag,"-a") == 0)||(strcmp(str_flag,"-b") == 0)||(strcmp(str_flag,"-p") == 0)||(strcmp(str_flag,"-s") == 0)||(strcmp(str_flag,"-ps")== 0))&&(Is_not_repeated_flag_cmd(str_flag)))
		return 1;
	return 0;
}
bool Data_recording_cmd(int argc,char **argv, int &i,rectangle &my_rectangle,char *select_parametr)//entry from cmd, I dont know how to split into functions
{
	if ((argv[i][0]=='-')&&(Is_correct_flag_cmd(argv[i])))
	{
		if ((strcmp(argv[i],"-a") == 0)&&(i+1<argc))
		{
			if (atoi(argv[i+1]) == 0)
				return 0;//check that after flag - numerical
			my_rectangle.Set_width(atoi(argv[i+1]));
			i++; 
			a_recording = 1;
		}
		if ((strcmp(argv[i],"-b") == 0)&&(i+1<argc))
		{
			if (atoi(argv[i+1]) == 0)
				return 0;//check that after flag - numerical
			my_rectangle.Set_height(atoi(argv[i+1])); 
			i++;
			b_recording = 1;
		}
		if ((strcmp(argv[i],"-p")== 0)||(strcmp(argv[i],"-s") == 0)||(strcmp(argv[i],"-ps") == 0))
		{
			strcpy(select_parametr,argv[i]);
			ps_recording = 1;
		}
		return 1;
	}
	else
		return 0;		
}
bool Input_remaing_data_and_recording(char *select_parametr,rectangle &my_rectangle)//Input remaing data, after input from cmd
{
	if (a_recording == 0)
	{
		cout << "width a "<< endl;
		cin >> width_a;
		my_rectangle.Set_width(width_a);
		if (Is_bad_enter())//check input
			return 0;
	}
	if (b_recording == 0)
	{
		cout << "height b"<< endl;
		cin >>  height_b;
		my_rectangle.Set_height(height_b);
		if (Is_bad_enter())//check input
			return 0;
	}
	if (ps_recording == 0)
	{
		cout << "-p/-s/-ps (square/perimetr/both)"<< endl;
		cin >> select_parametr;	
	}
	return 1;
}
bool Data_recording(int argc,char **argv,char *select_parametr,rectangle &my_rectangle)//recording the data
{
	for (int i = 1;i <= 5; i++)
	{
		if (argc >= (i+1))
		{
			if (Data_recording_cmd(argc,argv,i,my_rectangle,select_parametr) == 0)
				{
					cout << INCORR_DATA_MESSEGE << endl;
					return 0;
				}
		}
		else
		{
			cout << MESSEGE_ABOUT_RAMAINING_DATA << endl;
 			if (Input_remaing_data_and_recording(select_parametr,my_rectangle))
				break;
			else
				return 0;
		}
	}
	return 1;	
};
#endif

