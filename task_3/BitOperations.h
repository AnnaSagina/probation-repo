#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int Ñounting_bits_equal_to_one(int _number)
{	
	int count = 0;
	while(_number)
	{
		if (_number & 1) 
			count ++;
		_number >>= 1;
	}
	return count;
}

int Replacement_of_the_i_th_bit_by_one(int _number, int i)
{
	int result = 0;
	int mask;
	mask = pow(2.0,i);
	result = mask | _number;
	return result;
}	

int Bit_cyclic_shift(int _number)
{
	unsigned char value_bit = (_number << 1)|(_number >> 7); //variable length in bits
	return (int)value_bit;
}

unsigned __int64 conversion_from_decimal_to_binary(int _number)
{
	unsigned __int64 binary_form = 0;
	unsigned __int64 digit = 1;
	while(_number)
	{
		binary_form += (_number % 2)*digit;
		_number /= 2;
		digit *= 10;
	}
	return binary_form;
}

int Count_bits(int _number)
{
	int count = 0;
	while (_number)
	{
		_number >>= 1;
		count++;
	}
	return count;
}