#pragma once
#include "Node.h"
template<typename T>
class ListForEach  {
public:
	T* getValue() const {
	  return value;
	}
	void setSizeOfList(int *size){
		this->sizeOfList = size;
	}
	void setValue(T* value){
		this->value = value;
	}
	void setTreeRoot(T **treeRoot){
		this->treeRoot = treeRoot;
	}
	void operator()(){
		onForEachListExecute();
	}
	virtual void onEmptyList(){};
	virtual void onNonEmptyList(){};
protected:
	virtual void onForEachListExecute() = 0;
	T *value;
	T **treeRoot;
	int *sizeOfList;
};