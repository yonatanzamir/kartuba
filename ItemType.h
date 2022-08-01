#pragma once
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
class ItemType
{
private:	ItemType* next;
public:
	friend class Stack;
	string X, Y, ac, bd, abcd, st1, st2, st3, st4, restemp;
	string res;
	int multiply, n, line;

	ItemType(string X, string Y, int n, string res, int  line, string ac, string bd, string abcd, string st1, string st2, string st3, string st4, string restemp,
		int multiply, ItemType* ptr = nullptr);
	ItemType(string X, string Y, int n, string res, int  line);
	void operator=(const ItemType& other);
	ItemType();

};