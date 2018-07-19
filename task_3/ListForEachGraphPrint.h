#pragma once
#include "ListForEachGraph.h"
#include "ListForEachGraphPrintNode.h"
class ListForEachGraphPrint : public ListForEach<Node<Vertex*>> {
private:
	ostream &os;
	void PrintNeighbors(ListVertices * lv){
	  os	<< endl;
		if(lv->getSize() == 0)
			os  <<"None";
		else
		{
			ListForEachGraphPrintNode * lfegpn = new ListForEachGraphPrintNode(os);
			lv->ForEach(lfegpn);
			delete lfegpn;
		}
		os << endl;
	}
public:
	ListForEachGraphPrint(ostream & os): os(os) {}
protected:
	void onForEachListExecute(){ 
		Vertex *currentNode = this->getValue()->getValue();
		os << "Current Node: " << currentNode->name << endl;
        os << "is connected to: ";
		ListVertices * lvOut = currentNode->GetNeighborsPlus();
		PrintNeighbors(currentNode->GetNeighborsPlus());
		os << "is connected from: ";
		PrintNeighbors(currentNode->GetNeighborsMinus());
		
	}
};