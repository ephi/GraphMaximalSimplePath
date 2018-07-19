#pragma once
#include "ListForEachGraph.h"
class ListForEachGraphResetForScan : public ListForEach<Node<Vertex*>> {

protected:
	void onForEachListExecute(){ 
		Vertex *currentNode = this->getValue()->getValue();
		currentNode->color = WHITE;
		currentNode->pi = NILL;		
	}
};