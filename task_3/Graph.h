#pragma once
#include "Vertex.h"
#include "ListVertices.h"
class Graph
{
private:
	ListVertices * vertices;
public:
	void addVertex(Vertex* v);
	void transpose();
	void printGraph(ostream & os);
	void resetNodesForScan();
	Graph();
	~Graph(void);
};

