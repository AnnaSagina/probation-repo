#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

char* MESSEGE_BAD_ENTER = "Error: Bad enter";
char* BINARY_FORM = "Binary form :";
char* ANSWER = "Answer: ";

void Process_incorect_input() //bad input handling
{
	cout << "Enter numerics!!!!"<<endl;
	cin.clear();
	while(cin.get() != '\n');
}

bool Is_good_enter() //presence of bad input
{
	if (cin.good())
	{
		return 1;
	}
	Process_incorect_input();
	return 0;
}

bool Is_good_enter(int _choose_value)
{
	
	if ((!Is_good_enter())||((_choose_value!=3)&&(_choose_value!=2)&&(_choose_value!=1)))
	{
		cout << MESSEGE_BAD_ENTER << endl ;
		return 0;
	}
	return 1;
}

bool Is_the_number_acceptable(int _number , int position)
{
		if ( position < Count_bits(_number)) 
			return 1;
		cout << MESSEGE_BAD_ENTER << endl;
		return 0;
}

bool Is_the_number_acceptable(int _number)
{
		if (_number < 256)
			return 1;
		cout << MESSEGE_BAD_ENTER << endl;
		return 0;
}
