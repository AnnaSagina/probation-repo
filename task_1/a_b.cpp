//tack1.cpp
#include <iostream>
#include <fstream>

using namespace std;


int bad_enter(bool &k)
{
	if (!cin.good())
	{
		cout << "Incorrect, enter numerics"<<endl;
		k = false;
		cin.clear();
		while(cin.get() != '\n');
		return 1;
	}
	return 0;
}
	
void main(int argc,char **argv)
{
	int f = 1;
	char *str = new char[11];
	char g[10] = " ";
	int a = 0,b = 0;
	str=" ";
	bool k = true;
	while(f == 1)
	{
		if (argc != 4)
		{
			cout << "Please enter a,b and perimetr/square/both" << endl;

			switch(argc)
			{
				case 1:
					{				
						cout << "Please enter remaining data, left 3" << endl;
						cin >> a;
						if (bad_enter(k))
							break;

						cin >> b;
						if (bad_enter(k))
							break;
						cin >> g;
						str = g;
						break;
					}
				case 2:
				{
					cout << "Please enter remaining data, left 2"<<endl;
					cin >> b;
					if (bad_enter(k))
							break;
					cin >> g;
					str = g;
					break;
				}
				case 3:
				{
					cout << "Please enter remaining data, left 1"<<endl;
					cin >> g;
					str = g;
					break;
				}
			}
		}
		else
		{
			a = atoi(argv[1]);
			if (a == 0) 
			{ 
				k = false; 
				cout <<"incorrect data"<<endl;
			}
			b = atoi(argv[2]);
			if (b == 0) 
			{ 
				k = false; 
				cout <<"incorrect data"<<endl;
			}
			str = argv[3];
	
		}
		if (k)
		{
		if (strcmp(str,"square") == 0)
			cout <<"Square = "<< a*b << endl;
		else if  (strcmp(str,"perimetr") == 0)
				cout <<"Perimetr = "<< 2*(a+b)<< endl;
			else if (strcmp(str,"both") == 0)
				 {
					cout <<"Square = "<< a*b << endl;
					cout <<"Perimetr = "<< 2*(a+b)<< endl;
				 }
				 else
					
					 {
						 cout <<"incorrect data"<<endl;
					}
		argc = 1;
		}
		k = true;
		cout <<"1.continue"<<endl;
		cout <<"2.exit"<<endl;
		if(cin.good())
		cin >> f;
	
	}
		cout<<"  "<<endl;
	//
	//cout<<"files:"<<endl;
	//ifstream fin("f1.txt");
	//fin >> a;
	//fin >> b;
	//cout<<"square = "<<a*b<<endl;
	//cout <<"Perimetr = "<< 2*(a+b)<< endl;
	//cout<<"  "<<endl;

	/*char str2[11];*/
	
}