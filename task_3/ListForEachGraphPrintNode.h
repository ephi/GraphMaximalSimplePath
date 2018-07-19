#pragma once
#include "ListForEachGraph.h"
class ListForEachGraphPrintNode : public ListForEach<Node<Vertex*>> {
private:
	ostream &os;
public:
	ListForEachGraphPrintNode(ostream & os): os(os) {}
protected:
	void onForEachListExecute(){ 
		Vertex *currentNode = this->getValue()->getValue();	
		os << currentNode->name << ", ";
	}
};