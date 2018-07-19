#include "ListVertices.h"
#include <iostream>
using namespace std;
void ListVertices::Add(Vertex *v){

	List::Add(new Node<Vertex*>(v));	

}
Node<Vertex*>* ListVertices::createNodeInstance(Node<Vertex*> * currentNode){
	Node<Vertex*>* clonedNode = new Node<Vertex*>(currentNode->getValue()->clone());
	return clonedNode;

}
void ListVertices::onPrint(std::ostream & os,Vertex* value){
	os <<  value->name << ", ";
}