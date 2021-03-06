#ifndef GREATERTHANNODE_H
#define GREATERTHANNODE_H

#include "Node.h"
class VisitComp;
class VisitInterp;

class GreaterThanNode: public Node{

	public:
		GreaterThanNode(Node* child1, Node* child2);
		~GreaterThanNode();
		virtual std::string accept(VisitComp* v);
		virtual string accept(VisitInterp* v);

};

#endif 
