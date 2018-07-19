#pragma once
#include "ListForEachGraphAddNodeToN_V.h"
class ListForEachGraphAddNodeToN_V_MINUS : public ListForEachGraphAddNodeToN_V {
public:
	ListForEachGraphAddNodeToN_V_MINUS(Vertex* v_source): ListForEachGraphAddNodeToN_V(v_source) {}
protected:
	virtual void onMoveFromNeighborGroup() {
		v_source->AddNeighborMinus(getValue()->getValue());
	};
};