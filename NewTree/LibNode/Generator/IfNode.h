#ifndef IFNODE_H
#define IFNODE_H

#include "Node.h"
class VisitComp;
class VisitInterp;

class IfNode: public Node{

	public:
		IfNode(Node* child1, Node* child2);
		~IfNode();
		virtual std::string accept(VisitComp* v);
		virtual string accept(VisitInterp* v);

};

#endif 
