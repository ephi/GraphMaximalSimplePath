#pragma once
#include "Node.h"
#include "ListForEach.h"
#include <iostream>
using namespace std;
template<typename T> 
class List {
public:
	List(): root(NILL),size(0){};
	List(Node<T>* root): root(root),size(0),last(NILL){};
	virtual void Add(Node<T> *newNode)  {
		size++;
		Node<T> * node = root;
		if(node == NILL){
			root = newNode;
			last = newNode;
			return;
		}
		while(node->getNext() != NILL) 
			node = node->getNext();
		node->setNext(newNode);
		newNode->setPrev(node);
		last = newNode;
	};
	void ForEach(ListForEach<Node<T>> * lfe){
		Node<T> * node = root;
		lfe->setTreeRoot(&root);
		if(size != 0)
			lfe->onNonEmptyList();
		while(node != NILL)
		{
			lfe->setValue(node);
			lfe->setSizeOfList(&size);
			(*lfe)();
			node = node->getNext();
		}
		if(root == NILL)
			lfe->onEmptyList();
		lfe->setTreeRoot(NILL);
		lfe->setSizeOfList(NILL);
	};
	int getSize() const { return size; };
	void PrintList(ostream & os) {
		Node<T> * node = root;
		while(node != NILL) {
			onPrint(os,node->getValue());
			node = node->getNext();
		}
		onPrintComplete(os);
	};
	List* clone(){
		List* clonedList = createListInstance();
		if(root == NILL)
			return clonedList;
		Node<T> * node = root;
		while(node != NILL)
		{
			Node<T> * clonedNode = createNodeInstance(node);
			clonedList->Add(clonedNode);
			node = node->getNext();
		}
		return clonedList;
	};
	void Clear() {
		if(root == NILL)
			return;
		Node<T>* node = root;
		while(node != NILL){
			Node<T> *prev = node->getPrev();
			if(prev != NILL)
				delete prev;
			node->setPrev( NILL);
			if(node->getNext() == NILL){
				delete node;
				node = NILL;
			}
			else
				node = node->getNext();
		}
		root = NILL;

	};
	Node<T> * getRoot() {
		return root;
	}
	void AppendList(List* list){
		if(this->last == NILL)
			return;
		this->last->setNext(list->getRoot());
		if(list->getRoot() != NILL)
			list->getRoot()->setPrev(this->last);
		this->size += list->getSize();
		//delete list;
	};
	void RemoveLast() {
		if(this->last == NILL)
			return;
		Node<T> * prevLast = this->last->getPrev();
		if(prevLast == NILL)
			this->last = NILL;
		else
			prevLast->setNext(NILL);
		delete this->last;		
		this->last = prevLast;
		size--;
	};
	void Reverse() {
		Node<T> *temp = NILL;  
		Node<T> *current = this->root; 
		this->last = this->root;
		/* swap next and prev for all nodes of 
		doubly linked list */
		while (current !=  NULL)
		{
			temp = current->getPrev();
			current->setPrev(current->getNext());
			current->setNext(temp);              
			current = current->getPrev();
		}       
		/* Before changing head, check for the cases like empty 
		list and list with only one node */
		if(temp != NULL )
			this->root = temp->getPrev();
	};
	Node<T>* getLast(){
		return last;
	};
	virtual ~List(){
		Clear();
	};
protected:
	virtual List * createListInstance() { return new List(); };
	virtual Node<T>* createNodeInstance(Node<T> * currentNode) { return new Node<T>(currentNode->getValue()); };
	virtual void onPrint( ostream & os,T value) {};
	virtual void onPrintComplete( ostream & os) {};
private:
	Node<T>* root;
	Node<T>* last;
	int size;
};