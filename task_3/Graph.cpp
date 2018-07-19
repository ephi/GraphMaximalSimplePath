#include "Graph.h"
#include "ListForEachGraphTranspose.h"
#include "ListForEachGraphPrint.h"
#include "ListForEachGraphResetForScan.h"
Graph::Graph()
{
	vertices = new ListVertices();
}
void Graph::transpose() {
	ListForEachGraphTranspose * lfegt = new ListForEachGraphTranspose();
	vertices->ForEach(lfegt);
	delete lfegt;
}
void Graph::addVertex(Vertex* v){
	vertices->Add(v);
}
void Graph::printGraph(ostream & os){
	ListForEachGraphPrint * lfegp = new ListForEachGraphPrint(os);
	vertices->ForEach(lfegp);
	delete lfegp;
}
void Graph::resetNodesForScan(){
	ListForEachGraphResetForScan * lfe = new ListForEachGraphResetForScan();
	vertices->ForEach(lfe);
	delete lfe;
}

Graph::~Graph(void)
{
	delete vertices;
}