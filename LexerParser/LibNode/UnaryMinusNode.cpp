#include "UnaryMinusNode.h"
#include "VisitComp.h"

UnaryMinusNode::UnaryMinusNode(Node* child1): Node("unaryminus",  1){
	appendChild(child1);
}

UnaryMinusNode::~UnaryMinusNode(){}

string UnaryMinusNode::accept(VisitComp* v){
	return v->visit(this);
}
