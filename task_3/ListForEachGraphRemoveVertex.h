#include "ListForEachGraph.h"
#include "Vertex.h"
class ListForEachGraphRemoveVertex : public ListForEachGraph {
public:
	ListForEachGraphRemoveVertex(Vertex* v_source): ListForEachGraph(v_source) {}
protected:
	void onForEachListExecute(){
		Node<Vertex*>  *n_of_source = getValue();
		if((n_of_source)->getValue() == (getValue())->getValue())
		{
			(*this->sizeOfList)--;
			Node<Vertex*> * prev=  (n_of_source)->getPrev();
			Node<Vertex*> * next = (n_of_source)->getNext();
			next->setPrev(prev);
			prev->setNext(next);
			delete n_of_source;
		}
	}
};