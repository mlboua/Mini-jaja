#include "IfNode.h"
#include "VisitComp.h"

IfNode::IfNode(Node* child1, Node* child2): Node("if",  2){
	appendChild(child1);
	appendChild(child2);
}

IfNode::~IfNode(){}

string IfNode::accept(VisitComp* v){
	return v->visit(this);
}
