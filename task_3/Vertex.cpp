#pragma warning(disable:4996) 
#include "Vertex.h"
Vertex::~Vertex(){
	if(N_V_MINUS != NILL)
		delete N_V_MINUS;
	if(N_V_PLUS != NILL)
		delete N_V_PLUS;
	if(pi != NILL)
		delete pi;
	this->name.erase();
}
Vertex* Vertex::clone(bool isShallowClone){
	char * c = new char();
	this->name.copy(c,this->name.size(),0);
	Vertex* cloned = new Vertex(c);
	cloned->color = this->color;
	ListVertices * lvN_V_Minus = this->N_V_MINUS;
	ListVertices * lvN_V_Plus = this->N_V_PLUS;
	if(!isShallowClone)
	{
	  lvN_V_Minus = (ListVertices*)(this->N_V_MINUS->clone());
	  lvN_V_Plus = (ListVertices*)(this->N_V_PLUS->clone());
	}

	cloned->N_V_MINUS = lvN_V_Minus;
	cloned->N_V_PLUS = lvN_V_Plus;
	return cloned;
}

ListVertices * Vertex::GetNeighborsPlus() {
	if(this->N_V_PLUS == NILL)
		this->N_V_PLUS = new ListVertices();
	return this->N_V_PLUS;
}
void Vertex::AddNeighborPlus(Vertex* v){
	if(N_V_PLUS == NILL)
		N_V_PLUS = new ListVertices();	
	N_V_PLUS->Add(v);
}

ListVertices * Vertex::GetNeighborsMinus() {
	if(this->N_V_MINUS == NILL)
		this->N_V_MINUS = new ListVertices();
	return this->N_V_MINUS;
}
void Vertex::AddNeighborMinus(Vertex* v){
	if(N_V_MINUS == NILL)
		N_V_MINUS = new ListVertices();	
	N_V_MINUS->Add(v);
}