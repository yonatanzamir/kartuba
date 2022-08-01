#include "ItemType.h"
ItemType::ItemType(string X, string Y, int n, string res, int  line, string ac, string bd, string abcd, string st1, string st2, string st3, string st4, string restemp,
	int multiply, ItemType* ptr) :res(res),next(ptr)// ItemType constructor
{
	this->X = X;
	this->Y = Y;
	this->ac = ac;
	this->bd = bd;
	this->abcd =abcd;
	this->st1 = st1;
	this->st2 = st2;
	this->st3 = st3;
	this->st4 = st4;
	this->restemp = restemp;
	this->multiply = multiply;
	this->n = n;
	this->line = line;

}
ItemType::ItemType(string X, string Y, int n, string res, int  line):X(X),Y(Y),res(res),line(line),n(n)// ItemType constructor
{
}

void ItemType::operator=(const ItemType& other) // ItemType operator=
{
	this->X = other.X;
	this->Y = other.Y;
	this->n = other.n;
	this->res = other.res;
	this->line = other.line;
	this->ac = other.ac;
	this->bd = other.bd;
	this->abcd = other.abcd;
	this->st1 = other.st1;
	this->st2 = other.st2;
	this->st3 = other.st3;
	this->st4 = other.st4;
	this->restemp = other.restemp;
	this->multiply = other.multiply;
	this->next = nullptr;
}