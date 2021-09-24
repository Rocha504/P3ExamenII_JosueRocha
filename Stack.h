#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Stack
{
	public:
		Stack<T>();
		void push(T);
		T top();
		void pop();
		 
	protected:
		vector <T> pila;
};

#endif