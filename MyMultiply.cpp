#include "MyMultiply.h"
enum { START, AFTER_FIRST, AFTER_SECOND, AFTER_THIRD };

string Long_Add(string num1, string num2)//Add two numbers in long add method
{
	while (num1.size() < num2.size())
		num1.insert(0, "0");
	while (num1.size() > num2.size())
		num2.insert(0, "0");

	string res;
	char* temp;
	int length = num1.size() - 1;
	int carry = 0;
	int res_length = length + 1;;
	temp = new char[res_length + 2];

	for (int i = length; i >= 0; i--)
	{
		int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
		temp[res_length] = sum % 10 + '0';
		carry = sum / 10;
		res_length--;
	}
	temp[res_length] = carry + '0';
	temp[length + 2] = '\0';
	int i = 0;
	while (temp[i] == '0' && i < length + 1)
	{
		i++;
	}
	res = temp + i;
	delete[]temp;
	return res;
}
string Long_subtract(string num1, string num2)//subtract two numbers in long subtract method 
{
	while (num1.size() < num2.size())
		num1.insert(0, "0");
	while (num1.size() > num2.size())
		num2.insert(0, "0");

	string res;
	char* temp;
	int curr;
	int length = num1.size() - 1;
	int carry = 0;
	int res_length = length;
	temp = new char[res_length + 2];
	for (int i = length; i >= 0; i--)
	{
		curr = (num1[i] - '0') - (num2[i] - '0') + carry;
		if (curr < 0)
		{
			curr += 10;
			carry = -1;
		}
		else
			carry = 0;
		temp[res_length] = curr % 10 + '0';
		res_length--;
	}
	temp[length + 1] = '\0';
	int i = 0;
	while (temp[i] == '0' && i < length)
	{
		i++;
	}
	res = temp + i;
	delete[]temp;
	return  res;
}


void Kartsuba(string X, string Y, int n, string& res)//algorithem 2 - recursive kartsuba 
{
	while (X.size() < Y.size())
		X.insert(0, "0");
	while (X.size() > Y.size())
		Y.insert(0, "0");
	n = X.size();//base on x=y
	if (n == 1)
	{
		res = Pow_Ten(res, 2);
		int multiply = (X[0] - '0') * (Y[0] - '0');
		res[res.size() - 2] = multiply / 10 + '0';
		res[res.size() - 1] = multiply % 10 + '0';
	}
	else
	{
		string ac, bd, abcd;
		Kartsuba(X.substr(0, n / 2), Y.substr(0, n / 2), n / 2, ac);
		Kartsuba(X.substr(n / 2, n), Y.substr(n / 2, n), n / 2 + n % 2, bd);
		Kartsuba(Long_Add(X.substr(0, n / 2), X.substr(n / 2, n)), Long_Add(Y.substr(0, n / 2), Y.substr(n / 2, n)), n / 2 + 2, abcd);
		string st1 = Long_subtract(abcd, ac);
		string st2 = Long_subtract(st1, bd);
		string st3;
		if (n % 2 == 0)
		{
			st2 = Pow_Ten(st2, n / 2);
			st3 = Pow_Ten(ac, n);
		}
		else {
			st2 = Pow_Ten(st2, n / 2 + 1);
			st3 = Pow_Ten1(ac, n);
		}

		string st4 = Long_Add(st2, st3);
		string restemp = Long_Add(st4, bd);
		res = restemp;
	}
}
void Print_result(string res)//print the results from the multiply methods 
{
	int i = 0;
	while (res[i + 1] != '\0' && res[i] == '0')
	{
		i++;
	}
	if (res[i + 1] == '\0')
		cout << res[i];
	else {
		for (; res[i] != '\0'; i++)
		{
			cout << res[i];
		}
	}
	cout << endl;
}

string CharArrToString(char* str, int size)// convert char* arr to string 
{
	string temp = "";
	temp = Pow_Ten(temp, size + 1);
	for (int i = 0; i < size; i++)
		temp[i] = str[i];
	temp[size] = '\0';
	return temp;
}

string Pow_Ten(string num, int n)// append zeros to set up power by 10^n - for even numbers
{

	for (int i = 0; i < n; i++)
		num.append("0");
	return num;
}
string Pow_Ten1(string num, int n)// append zeros to set up power by 10^n- for even numbers
{
	n = 2 * (n - n / 2);
	return Pow_Ten(num, n);
}

char* Long_Multiply(string num1, string num2) //algorithem 1 - Long multiply like 4th grade
{
	int index_num1, index_num2, digit_num_1, digit_num_2;
	int carry = 0;
	int size1 = num1.size();
	int size2 = num2.size();
	char* res = new char[size1 + size2];
	for (int i = 0; i < size1 + size2; i++)//(*)
	{
		res[i] = '0';
	}
	index_num1 = index_num2 = 0;
	for (int i = size1 - 1; i >= 0; i--)//(**)
	{
		int carry = 0;
		digit_num_1 = num1[i] - '0';
		index_num2 = 0;
		for (int j = size2 - 1; j >= 0; j--)
		{
			digit_num_2 = num2[j] - '0';
			int sum = digit_num_2 * digit_num_1 + res[index_num1 + index_num2] - '0' + carry;
			carry = sum / 10;
			res[index_num1 + index_num2] = sum % 10 + '0';
			index_num2++;
		}
		if (carry > 0)
		{
			res[index_num1 + index_num2] = ((res[index_num1 + index_num2] - '0') + carry) + '0';
		}
		index_num1++;
	}

	char* temp = new char[size1 + size2];
	int j = 0;

	for (int i = size1 + size2 - 1; i >= 0; i--)//(***)
	{
		temp[j++] = res[i];
	}
	delete[]res;
	return temp;
}


