#pragma once
#include "ItemType.h"

class Stack
{
private:
	ItemType* top;
public:
	Stack();
	~Stack();
	void MakeEmpty();
	bool IsEmpty();
	void Push(ItemType item);
	ItemType pop();
};

