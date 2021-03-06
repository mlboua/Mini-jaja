#ifndef QUADRUPLET_H
#define QUADRUPLET_H

#include <fstream>
#include <map>

typedef enum Kind{CST, VCST, VAR} Kind;
typedef enum Type{BOOLEAN, INTEGER, VOID} Type;

class Quadruplet{

    public:
        Quadruplet(const std::string identifier, const int value, const Kind kind, const Type type): identifier(identifier), value(value), kind(kind), type(type){}
        
        Quadruplet(const Quadruplet* quadruplet): identifier(quadruplet->getIdentifier()), value(quadruplet->getValue()), kind(quadruplet->getKind()), type(quadruplet->getType()){}

        std::string getIdentifier() const{
            return identifier;
        }

        int getValue() const{
            return value;
        }

        Type getType() const{
            return type;
        }

        Kind getKind() const{
            return kind;
        }

        void setValue(const int value){
            this->value = value;
        }

        void setKind(const Kind kind){
            this->kind = kind;
        }

        friend std::ostream& operator<<(std::ostream& os, const Quadruplet& quadruplet);

    private:
        std::string identifier;
        int value;
        Kind kind;
        Type type;

};

#endif
