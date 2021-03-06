#include "JJCProgram.h"
#include <QRegExp>
#include <iostream>
#include <string>
#include "allInstruction.h"

using namespace std;

JJCProgram::JJCProgram(string fileName):Program(fileName), fileName(fileName){
   nbInstruction = 0;
   instructions = new vector<Instruction*>();
   parse();
}

int JJCProgram::getNbInstruction() const
{
    return nbInstruction;
}

void JJCProgram::setNbInstruction(int value)
{
    nbInstruction = value;
}

vector<Instruction*>* JJCProgram::getInstructions() const
{
    return instructions;
}

void JJCProgram::setInstructions(vector<Instruction*>* value)
{
    instructions = value;
}

void JJCProgram::parse(){

    QRegExp regexp;
    ifstream file1(fileName.c_str(), ios_base::in);
    if (file1.is_open()){

            string line;
            while(getline(file1,line)){
		//cout<< line <<endl;
                if(line == "init"){
                    this->instructions->push_back(new InitInstruction("init"));
                    nbInstruction++;
                }

                if(line == "pop"){
                   instructions->push_back(new PopInstruction("pop"));
                   nbInstruction++;

                }
                if(line == "swap"){
                   instructions->push_back(new SwapInstruction("swap"));
                   nbInstruction++;
                }
                if(line == "jcstop"){
                   instructions->push_back(new JCstop("jcstop"));
                   nbInstruction++;

                }
                if(line == "return"){
                   instructions->push_back(new ReturnInstruction("return"));
                   nbInstruction++;

                }
                if(line == "nop"){
                   instructions->push_back(new NopInstruction("nop"));
                   nbInstruction++;

                }
                if(line == "neg"){
                   instructions->push_back(new NegInstruction("neg"));
                   nbInstruction++;
                }
                if(line == "not"){
                   instructions->push_back(new NotInstruction("not"));
                   nbInstruction++;
                }
                if(line == "add"){
                   instructions->push_back(new AddInstruction("add"));
                   nbInstruction++;
                }
                if(line == "sub"){
                   instructions->push_back(new SubInstruction("sub"));
                   nbInstruction++;
                }
                if(line == "mul"){
                   instructions->push_back(new MulInstruction("mul"));
                   nbInstruction++;
                }
                if(line == "div"){
                   instructions->push_back(new DivInstruction("div"));
                   nbInstruction++;
                }
                if(line == "cmp"){
                   instructions->push_back(new CmpInstruction("cmp"));
                   nbInstruction++;
                }
                if(line == "sup"){
                   instructions->push_back(new SupInstruction("sup"));
                   nbInstruction++;
                }
                if(line == "or"){
                   instructions->push_back(new OrInstruction("or"));
                   nbInstruction++;
                }
                if(line == "and"){
                   instructions->push_back(new AndInstruction("and"));
                   nbInstruction++;
                 }
                regexp.setPattern("^push\\(([1-9][0-9]*|0|true|false)\\)$");
                if(QString(line.c_str()).contains(regexp)){
                    int identifier;
                    //ajouter instruction push à la liste;
                    if (regexp.cap(1).toStdString() == "true"){
                        identifier = 1;
                    }
                    else if (regexp.cap(1).toStdString() == "false"){
                        identifier = 0;
                    }
                    else{
                    identifier = regexp.cap(1).toInt();
                    }
                    instructions->push_back(new PushInstruction("push",identifier));
                    nbInstruction++;
                }
                regexp.setPattern("^store\\(([a-zA-Z][a-zA-Z_0-9]*)\\)$");
                if(QString(line.c_str()).contains(regexp)){
                    //ajouter une instruction jstore à la liste
                    string identifier = regexp.cap(1).toStdString();
                    instructions->push_back(new StoreInstruction("store",identifier));
                    nbInstruction++;
                }
                regexp.setPattern("^newarray\\(([a-zA-Z][a-zA-Z_0-9]*),(int|boolean)\\)$");
                if(QString(line.c_str()).contains(regexp)){
                    string ident = regexp.cap(1).toStdString();
                    Type type = stringToType(regexp.cap(2).toStdString());
                    instructions->push_back(new NewArrayInstruction("newarray",ident,type));
                    nbInstruction++;
                }
                regexp.setPattern("^new\\(([a-zA-Z][a-zA-Z_0-9]*),(int|boolean|void),(var|vcst|cst|meth),([1-9][0-9]*|0)\\)$");
                if(QString(line.c_str()).contains(regexp)){
                    //ajouter une instruction new à la liste
		    
                    string identifier = regexp.cap(1).toStdString();
                    Type type = stringToType(regexp.cap(2).toStdString());
                    Kind kind = stringToKind(regexp.cap(3).toStdString());
                    int value = regexp.cap(4).toInt();
                    instructions->push_back(new NewInstruction("new",identifier,type,kind,value));
                    nbInstruction++;
                }
                regexp.setPattern("^load\\(([a-zA-Z][a-zA-Z_0-9]*)\\)$");
                if(QString(line.c_str()).contains(regexp)){
                    string identifier = regexp.cap(1).toStdString();
                    instructions->push_back(new LoadInstruction("load",identifier));
                }
                    regexp.setPattern("^aload\\(([a-zA-Z][a-zA-Z_0-9]*)\\)$");
                    if(QString(line.c_str()).contains(regexp)){
                    //ajouter une instruction aload à la liste
                    string identifier = regexp.cap(1).toStdString();
                    instructions->push_back(new AloadInstruction("aload",identifier));
                    nbInstruction++;
                }
                regexp.setPattern("^astore\\(([a-zA-Z][a-zA-Z_0-9]*)\\)$");
                if(QString(line.c_str()).contains(regexp)){
                    //ajouter une instruction astore à la liste
                    string identifier = regexp.cap(1).toStdString();
                    instructions->push_back(new AstoreInstruction("astore",identifier));
                    nbInstruction++;
                }
                regexp.setPattern("^invoke\\(([a-zA-Z][a-zA-Z_0-9]*)\\)$");
                if(QString(line.c_str()).contains(regexp)){
                    //ajouter une instruction invoke à la liste
                    string identifier = regexp.cap(1).toStdString();
                    instructions->push_back(new InvokeInstruction("invoke",identifier));
                    nbInstruction++;
                }
                regexp.setPattern("^inc\\(([a-zA-Z][a-zA-Z_0-9]*)\\)$");
                if(QString(line.c_str()).contains(regexp)){
                    //ajouter instruction inc à la liste;
                    string identifier = regexp.cap(1).toStdString();
                    instructions->push_back(new IncInstruction("inc",identifier));
                    nbInstruction++;
                }
                regexp.setPattern("^ainc\\(([a-zA-Z][a-zA-Z_0-9]*)\\)$");
                if(QString(line.c_str()).contains(regexp)){
                    //ajouter instruction ainc à la liste;
                    string identifier = regexp.cap(1).toStdString();
                    instructions->push_back(new AIncInstruction("ainc",identifier));
                    nbInstruction++;
                }
                regexp.setPattern("^if\\(([1-9][0-9]*|0)\\)$");
                if(QString(line.c_str()).contains(regexp)){
                    int addr = regexp.cap(1).toInt();
                    instructions->push_back(new IfInstruction("if",addr));
                    nbInstruction++;
                }
                regexp.setPattern("^goto\\(([1-9][0-9]*|0)\\)$");
                if(QString(line.c_str()).contains(regexp)){
                    //ajouter instruction goto à la liste;
                    int addr = regexp.cap(1).toInt();
                    instructions->push_back(new GotoInstruction("goto",addr));
                    nbInstruction++;
                }


            }
     }
}


