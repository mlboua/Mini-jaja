#include "IfElseNode.h"
#include "VisitComp.h"

IfElseNode::IfElseNode(Node* child1, Node* child2, Node* child3): Node("ifelse",  3){
	appendChild(child1);
	appendChild(child2);
	appendChild(child3);
}

IfElseNode::~IfElseNode(){}

string IfElseNode::accept(VisitComp* v){
	return v->visit(this);
}
