#include "MaximalPathAlgo.h"
#include "ListForEachFindMaxPath.h"
MaximalPathAlgo::MaximalPathAlgo(Graph *g):g(g)
{
	g->resetNodesForScan();
	maximal_path_in_g_including_y = new ListVertices();
	maximal_path_in_g_including_x_y =  new ListVertices();
}

void MaximalPathAlgo::PrintPath(Vertex *v,ListVertices* lv){
	while(v != NILL)
	{
		Vertex *tmp = v;
		lv->Add(v);
		v = v->pi;
		tmp->pi = NILL;
	}
}

ListVertices * MaximalPathAlgo::FindMaximalPath(Vertex *x,Vertex * y){
	Vertex * pointer_last_in_path_a = y;
	ListForEachMaxPath * lfemp = new ListForEachMaxPath(y,&pointer_last_in_path_a);
	y->GetNeighborsPlus()->ForEach(lfemp);
	delete lfemp;
	PrintPath(pointer_last_in_path_a,maximal_path_in_g_including_y);
	maximal_path_in_g_including_y->Reverse();
	g->transpose();
	Vertex * pointer_last_in_path_b = x;
	lfemp = new ListForEachMaxPath(x,&pointer_last_in_path_b);
	x->GetNeighborsPlus()->ForEach(lfemp);
	PrintPath(pointer_last_in_path_b,maximal_path_in_g_including_x_y);
	delete lfemp;
	if(maximal_path_in_g_including_x_y->getRoot() == NILL)
	{
		maximal_path_in_g_including_x_y->Add(x);
	}

	if(maximal_path_in_g_including_y->getLast()->getValue() == maximal_path_in_g_including_x_y->getLast()->getValue())
		maximal_path_in_g_including_y->RemoveLast();
	maximal_path_in_g_including_x_y->AppendList(maximal_path_in_g_including_y);

	return maximal_path_in_g_including_x_y;

}
MaximalPathAlgo::~MaximalPathAlgo(void)
{
	//re-transpose to original graph
	g->transpose();
	delete maximal_path_in_g_including_x_y;
}
