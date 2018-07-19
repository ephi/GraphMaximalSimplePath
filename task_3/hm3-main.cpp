#define _CRT_SECURE_NO_WARNINGS
#include "Graph.h"
#include "MaximalPathAlgo.h"
#include <vector>
#include <sstream>
using namespace std;
#define DEBUG 0


vector<vector<int>> split(string str) { 
	vector<vector<int>> internalv;
	bool isInNode = false;
	int nNumber = -1;
	for(size_t i = 0; i< str.length();++i){
		if( str[i] == '{' ){
			isInNode = true;
			nNumber = -1;
			internalv.push_back(vector<int>());
		}
		else if(str[i] == ',' )
		{
			if(nNumber != -1){
				nNumber /= 10;
				(*(internalv.end() - 1)).push_back(nNumber);
			}
			nNumber = -1;
		}
		else if(str[i] == '}')
			isInNode = false;
		if(isInNode){

			if(isdigit(str[i])){
				if(nNumber == -1){
					nNumber = 0;
				}
				int digit = str[i] - '0';
				nNumber += digit;
				nNumber *= 10;
			}	
		}
	}
	return internalv;
}

void inputEdge(Vertex **nodesArr,Vertex**x,Vertex** y){
	string input;
	cout << "Please enter the nodes of the edge: " << endl;
	getline(cin,input);
	int nNumber = -1;
	Vertex **v = x;
	for(size_t i = 0;i < input.length();++i){
		if(input[i] == ',')
		{
			if(nNumber != -1){
				nNumber /= 10;
				*v = nodesArr[--nNumber];;
				v = y;
			}
			nNumber = -1;
		}
		else{
			if(isdigit(input[i])){
				if(nNumber == -1){
					nNumber = 0;
				}
				int digit = input[i] - '0';
				nNumber += digit;
				nNumber *= 10;
			}
		}
	}
	nNumber /= 10;
	*v = nodesArr[--nNumber];;
}
Vertex **  inputGraph(Graph * g){
	int numberOfNodes;
	cout << "Please enter the number of nodes in the directed graph:" << endl;
	cin >> numberOfNodes;
	Vertex ** nodesArr = new Vertex*[numberOfNodes];
	for(int i = 0; i < numberOfNodes; ++i){
		char * buff= new char[100];
		sprintf(buff,"v%d",i+1);
		nodesArr[i] = new Vertex(buff);
		delete buff;
	}	
	cin.ignore();
	cout << "Please enter the list of neighbors for each node of the graph: " << endl;
	string input;
	getline(cin,input);
	vector<vector<int>> nodes = split(input);
	for(int i =0; i< numberOfNodes ; ++i){
		int numberOfneighbors = nodes[i].size();
		for(int j = 0;j < numberOfneighbors;++j){
			int neighborNodeNumber = nodes[i][j];
			neighborNodeNumber--;
			nodesArr[i]->GetNeighborsPlus()->Add(nodesArr[neighborNodeNumber]);
			nodesArr[neighborNodeNumber]->GetNeighborsMinus()->Add(nodesArr[i]);
		}
		g->addVertex(nodesArr[i]);
	}
	return nodesArr;
}
void inputGraphDebug(Graph * g,Vertex **x,Vertex **y){
	Vertex ** nodesArr = inputGraph(g);
	inputEdge(nodesArr,x,y);
	delete nodesArr;
}

void main(){
	Graph *g = new Graph();
	Vertex *x = NILL,*y = NILL;
	if(DEBUG){
		MaximalPathAlgo mpalgo(g);
		inputGraphDebug(g,&x,&y);
		g->printGraph(cout);
		cout << endl;
		ListVertices * result = mpalgo.FindMaximalPath(x,y);
		result->PrintList(cout);
	}
	else
	{
		Vertex **nodesArr=	inputGraph(g);
		bool quit = false;
		while(!quit){
			inputEdge(nodesArr,&x,&y);
			MaximalPathAlgo * mpalg = new MaximalPathAlgo(g);
			cout << "The output is:" << endl << "(";
			mpalg->FindMaximalPath(x,y)->PrintList(cout);
			cout << ")" << endl;
			int q;
			string input;
			cout << "Do you want to continue (1 - Yes/ 0 - No):" << endl;
			getline(cin,input);
			q = stoi(input);
			quit = true;
			if(q == 1)
				quit = false;
			delete mpalg;
		}
		delete nodesArr;
	}

	delete g;
}