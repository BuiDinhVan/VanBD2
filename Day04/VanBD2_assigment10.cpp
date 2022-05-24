#include<iostream>
using namespace std;

class String
{
public:
	char* str;
	String();
	friend String operator + (const String&, const String&);
	friend ostream& operator << (ostream&, String&);
	friend istream& operator >> (istream&, String&);
};

int main() {
	String str1, str2, merge;
	cin >> str1; cin >> str2;
	merge = str1 + str2;
	cout << "The result: ";
	cout << merge;
	return 0;
}

String::String() {
	this->str = new char[100];
	if (this->str)
		memset(this->str, '\0', 100);
}

/**********************************************************
* Input: str1, str2: String
* Return: String
* Description: operator overloading to link two string
***********************************************************/
String operator+(const String& str1, const String& str2)
{
	String merge;
	int index_merge = 0, index_str1 = 0, index_str2 = 0;
	while (str1.str[index_str1] != '\0')
	{
		merge.str[index_merge++] = str1.str[index_str1++];
	}
	while (str2.str[index_str2] != '\0')
	{
		merge.str[index_merge++] = str2.str[index_str2++];
	}
	return merge;
}

/**********************************************************
* Input: str: String
* Description: cout operator overloading
***********************************************************/
ostream& operator<<(ostream& out, String& str)
{
	out << str.str;
	return out;
}

/**********************************************************
* Input: str: String
* Description: cin operator overloading
***********************************************************/
istream& operator>>(istream& in, String& str)
{
	cout << "Enter the string: ";
	in >> str.str;
	return in;
}

