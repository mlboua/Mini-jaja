#include "Memory.h"
#include "VisitInterp.h"
#include "Interpreter.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

VisitInterp::VisitInterp(): compteurMeth(0), compteurClass(0){
	stringToType["BOOLEAN"] = BOOLEAN;
	stringToType["INTEGER"] = INTEGER;
	stringToType["VOID"] = VOID;
}

VisitInterp::~VisitInterp(){}

void VisitInterp::visitAll(ClassNode* root, Memory* mem, int flag){
	//Visite tout les élements de l'arbre
	//string res;
	//Memory* mem = new mem(NULL, 0);


	root->accept(this, mem);
	//cout << res;
}

string VisitInterp::visit(AndNode* c, Memory* mem, int flag) {
	cout <<  "BE CAREFULL : VISIT NOT IMPLEMENTED FOR ANDNODE !\n";
	return "";
}

string VisitInterp::visit(AssignmentNode* assign, Memory* mem, int flag) {
	string identifier = assign->getChildren()[0]->accept(this, mem);
	int value = atoi(assign->getChildren()[1]->accept(this, mem).c_str());
	Interpreter::affecterVal(identifier, value, mem);
	/*
	//push
	mem->push(new Quadruplet("", assign->getChildren()[1]->accept(this, mem)), CST, VOID);
	mem->getAddress(mem->getAddress()+1);
	//store
	int value = mem->top()->getValue();œ
	mem->pop();
	Interpreter::affecterVal(assign->getChildren()[0]->accept(this, mem));

	//*/
	return "";
}

string VisitInterp::visit(BinaryArrayNode* c, Memory* mem, int flag) {
	cout <<  "BE CAREFULL : VISIT NOT IMPLEMENTED FOR BINARYARRAYNODE !\n";
	return "";
}

string VisitInterp::visit(BinaryMinusNode* c, Memory* mem, int flag) {
	int leftChild = atoi(c->getChildren()[0]->accept(this, mem).c_str());
	int rightChild = atoi(c->getChildren()[1]->accept(this, mem).c_str());
	std::ostringstream oss;
	int value = leftChild - rightChild;
	oss << value;
	return oss.str();
}

string VisitInterp::visit(CallENode* c, Memory* mem, int flag) {
	cout <<  "BE CAREFULL : VISIT NOT IMPLEMENTED FOR CALLENODE !\n";
	return "";
}

string VisitInterp::visit(CallINode* c, Memory* mem, int flag) {
	cout <<  "BE CAREFULL : VISIT NOT IMPLEMENTED FOR CALLINODE !\n";
	return "";
}

string VisitInterp::visit(ClassNode* c, Memory* mem, int flag) {
	// []
	mem->setStack(new Stack<Quadruplet*>());

	// DeclVar
	string identifier = c->getChildren()[0]->accept(this, mem);
	Interpreter::declVar(identifier, 0, VOID, mem);

	// dss
	c->getChildren()[1]->accept(this, mem);
	cout << "####################################" << endl;
	cout << "Before main :" << endl;
	cout << "####################################" << endl;
	mem->getStack()->display();

	//mma
	c->getChildren()[2]->accept(this, mem);

	cout << "####################################" << endl;
	cout << "After main :" << endl;
	cout << "####################################" << endl;
	mem->getStack()->display();

	//retrait dss
	c->getChildren()[1]->accept(this, mem, 1);

	cout << "####################################" << endl;
	cout << "Withdrawing :" << endl;
	cout << "####################################" << endl;
	mem->getStack()->display();
	return "";
}

string VisitInterp::visit(CstNode* c, Memory* mem, int flag) {
	return "";
}

string VisitInterp::visit(DeclsNode* decls, Memory* mem, int flag) {
	if(flag == 0){
		if(decls->getLabel() != "") {
			decls->getChildren()[0]->accept(this, mem);
			decls->getChildren()[1]->accept(this, mem);
		}
	}else{
		if(decls->getLabel() != "") {
			decls->getChildren()[0]->accept(this, mem, 1);
			decls->getChildren()[1]->accept(this, mem, 1);
		}
	}
	return "";
}