int Is_Size_Valid(string size)//checks if the size of the number is a valid input (leading zeros or non-digits -> wrong output)
{
	if (size[0] == '0' && size.size() != 1)
	{
		cout << "wrong output";
		exit(1);
	}
	else
	{
		int n = 0;
		int j = 1;
		int i = size.size() - 1;
		for (; i >= 0; i--)
		{
			if (!Is_Digit(size[i]))
			{
				cout << "wrong output";
				exit(1);
			}
			n += (size[i] - '0') * j;
			j *= 10;
		}
		return n;
	}

}

bool Is_Digit(char ch) //check if ch is a digit
{
	if (ch - '0' >= 0 && ch - '0' <= 9)
		return true;
	else
		return false;
}
bool Is_Valid_Input(string num1, string num2, int n)//checks if the size of the numbers is a valid input (two numbers have the same size as n and digits)
{
	if (num1.size() != n || num2.size() != n)
	{
		cout << "wrong output"<< endl;
		return false;
	}
	else
	{
		int i = 0;
		bool flag = true;
		while (i < n && flag)
		{
			if (!Is_Digit(num1[i]) || !Is_Digit(num2[i]))
			{
				cout << "wrong output" << endl;
				flag = false;
			}
			i++;
		}

		return flag;
	}
}


void Iterative_Kartsuba(string X, string Y, int n, string& res) //algorithem 3 - non-recursive kartsuba algorithem
{
	Stack S; 
	S.MakeEmpty();
	ItemType Curr(X, Y, n, res, START);                                                    
	int returnFromRecursion = 0;
	string temp;
	do { 
		if (returnFromRecursion)
			Curr = S.pop();
		if (Curr.line == START) {
			while (Curr.X.size() < Curr.Y.size())
				Curr.X.insert(0, "0");
			while (Curr.X.size() > Curr.Y.size())
				Curr.Y.insert(0, "0");
			Curr.n = Curr.X.size();
			if (Curr.n == 1) {
				Curr.res = Pow_Ten(Curr.res, 2);
				Curr.multiply = (Curr.X[0] - '0') * (Curr.Y[0] - '0');
				Curr.res[Curr.res.size() - 2] = Curr.multiply / 10 + '0';
				Curr.res[Curr.res.size() - 1] = Curr.multiply % 10 + '0';
				temp = Curr.res;
				returnFromRecursion = 1;
			}
			else {
				Curr.line = AFTER_FIRST;
				S.Push(Curr);
				Curr.X = Curr.X.substr(0, Curr.n / 2);
				Curr.Y = Curr.Y.substr(0, Curr.n / 2);
				Curr.n = Curr.n / 2;
				Curr.line = START;
				returnFromRecursion = 0;
			
			}
		}
		else if (Curr.line == AFTER_FIRST) {

			Curr.line = AFTER_SECOND;
			Curr.ac = temp;
			S.Push(Curr);
			Curr.X = Curr.X.substr(Curr.n / 2, Curr.n);
			Curr.Y = Curr.Y.substr(Curr.n / 2, Curr.n);
			Curr.n = ((Curr.n / 2) + (Curr.n % 2));
			Curr.line = START;
			returnFromRecursion = 0;
	
		}
		else if (Curr.line == AFTER_SECOND) 
		{
			Curr.line = AFTER_THIRD;
			Curr.bd = temp;
			S.Push(Curr);
			Curr.X = Long_Add(Curr.X.substr(0,Curr.n / 2),Curr.X.substr(Curr.n / 2, Curr.n));
			Curr.Y = Long_Add(Curr.Y.substr(0, Curr.n / 2), Curr.Y.substr(Curr.n / 2, Curr.n));
			Curr.n = Curr.n/2 + 2;
			Curr.line = START;
			returnFromRecursion = 0;
		}
		else if (Curr.line == AFTER_THIRD)
		{
			Curr.abcd = temp;
			 Curr.st1 = Long_subtract(Curr.abcd, Curr.ac);
			 Curr.st2 = Long_subtract(Curr.st1, Curr.bd);

			if (Curr.n % 2 == 0)
			{
				Curr.st2 = Pow_Ten(Curr.st2, Curr.n / 2);
				Curr.st3 = Pow_Ten( Curr.ac, Curr.n);
			}
			else {
				Curr.st2 = Pow_Ten(Curr.st2, Curr.n / 2 + 1);
				Curr.st3 = Pow_Ten1(Curr.ac, Curr.n);
			}

			Curr.st4 = Long_Add(Curr.st2, Curr.st3);
			Curr.restemp = Long_Add(Curr.st4, Curr.bd);
			Curr.res = Curr.restemp;
			temp = Curr.res;
			returnFromRecursion = 1;
		}
	} 
	while (!S.IsEmpty());
	res = Curr.res;
}
