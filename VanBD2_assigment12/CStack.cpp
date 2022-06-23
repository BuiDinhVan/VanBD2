#include<iostream>
#include"CStack.h"
using namespace std;

template<typename T>
Stack<T>::Stack() {
	Data = new T[100];
	index = 0;
}

template<typename T>
void Stack<T>::push(T data) {
	Data[index++] = data;
}

template<typename T>
T Stack<T>::pop() {
	return Data[--index];
}

int main() {
	Stack<int> s;
	for (int i = 0; i < 10; i++)
		s.push(i);
	for (int i = 0; i < 10; i++) {
		cout << s.pop() << " ";
	}
	return 0;
}