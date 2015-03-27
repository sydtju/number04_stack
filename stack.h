/*模板类  简易stack的实现*/
#pragma once  
#ifndef _STACK_H
#define _STACK_H

template<class T>
class Stack{
public:
	Stack(int capacity=10);
	T pop();
	bool push(T element);
	bool isEmpty()const;
	bool isFull()const;
	int getNumber()const;
	~Stack();
private:
	int capacity;
	int top;
	T* stack;
};

template<class T>
Stack<T>::Stack(int capacity=10){
	this->capacity=capacity;
	this->stack=new T[capacity];
	top=-1;
}
template<class T>
bool Stack<T>::isEmpty()const{
	return -1==top?true:false;
}
template<class T>
bool Stack<T>::push(T element){
	if(Stack<T>::isFull())
		return false;
	else{
		top++;
		stack[top]=element;
		return true;
	}
}
template<class T>
T Stack<T>::pop(){
	if(Stack<T>::isEmpty())
		throw "the stack is empty!\n";
	else{
		return stack[top--];
	}
}
template <class T>
bool Stack<T>::isFull()const{
	return  top==capacity-1?true:false; 
}
template <class T>
int Stack<T>::getNumber()const{
	return top+1;
}
template <class T>
Stack<T>::~Stack(){
	delete[] stack;
	stack=NULL;
}
#endif