string VisitInterp::visit(DivideNode* c, Memory* mem, int flag) {
	int leftChild = atoi(c->getChildren()[0]->accept(this, mem).c_str());
	int rightChild = atoi(c->getChildren()[1]->accept(this, mem).c_str());
	std::ostringstream oss;
	int value = leftChild/rightChild;
	oss << value;
	return oss.str();

}

string VisitInterp::visit(EqualityNode* c, Memory* mem, int flag) {
	int leftChild = atoi(c->getChildren()[0]->accept(this, mem).c_str());
	int rightChild = atoi(c->getChildren()[1]->accept(this, mem).c_str());

	if(leftChild == rightChild ) return "true";
	else return "false";

}

string VisitInterp::visit(ExpListNode* c, Memory* mem, int flag) {
	cout <<  "BE CAREFULL : VISIT NOT IMPLEMENTED FOR EXPLISTNODE !\n";
	return "";
}

string VisitInterp::visit(GreaterThanNode* c, Memory* mem, int flag) {
	int leftChild = atoi(c->getChildren()[0]->accept(this, mem).c_str());
	int rightChild = atoi(c->getChildren()[1]->accept(this, mem).c_str());

	if(leftChild > rightChild) return "true";
	else return "false";
}

string VisitInterp::visit(HeaderNode* c, Memory* mem, int flag) {
	cout <<  "BE CAREFULL : VISIT NOT IMPLEMENTED FOR HEADERNODE !\n";
	return "";
}

string VisitInterp::visit(HeadersNode* c, Memory* mem, int flag) {
	cout <<  "BE CAREFULL : VISIT NOT IMPLEMENTED FOR HEADERSNODE !\n";
	return "";
}

string VisitInterp::visit(IdentNode* id, Memory* mem, int flag) {
	string identifier = id->getChildren()[0]->accept(this, mem);
	return identifier;
}

string VisitInterp::visit(IfElseNode* in, Memory* mem, int flag) {
	cout <<  "BE CAREFULL : VISIT NOT IMPLEMENTED FOR IFELSENODENODE !\n";
	return "";
}

string VisitInterp::visit(IfNode* in, Memory* mem, int flag) {
	cout <<  "BE CAREFULL : VISIT NOT IMPLEMENTED FOR IFNODE !\n";
	return "";
}

string VisitInterp::visit(IncrementNode* in, Memory* mem, int flag) {
	string identifier = in->getChildren()[0]->accept(this, mem);
	Interpreter::affecterVal(identifier, Interpreter::val(identifier, mem) + 1, mem);
	return "";
}

string VisitInterp::visit(InstrsNode* iss, Memory* mem, int flag) {
	if(iss->getLabel() != "") {
		iss->getChildren()[0]->accept(this, mem);
		iss->getChildren()[1]->accept(this, mem);
	}
	return "";
}

string VisitInterp::visit(LeafNode* leaf, Memory* mem, int flag) {
	return leaf->getLabel();
}

string VisitInterp::visit(MainNode* main, Memory* mem, int flag) {

	main->getChildren()[0]->accept(this, mem);
	main->getChildren()[1]->accept(this, mem);

	//retrait
	main->getChildren()[0]->accept(this, mem, 1);
	return "";
}

string VisitInterp::visit(MethodNode* in, Memory* mem, int flag) {
	cout <<  "BE CAREFULL : VISIT NOT IMPLEMENTED FOR METHODNODE !\n";
	return "";
}

string VisitInterp::visit(NotNode* in, Memory* mem, int flag) {
	int child = atoi(in->getChildren()[0]->accept(this, mem).c_str());
	if(!child) return "true";
	else return "false";
}

string VisitInterp::visit(NumberNode* num, Memory* mem, int flag) {
	return num->getChildren()[0]->accept(this, mem);
}

string VisitInterp::visit(OrNode* num, Memory* mem, int flag) {
	int leftChild = atoi(num->getChildren()[0]->accept(this, mem).c_str());
	int rightChild = atoi(num->getChildren()[1]->accept(this, mem).c_str());

	return (leftChild || rightChild ) ? "true" : "false";
}

