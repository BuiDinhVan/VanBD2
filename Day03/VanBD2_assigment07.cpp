#include <iostream>
using namespace std;

/************************************************************************
* Input: float a, b
* Return: sum of two numbers
* Descripton: Plus two numbers
*************************************************************************/
float Plus(float a, float b){
    return a + b;
}

/************************************************************************
* Input: float a, b
* Return: subtract of two numbers
* Descripton: Minus two numbers
*************************************************************************/
float Minus(float a, float b){
    return a - b;
}

/************************************************************************
* Input: float a, b
* Return: Multiply of two numbers
* Descripton: Multiply two numbers
*************************************************************************/
float Multiply(float a, float b){
    return a * b;
}

/************************************************************************
* Input: float a, b
* Return: Divide of two numbers
* Descripton: Divide two numbers
*************************************************************************/
float Devide(float a, float b){
    return a / b;
}

/************************************************************************
* Input: float a, b
* Return: Result of operation
* Descripton: Implement basic operations
*************************************************************************/
void opearation(float a, float b, float(*p2Fun)(float,float)){
    cout << p2Fun(a, b) << endl;
}

int main()
{
    float a, b;
    cout << "Enter a, b: \n";
    cin >> a >> b;
    cout << "a + b =  ";
    opearation(a, b, Plus);
    cout << "a - b =  ";
    opearation(a, b, Minus); 
    cout << "a * b =  ";
    opearation(a, b, Multiply);
    cout << "a / b =  ";
    opearation(a, b, Devide);
    return 0;
}