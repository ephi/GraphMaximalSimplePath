#pragma once
#include "ListVertices.h"
#include <string>
using namespace std;
enum COLORS { WHITE, RED };
class ListVertices;
class Vertex {
public:
	Vertex(char *name):pi(NILL),N_V_PLUS(NILL),N_V_MINUS(NILL),color(WHITE),name(name),hasTransposed(false) {}
	void AddNeighborPlus(Vertex* v);
	void AddNeighborMinus(Vertex* v);
	ListVertices * GetNeighborsPlus();
	ListVertices * GetNeighborsMinus();
	~Vertex();
	Vertex* clone(bool isShallowClone = 1);
	friend class ListVertices;
	friend class ListForEachGraphAddNodeToN_V;
	friend class ListForEachGraphPrint;
	friend class ListForEachGraphResetForScan;
	friend class ListForEachGraphPrintNode;
	friend class MaximalPathAlgo;
	friend class ListForEachGraphPrint;
	friend class ListForEachMaxPath;
//	void clearTransposedFlag(){};
private:
	string name;
	ListVertices * N_V_PLUS;//out neihbors
	ListVertices * N_V_MINUS;//in
	COLORS color;
	Vertex* pi;
	bool hasTransposed;
};