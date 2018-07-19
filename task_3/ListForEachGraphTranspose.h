#pragma once
#include "ListForEach.h"
#include "ListForEachGraphAddNodeToN_V_MINUS.h"
#include "ListForEachGraphAddNodeToN_V_PLUS.h"
#include "Vertex.h"

class ListForEachGraphTranspose : public ListForEach<Node<Vertex*>>  {
private:
	void shiftNeighborsGroups(ListForEachGraphAddNodeToN_V *nodeToV,List<Vertex*>  *n_v){	
		n_v->ForEach(nodeToV);
		delete nodeToV;
	}
protected:
	void onForEachListExecute(){
		Node<Vertex*> *node = this->getValue();
		Vertex* v = (node)->getValue();
		//shift neighbors from plus to minus
		//ListVertices * minusListCopy = (ListVertices * )this->getValue()->getValue()->GetNeighborsMinus()->clone();
		ListForEachGraphAddNodeToN_V_MINUS * nv_minus =	new ListForEachGraphAddNodeToN_V_MINUS(v);
		nv_minus->setTransposedFlag(true);
		shiftNeighborsGroups(nv_minus,(this->getValue())->getValue()->GetNeighborsPlus());
		//shift neighbors from minus to plus
		ListForEachGraphAddNodeToN_V_PLUS * nv_plus =	new ListForEachGraphAddNodeToN_V_PLUS(v);
		nv_plus->setTransposedFlag(false);
		shiftNeighborsGroups(nv_plus,(this->getValue())->getValue()->GetNeighborsMinus());
	};

};