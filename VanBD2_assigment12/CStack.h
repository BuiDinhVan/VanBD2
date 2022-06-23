#pragma once

template<class T>
class Stack {
private:
	T* Data;
	int index;
public:
	Stack();
	void push(T data);
	T pop();
};
