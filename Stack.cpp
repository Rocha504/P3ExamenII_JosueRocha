#include "Stack.h"
#include <iostream>
#include <vector>
using namespace std;


template<class T>
Stack<T>::Stack(){
	
}

template<class T>
void Stack<T>:: push(T elemento){
	this->pila.push_back(elemento);
}

template<class T>
void Stack<T>:: pop(){
	this->pila.pop_back();
}

template<class T>
T Stack<T>::top(){
	return this->pila[pila.size()-1];
}

template<class T>
void Stack<T>::print(){
	for(int i=0;i<this->pila.size();i++){
		
		cout<<"["<<this->pila[i]<<"]"<<endl;
	}
 
}
 
 