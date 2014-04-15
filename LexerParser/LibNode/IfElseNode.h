#ifndef IFELSENODE_H
#define IFELSENODE_H

#include "Node.h"
class VisitComp;

class IfElseNode: public Node{

	public:
		IfElseNode(Node* child1, Node* child2, Node* child3);
		~IfElseNode();
		virtual std::string accept(VisitComp* v);

};

#endif 
