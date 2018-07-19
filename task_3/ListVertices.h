#pragma once
#include "List.h"
#include "Vertex.h"
class Vertex;
class ListVertices : public List<Vertex*> {
public:
	void Add(Vertex* vertex);
protected:
	List * createListInstance() { return new ListVertices(); };
	Node<Vertex*>* createNodeInstance(Node<Vertex*> * currentNode);
	void onPrint( ostream & os,Vertex* value);
};