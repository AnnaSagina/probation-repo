#include <iostream>
#include <fstream>
#include "rectangle.h"

#ifndef __INPUT_METOD_H__
#define __INPUT_METOD_H__

char messege_about_remaing_data[38] = "Please enter remaining data ";
char incorr_data_messege[20] = "incorrect data";
bool a_recording = 0;
bool b_recording = 0;
bool ps_recording = 0;
bool correct_input_flag = true;

void Process_incorect_input(bool &correct_input_) // обработка плохого ввода
{
	cout << incorr_data_messege <<", enter numerics"<<endl;
	correct_input_ = false;
	cin.clear();
	while(cin.get() != '\n');
}

bool Is_bad_enter(bool &correct_input_) //наличие плохого ввода
{
	if (!cin.good())
	{
		Process_incorect_input(correct_input_);
		return 1;
	}
	return 0;
}

int Calculation_square(char *_select_parametr,rectangle &my_rectangle)//вычисление площади
{
	return (my_rectangle.height *my_rectangle.width);			
}

int Calculation_perimetr(char *select_parametr,rectangle &my_rectangle)//вычисление периметра
{
	return 2*(my_rectangle.height + my_rectangle.width);	
}

void —omputation_output(char *select_parametr,rectangle &my_rectangle)//вывод посчитанных величин
{
	if (strcmp(select_parametr,"-s") == 0)
		cout <<"Square = "<< Calculation_square(select_parametr,my_rectangle) << endl;
	else 
		if  (strcmp(select_parametr,"-p") == 0)
				cout <<"Perimetr = "<< Calculation_perimetr(select_parametr,my_rectangle) << endl;
		else 
			if (strcmp(select_parametr,"-ps") == 0)
			{
				cout <<"Square = "<< Calculation_square(select_parametr,my_rectangle) << endl;
				cout <<"Perimetr = "<< Calculation_perimetr(select_parametr,my_rectangle) << endl;
			}
			else
			{
				cout <<incorr_data_messege << endl; // по сути это тоже плохой ввод, но отличаетс€ от ввода а и б
			}
}

bool Is_not_repeat_flag_cmd(char *str_flag)
{
	if ((strcmp(str_flag,"-a") == 0)&&(a_recording == 1))
		return 0;
	if ((strcmp(str_flag,"-b") == 0)&&(b_recording == 1))
		return 0;
	if (((strcmp(str_flag,"-s") == 0)||(strcmp(str_flag,"-p") == 0)||(strcmp(str_flag,"-ps") == 0))&&(ps_recording == 1))
		return 0;
	return 1;
}

bool Is_correct_flag_cmd(char *str_flag)
{
	if (((strcmp(str_flag,"-a") == 0)||(strcmp(str_flag,"-b") == 0)||(strcmp(str_flag,"-p") == 0)||(strcmp(str_flag,"-s") == 0)||(strcmp(str_flag,"-ps")== 0))&&(Is_not_repeat_flag_cmd(str_flag)))
		return 1;
	return 0;
}

bool Data_recording_cmd(int argc,char **argv, int &i,rectangle &my_rectangle,char *select_parametr)//запись с командной строки, не придумала как красиво поделить эти функциии(
{
	if ((argv[i][0]=='-')&&(Is_correct_flag_cmd(argv[i])))
	{
		if ((strcmp(argv[i],"-a") == 0)&&(i+1<argc))
		{
			if (atoi(argv[i+1]) == 0)
				return 0;//провер€ю что за флагом идет число , как по другому не знаю, потому что атой возвращает ноль если это буква
			my_rectangle.width = atoi(argv[i+1]);
			i++; 
			a_recording = 1;
		}
		if ((strcmp(argv[i],"-b") == 0)&&(i+1<argc))
		{
			if (atoi(argv[i+1]) == 0)
				return 0;//провер€ю что за флагом идет число
			my_rectangle.height = atoi(argv[i+1]); 
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

void Input_remaing_data_and_recording(char *select_parametr,rectangle &my_rectangle)//ввод данных оставшихс€, после командной строки
{
	if (a_recording == 0)
	{
		cout << "width a "<< endl;
		cin >> my_rectangle.width;
		if (Is_bad_enter(correct_input_flag))//проверили что число
			return ;
	}
	if (b_recording == 0)
	{
		cout << "height b"<< endl;
		cin >>  my_rectangle.height;;
		if (Is_bad_enter(correct_input_flag))//проверили что число
			return ;
	}
	if (ps_recording == 0)
	{
		cout << "-p/-s/-ps (square/perimetr/both)"<< endl;
		cin >> select_parametr;	
	}
}

void Data_recording(int argc,char **argv,char *select_parametr,rectangle &my_rectangle)//запись данных
{
	for (int i = 1;i <= 5; i++)
	{
		if (argc >= (i+1))//запись с командной строки
		{
			if (Data_recording_cmd(argc,argv,i,my_rectangle,select_parametr) == 0)
				{
					correct_input_flag = false;	
					cout << incorr_data_messege << endl;
					return;
				}
		}
		else
		{
			cout << messege_about_remaing_data << endl;
			Input_remaing_data_and_recording(select_parametr,my_rectangle);//ввод оставшихс€ данных с клавиатуры+запись
			break;
		}
	}
	correct_input_flag = true;	
};
#endif