string VisitInterp::visit(PlusNode* num, Memory* mem, int flag) {
	int leftChild;
	int rightChild;

	string leftLabel = num->getChildren()[0]->getLabel();
	string rightLabel = num->getChildren()[1]->getLabel();
	if(leftLabel == "ident"){
		leftChild = Interpreter::val(num->getChildren()[0]->accept(this, mem), mem);
	}else{
		leftChild = atoi(num->getChildren()[0]->accept(this, mem).c_str());
	}
	if(rightLabel == "ident"){
		rightChild = Interpreter::val(num->getChildren()[1]->accept(this, mem), mem);
	}else{
		rightChild = atoi(num->getChildren()[1]->accept(this, mem).c_str());
	}

	std::ostringstream oss;
	int value = leftChild+rightChild;
	cout << "VALUE : " << value << endl;
	oss << value;
	return oss.str();
}

string VisitInterp::visit(ReturnNode* num, Memory* mem, int flag) {
	cout <<  "BE CAREFULL : VISIT NOT IMPLEMENTED FOR RETURNNODE !\n";
	return "";
}

string VisitInterp::visit(SumNode* num, Memory* mem, int flag) {
	cout <<  "BE CAREFULL : VISIT NOT IMPLEMENTED FOR SUMNODE !\n";
	return "";
}

string VisitInterp::visit(TernaryArrayNode* num, Memory* mem, int flag) {
	cout <<  "BE CAREFULL : VISIT NOT IMPLEMENTED FOR TERNARYARRAYNODE !\n";
	return "";
}

string VisitInterp::visit(TimesNode* num, Memory* mem, int flag) {
	int leftChild = atoi(num->getChildren()[0]->accept(this, mem).c_str());
	int rightChild = atoi(num->getChildren()[1]->accept(this, mem).c_str());

	std::ostringstream oss;
	int value = leftChild*rightChild;
	oss << value;
	return oss.str();
	return "";
}

string VisitInterp::visit(UnaryMinusNode* num, Memory* mem, int flag) {
	int leftChild = atoi(num->getChildren()[0]->accept(this, mem).c_str());
	std::ostringstream oss;
	int value = -leftChild;
	oss << value;
	return oss.str();
}

string VisitInterp::visit(VarNode* v, Memory* mem, int flag) {
	string identifier;
	int value;
	Type type;

    cout << "LOOLS" << endl;

	if(flag == 0){
		identifier = v->getChildren()[1]->accept(this, mem);            //identifier
		type = stringToType[v->getChildren()[0]->accept(this, mem)];                  //type

		if(v->getChildren()[2]->getChildren() != NULL){
			value = atoi(v->getChildren()[2]->accept(this, mem).c_str());   // value
			Interpreter::declVar(identifier, value, type, mem);     //mem
			//*/
		}else{
			value = 0;
			Interpreter::declVar(identifier, value, type, mem);     //mem
			//*/
		}
	}else{
		/*identifier = v->getChildren()[1]->accept(this, mem);            //identifier
		  type = stringToType[v->getChildren()[0]->accept(this, mem)];                  //type

		  if(v->getChildren()[2]->getChildren() != NULL){
		  value = atoi(v->getChildren()[2]->accept(this, mem).c_str());   // value

		  Interpreter::retraitVar(identifier,
		  value,
		  type,
		  mem);     //mem
		//*/
		/*}else{

		  Interpreter::retraitVar(identifier,
		  value,
		  type,
		  mem);    //mem
		//*/
		//}
	}
	return "";
}

string VisitInterp::visit(VarsNode* v, Memory* mem, int flag) {
	if(flag == 0){
		if(v->getLabel() != ""){
			v->getChildren()[0]->accept(this, mem);
			v->getChildren()[1]->accept(this, mem);
		}
	}else{
		if(v->getLabel() != ""){
			v->getChildren()[0]->accept(this, mem, 1);
			v->getChildren()[1]->accept(this, mem, 1);
		}
	}
	return "";
}

string VisitInterp::visit(WhileNode* num, Memory* mem, int flag) {
	cout <<  "BE CAREFULL : VISIT NOT IMPLEMENTED FOR WHILENODE !\n";
	return "";
}

