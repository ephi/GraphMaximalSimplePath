#pragma once
#include "ListForEachGraph.h"
class ListForEachGraphAddNodeToN_V : public ListForEachGraph {
private :
	bool transposedFlag;
public:	
	ListForEachGraphAddNodeToN_V(Vertex* v_source): ListForEachGraph(v_source),transposedFlag(false) {}
	void setTransposedFlag(bool transposedFlag) { 
	   this->transposedFlag = transposedFlag;

	}
protected:
	virtual void onMoveFromNeighborGroup() = 0;
	void onForEachListExecute(){
		Node<Vertex*>  *n_of_source = getValue();
		Vertex * v = n_of_source->getValue();
		if(v->hasTransposed)
		{
			v->hasTransposed = transposedFlag;
			return;
		}
		onMoveFromNeighborGroup();
		Node<Vertex*> * prev=  (n_of_source)->getPrev();
		Node<Vertex*> * next = (n_of_source)->getNext();
		if(next != NILL)
		{
			next->setPrev(prev);
		}
		if(prev == NILL)
		{
			*(this->treeRoot) = next;
			//&(next->getPrev()) = NILL;
		}
		else
			prev->setNext(next);
		//delete n_of_source;
		(*sizeOfList)--;
		v->hasTransposed = transposedFlag;
	}
};