#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <bitset>

using namespace std;

template <class Type>

class Node
{
private:
	Type data;
	Node<Type>* next;
public:

	Node(Type _data = Type(), Node<Type>* n = NULL) 
	{
		SetData(_data);
		SetNext(n);
	}

	void SetData(Type _data)
	{
	 data = _data;
	}

	void SetNext(Node<Type>* _next)
	{
		next = _next;
	}

	Type GetData()
	{
		return data;
	}

	Node<Type>* GetNext()
	{
		return next;
	}
};