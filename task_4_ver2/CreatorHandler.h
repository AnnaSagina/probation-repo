#include "Handler.h"

class CreatorHandler
{
public:

	virtual Handler* CreateHandler() = 0;
};

class CreatorSmall: public CreatorHandler
{
public:
	Handler* CreateHandler()
	{
		return new HandlerSmall;
	}

};

class CreatorBig: public CreatorHandler
{
public:
	Handler* CreateHandler()
	{
		return new HandlerBig;
	}

};