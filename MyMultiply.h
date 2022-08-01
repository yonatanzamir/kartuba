#include <iostream>
#include <string>
#include <cctype>
#include "Stack.h"
#include "ItemType.h"

using namespace std;
char* Long_Multiply(string num1, string num2);
bool Is_Valid_Input(string num1, string num2, int n);
bool Is_Digit(char ch);
void Kartsuba(string X, string Y, int n, string& res);
string Long_subtract(string num1, string num2);
string Long_Add(string num1, string num2);
string Pow_Ten(string num, int n);
string Pow_Ten1(string num, int n);
void Print_result(string res);
string CharArrToString(char* str, int size);
int Is_Size_Valid(string size);
void Iterative_Kartsuba(string X, string Y, int n, string& res);
