#include <iostream>
#include <fstream>
#include "rectangle.h"

#ifndef __INPUT_METOD_H__
#define __INPUT_METOD_H__

char messege_about_remaing_data[38] = "Please enter remaining data ";
char incorr_data_messege[20] = "incorrect data";

void Process_incorect_input(bool &correct_input_) // ��������� ������� �����
{
	cout << incorr_data_messege <<", enter numerics"<<endl;
	correct_input_ = false;
	cin.clear();
	while(cin.get() != '\n');
}

bool Is_bad_enter(bool &correct_input_) //������� ������� �����
{
	if (!cin.good())
	{
		Process_incorect_input(correct_input_);
		return 1;
	}
	return 0;
}

int Calculation_square(char *_select_parametr,rectangle &my_rectangle)//���������� �������
{
	return (my_rectangle.height *my_rectangle.width);			
}

int Calculation_perimetr(char *select_parametr,rectangle &my_rectangle)//���������� ���������
{
	return 2*(my_rectangle.height + my_rectangle.width);	
}

void �omputation_output(char *select_parametr,rectangle &my_rectangle)//����� ����������� �������
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
				cout <<incorr_data_messege << endl; // �� ���� ��� ���� ������ ����, �� ���������� �� ����� � � �
			}
}

bool Data_recording_cmd(char **argv, int &i,rectangle &my_rectangle,char *select_parametr)//������ � ��������� ������, �� ��������� ��� ������� �������� ��� ��������(
{
	bool error = 1;// �������� ������������ �����
	if ((argv[i][0]=='-'))
	{
		if (strcmp(argv[i],"-a") == 0)
		{
			if (atoi(argv[i+1]) == 0)
				return 0;//�������� ��� �� ������ ���� ����� , ��� �� ������� �� ����, ������ ��� ���� ���������� ���� ���� ��� �����
			my_rectangle.width = atoi(argv[i+1]);
			i++; 
			error = 0;
		}
		if (strcmp(argv[i],"-b") == 0)
		{
			if (atoi(argv[i+1]) == 0)
				return 0;//�������� ��� �� ������ ���� �����
			my_rectangle.height = atoi(argv[i+1]); i++;
			error = 0;
		}
		if ((strcmp( argv[i],"-p")== 0)||(strcmp(argv[i],"-s") == 0)||(strcmp(argv[i],"-ps") == 0))
		{
			strcpy(select_parametr,argv[i]);
			error = 0;
		}

	}
		if (error == 1)
			return 0;
		else 
			return 1;
}

void Input_remaing_data_and_recording(int argc,char *select_parametr,bool &correct_input_flag, rectangle &my_rectangle)//���� ������ ����������, ����� ��������� ������
{
	if (argc == 1)
	{
		cout << "width a "<< endl;
		cin >> my_rectangle.width;
		if (Is_bad_enter(correct_input_flag))//��������� ��� �����
			return ;
	}
		if ((argc == 1)||(argc == 3))
		{
			cout << "height b"<< endl;
			cin >>  my_rectangle.height;;
					if (Is_bad_enter(correct_input_flag))//��������� ��� �����
				return ;
		}
		if (argc != 6)
		{
			cout << "-p/-s/-ps (square/perimetr/both)"<< endl;
			cin >> select_parametr;	
		}
}

void Data_recording(int argc,char **argv,char *select_parametr,rectangle &my_rectangle,bool & correct_input_flag)//������ ������
{
	for (int i = 1;i <= 5; i++)
	{
		if (argc >= (i+1))//������ � ��������� ������
		{
			if(Data_recording_cmd(argv,i,my_rectangle,select_parametr) == 0)
				{
					correct_input_flag = false;	
					cout << incorr_data_messege << endl;
					return;
				}
		}
		else
		{
			cout << messege_about_remaing_data << endl;
			Input_remaing_data_and_recording(argc,select_parametr,correct_input_flag,my_rectangle);//���� ���������� ������ � ����������+������
			break;
		}
	}
	correct_input_flag = true;	
};
#endif

