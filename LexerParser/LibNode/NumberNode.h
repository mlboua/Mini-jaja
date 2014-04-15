#ifndef NUMBERNODE_H
#define NUMBERNODE_H

#include "Node.h"
class VisitComp;

class NumberNode: public Node{

	public:
		NumberNode(Node* child1);
		~NumberNode();
		virtual std::string accept(VisitComp* v);

};

#endif 
