#pragma once
#include "ListVertices.h"
#include "Graph.h"
class MaximalPathAlgo
{
private:
	Graph *g;
	ListVertices *maximal_path_in_g_including_y;
	ListVertices *maximal_path_in_g_including_x_y;
	void PrintPath(Vertex *v,ListVertices *lv);
public:
	MaximalPathAlgo(Graph *g);
	ListVertices * FindMaximalPath(Vertex *x,Vertex * y);
	~MaximalPathAlgo(void);
};

