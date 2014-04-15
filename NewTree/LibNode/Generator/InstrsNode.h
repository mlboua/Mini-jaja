#ifndef INSTRSNODE_H
#define INSTRSNODE_H

#include "Node.h"
class VisitComp;
class VisitInterp;

class InstrsNode: public Node{

	public:
		InstrsNode(Node* child1, Node* child2);
		~InstrsNode();
		virtual std::string accept(VisitComp* v);
		virtual string accept(VisitInterp* v);

};

#endif 
