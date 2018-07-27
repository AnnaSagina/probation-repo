#include "Handler.h"
using namespace std;
#ifndef __INPUT_METOD_H__
#define __INPUT_METOD_H__

const char INCORR_DATA_MESSEGE[20] = "incorrect data";

bool Is_good_input_config(char* str_config)
{
	if ( (sizeof(str_config) == 4) )
	{
	for (int i = 0; i < 4; i++)
		if (!((str_config[i] == '0')||(str_config[i] == '1')))
		{
			cout << INCORR_DATA_MESSEGE << endl;
			return 0;
		}
	return 1;
	}
	else
	{
		cout << INCORR_DATA_MESSEGE << endl;
		return 0;
	}
}

bool Is_bad_input_data()
{
	return 0;
}
#endif