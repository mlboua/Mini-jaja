#include "VarsNode.h"
#include "VisitComp.h"

VarsNode::VarsNode(Node* child1, Node* child2): Node("vars",  2){
	appendChild(child1);
	appendChild(child2);
}

VarsNode::~VarsNode(){}

string VarsNode::accept(VisitComp* v){
	return v->visit(this);
}
