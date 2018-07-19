#pragma once
#include "ListForEach.h"
#include "Vertex.h"
class ListForEachGraph : public ListForEach<Node<Vertex*>>{
public:
	ListForEachGraph(Vertex* v_source): v_source(v_source) {}
protected:
	Vertex* v_source;
};