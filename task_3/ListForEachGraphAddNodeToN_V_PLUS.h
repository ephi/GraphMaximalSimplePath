#pragma once
#include "ListForEachGraphAddNodeToN_V.h"
class ListForEachGraphAddNodeToN_V_PLUS : public ListForEachGraphAddNodeToN_V {
public:
	ListForEachGraphAddNodeToN_V_PLUS(Vertex* v_source): ListForEachGraphAddNodeToN_V(v_source) {}
protected:
	virtual void onMoveFromNeighborGroup() {
		v_source->AddNeighborPlus(getValue()->getValue());
	};
};