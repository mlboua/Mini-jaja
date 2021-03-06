#include "ExpListNode.h"
#include "VisitComp.h"
#include "VisitInterp.h"

ExpListNode::ExpListNode(Node* child1, Node* child2): Node("explist",  2){
    appendChild(child1);
    appendChild(child2);
}

ExpListNode::~ExpListNode(){}

string ExpListNode::accept(VisitComp* v, int flag){
    return v->visit(this, flag);
}

string ExpListNode::accept(VisitInterp* v, Memory* mem, int flag){
    return v->visit(this, mem, flag);
}

