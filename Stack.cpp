#include "Stack.h"

Stack::Stack()
{
	top = nullptr;
}
Stack::~Stack()
{
	MakeEmpty();
}
void Stack::MakeEmpty() {
	ItemType* temp;
	while (top != nullptr)
	{
		temp = top;
		top = top->next;
		delete temp;
	}
}
bool Stack::IsEmpty() {
	return (top == nullptr);
}

void Stack::Push(ItemType t)
{
	ItemType* temp =new ItemType(t.X,t.Y,t.n, t.res, t.line,t.ac, t.bd, t.abcd, t.st1, t.st2, t.st3, t.st4, t.restemp,
		 t.multiply , top);
	top = temp;

}
ItemType Stack::pop()
{
	if (IsEmpty())
	{
		cout << "This stack is empty " << endl;
		exit(1);
	}
	ItemType* item = top;
	ItemType temp = *item;
	top = top->next;
	delete item;
	temp.next = nullptr;
	return temp;
}