#pragma once
#include "Vertex.h"
#include "ListForEachGraph.h"
class ListForEachMaxPath : public ListForEachGraph {
public: 
	ListForEachMaxPath(Vertex *v_source,Vertex **pointer_last_in_path) :ListForEachGraph(v_source), pointer_last_in_path(pointer_last_in_path){}
	virtual void onEmptyList(){
		if(*pointer_last_in_path != NILL)
			(*pointer_last_in_path)->color = RED;
	};
	virtual void onNonEmptyList(){
		*pointer_last_in_path = NILL;
	};
private:
	Vertex **pointer_last_in_path;
protected:
	void onForEachListExecute(){ 
		Vertex *currentNode = this->getValue()->getValue();
		if(currentNode->color != RED){
			if(v_source->color == WHITE){
				currentNode->pi = v_source;
				v_source->color = RED;
				ListForEachMaxPath * lfemp = new ListForEachMaxPath(currentNode,pointer_last_in_path);
				ListVertices * lvOut = currentNode->GetNeighborsPlus();
				lvOut->ForEach(lfemp);
			}
			if(*pointer_last_in_path == NILL)
				*pointer_last_in_path = currentNode;
		}
		//PrintNeighbors(currentNode->GetNeighborsPlus());
		//os << "is connected from: ";
		//PrintNeighbors(currentNode->GetNeighborsMinus());
	}
};