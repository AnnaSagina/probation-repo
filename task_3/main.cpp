#include "BitOperations.h"
#include "InputMetods.h"

using namespace std;

void Execute_the_selected_function(int _choose_value, int  _number)
{
	int position;
	switch(_choose_value)
	{
		case 1:
		{
			cout << ANSWER << Counting_bits_equal_to_one(_number) <<  endl;
			break;
		}
		case 2:
		{
			cout << "Enter position" << endl;
			cin >> position;
			if (Is_the_number_acceptable(_number,_choose_value)) 
			{
				cout << ANSWER << set_bit_i(_number,position) << 
					"( " << BINARY_FORM  << dec2bin(set_bit_i(_number,position))<<")"<< endl ;
				break;
			}
			break;
		}
		case 3:
		{
			if (Is_the_number_acceptable(_number)) 
			{
				cout << ANSWER << Bit_cyclic_shift(_number) << 
					"(" << BINARY_FORM  << dec2bin( Bit_cyclic_shift(_number))<<")"<< endl ;
				break;
			}
			break;
		}
	}
}

void main()
{
	int number,continuation = 1 ;
	int choose_value;
	while (continuation == 1)
	{
		cout << "Choose a function" << endl;
		do
		{
			cout << "1. Counting_bits_equal_to_one " << endl;
			cout << "2. Replacement_of_the_i_th_bit_by_one " << endl;
			cout << "3. Bit_cyclic_shift " << endl;
			cin >> choose_value;
		}
		while(!Is_good_enter( choose_value));

		do
		{
			cout << "Enter number" << endl;
			cin >> number;
		}
		while(!Is_good_enter());
	
		cout << "(" <<BINARY_FORM << dec2bin(number)<< ")" << endl;	
		Execute_the_selected_function(choose_value, number);
		cout << "Do you want to continue?" << endl;
		cout << "1. yes" << endl;;
		cin >> continuation;
		if(!cin.good())
		{
			continuation = -1;
		}
	}		
	system("pause");
}
