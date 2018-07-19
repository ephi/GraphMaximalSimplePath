#pragma once
#define NILL 0
template<typename T>
class Node{
public:
	Node(T value):pNext(NILL),pPrev(NILL),value(value){}
	~Node(){}
	Node<T> * getNext() const { return this->pNext;}
	Node<T> * getPrev() const { return this->pPrev;}
	void setNext(Node<T> * pNext) { this->pNext =pNext; }
	void setPrev(Node<T> * pPrev) { this->pPrev =pPrev; }
	T getValue() {  return value ;}
private:
	T value;
	Node<T> *pNext;
	Node<T> *pPrev;
};