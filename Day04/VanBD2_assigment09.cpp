#include <iostream>
using namespace std;

class CFraction
{
private:
	int num;
	int den;
	static int no;
public:
	CFraction();
	void enterCFraction();
	friend CFraction operator + (const CFraction&, const CFraction&);
	friend CFraction operator - (const CFraction&, const CFraction&);
	friend CFraction operator * (const CFraction&, const CFraction&);
	friend CFraction operator / (const CFraction&, const CFraction&);
	void printCFraction();
};

int CFraction::no = 1;

/******************************************************
* Input: a, b integer number
* Return: Greatest common factor
* Description: Find Greatest common factor of two number
*******************************************************/
int GreatCommondFactor(int a, int b) {
	a = abs(a);
	b = abs(b);
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

/******************************************************
* Description: Enter the number Fraction
*			   denominator other than 0
*******************************************************/
void CFraction::enterCFraction() {
	cout << "Enter num of CFraction " << this->no << ": ";
	cin >> this->num;
	do
	{
		cout << "Enter dem of CFraction " << this->no << ": ";
		cin >> this->den;
	} while (this->den == 0);
	this->no++;
}

/******************************************************
* Description: Print the number Fraction
*******************************************************/
void CFraction::printCFraction() {
	cout << this->num << "/" << this->den << endl;
}

CFraction::CFraction() :num(1), den(1) {};


/******************************************************
* Input: a, b: two number Fraction
* Return: The sum of two Fraction
* Description: plus operator overloading of two Fraction
*******************************************************/
CFraction operator + (const CFraction& a, const CFraction& b)
{
	CFraction result;
	int GCF;
	result.num = a.num * b.den + a.den * b.num;
	result.den = a.den * b.den;
	GCF = GreatCommondFactor(result.num, result.den);
	result.num /= GCF;
	result.den /= GCF;
	return result;
}

/******************************************************
* Input: a, b: two number Fraction
* Return: The subtraction of two Fraction
* Description: minus operator overloading of two Fraction
*******************************************************/
CFraction operator - (const CFraction& a, const CFraction& b)
{
	CFraction result;
	int GCF;
	result.num = a.num * b.den - a.den * b.num;
	result.den = a.den * b.den;
	GCF = GreatCommondFactor(result.num, result.den);
	result.num /= GCF;
	result.den /= GCF;
	return result;
}

/******************************************************
* Input: a, b: two number Fraction
* Return: The multiply of two Fraction
* Description: multiply operator overloading of two Fraction
*******************************************************/
CFraction operator * (const CFraction& a, const CFraction& b)
{
	CFraction result;
	int GCF;
	result.num = a.num * b.num;
	result.den = a.den * b.den;
	GCF = GreatCommondFactor(result.num, result.den);
	result.num /= GCF;
	result.den /= GCF;
	return result;
}

/******************************************************
* Input: a, b: two number Fraction
* Return: The divide of two Fraction
* Description: devide operator overloading of two Fraction
*******************************************************/
CFraction operator / (const CFraction& a, const CFraction& b)
{
	CFraction result;
	int GCF;
	result.num = a.num * b.den;
	result.den = a.den * b.num;
	GCF = GreatCommondFactor(result.num, result.den);
	result.num /= GCF;
	result.den /= GCF;
	return result;
}

int main()
{
	CFraction cF1, cF2, Result;
	cF1.enterCFraction();
	cF2.enterCFraction();
	Result = cF1 + cF2;
	cout << "The sum of tow Fraction: ";
	Result.printCFraction();
	Result = cF1 - cF2;
	cout << "The subtraction of tow Fraction: ";
	Result.printCFraction();
	Result = cF1 * cF2;
	cout << "The multiply of tow Fraction: ";
	Result.printCFraction();
	Result = cF1 / cF2;
	cout << "The divide of tow Fraction: ";
	Result.printCFraction();
	return 0;
}


