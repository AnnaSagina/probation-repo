#include "CreatorHandler.h"

void main()

{
	Handler* handler;
	Rectangle rectangle(10,20);
	CreatorSmall my_small;
	CreatorBig my_big;

	cout << "Small handler" << endl;
	handler = my_small.CreateHandler();
	handler->MainFuncHandler(rectangle);
	cout << endl;
	cout << "Big handler" << endl;
	handler = my_big.CreateHandler();
	handler->MainFuncHandler(rectangle);
	system("pause");

}