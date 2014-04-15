#ifndef ANDNODE_H
#define ANDNODE_H

#include "Node.h"
class VisitComp;
class VisitInterp;
class Memory;

class AndNode: public Node{

    public:
        AndNode(Node* child1, Node* child2);
        ~AndNode();
        virtual std::string accept(VisitComp* v, int flag=0);
        virtual string accept(VisitInterp* v, Memory* mem, int flag=0);

};

#endif 
