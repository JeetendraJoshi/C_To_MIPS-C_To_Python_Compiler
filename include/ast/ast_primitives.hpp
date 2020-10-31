#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>
#include <algorithm>
class Variable
    : public Expression
{
private:
    std::string id;
public:
    Variable(const std::string &_id)
        : id(_id)
    {}

    const std::string getId() const
    { return id; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<id;
    }

    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override
    {
        dst<<id;
        if (n.globaldec){
            bool temp = false;
            for (int i = 0 ; i < globals.size(); i++){
                if (globals[i]== id){
                    temp = true;
                }
            }
            if (!temp){
                globals.push_back(id);
            }
        }
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
       if(n.funcDec == 1){
           dst<< ".globl "<< id<<std::endl;
           dst<< id<<":"<<std::endl;
           n.funcNames.push_back(id);
           //dst<<"addi $sp, $sp, -16"<<std::endl;
           //n.address -= 16; 
           n.funcDec = 0;
           return "$2";
       }
       else if(n.funcDec == 2){
           

           for(int i  =0; i < n.registercounter && i < 4;i++){
               std::string storereg = "$"+std::to_string(i + 4);
               dst<< "addi $8, $sp, "<<(n.registercounter-1-i)*4<<std::endl;
               dst<< "lw "<<storereg<<", 0($8)"<<std::endl;
           }
           
           dst << "jal " << id<<std::endl;
           dst<< "nop"<<std::endl;
           
           for(int i  = 0; i < n.registercounter;i++){
               
             dst << "addi $sp, $sp, 4"<<std::endl;
              n.address += 4; 
           }
           
           return "$2";

       }
       //init decl global and local
       else if(n.funcDec == 5 && n.global){
           dst<< ".globl "<< id<<std::endl;
           dst<< id<<": ";
           n.globals.push_back(id);
        return "$2";

       }
       //enum
       else if(n.funcDec == 10){
           dst<< ".globl "<< id<<std::endl;
           dst<< id<<": ";
           n.globals.push_back(id);
           return "$2";
       }
       //local assign
        else if(n.funcDec == 5 && n.global == false){
         
         n.address -=4;
        dst<< "addi $sp, $sp, -4"<<std::endl; 
         n.vartoadd[id] = n.address;
        

        n.varaddress = n.vartoadd[id] - n.address;
        dst<< "addi $8, $sp, "<<n.varaddress<<std::endl;
        dst<< "lw $2, 0($8)"<<std::endl;
        return "$2";

       }
        //local array assign
  /*  else if(n.funcDec == 7 && !n.global){
        n.address -=4;
        dst<< "addi $sp, $sp, -4"<<std::endl; 
        n.arraytoadd[id] = n.address;
    }*/
       //already assigned
       else{
           if (n.vartoadd.find(id) != n.vartoadd.end()){
                n.varaddress = n.vartoadd[id] - n.address;
                dst<< "addi $8, $sp, "<<n.varaddress<<std::endl;
                dst<< "lw $2, 0($8)"<<std::endl;

           }
           else {
                n.isGlobal = true;
                if(n.leftHand || n.isArray){
                    n.labname = id;
                    dst << "add $2, $zero, $zero"<<std::endl;
                }
                else if(!n.leftHand && !n.isArray){
                   // dst<<"Got here for id "<<id<<std::endl;
                    dst << "lw $2, "<<id<<"($zero)"<<std::endl;
                }
                 

           }

        return "$2";
       }
    }

};

class Number
    : public Expression
{
private:
    double value;
public:
    Number(double _value)
        : value(_value)
    {}

    double getValue() const
    { return value; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<value;
    }

    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override
    {
        dst<<value;
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if(n.global){
            if(n.isArray && !n.isAssign){
                dst << value * 4 << std::endl;
            }
            else if (n.isArray &&  n.isAssign){
                dst <<"";
            }
            else{
                n.result = value;
                if(n.funcDec == 10){
                    n.enumInt = value;
                }
            }
        }
        else{
            if (n.realsize){
              n.result =  value;
            }
            else{
                dst<< "addi $2, $zero, "<<value<<std::endl;
              }
        }
        if (n.casenumber== true){
          n.caseexpressions.push_back(value);
        }
        return "$2";


    }
};


class IntOperator
    : public Expression
{
public:
    IntOperator()
    {}

    virtual void print(std::ostream &dst) const override
    {
        dst<<"int";
    }

    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override
    {
        dst<<"";
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{

        return "";


    }

};


class VoidOperator
    : public Expression
{
public:
    VoidOperator()
    {}

    virtual void print(std::ostream &dst) const override
    {
        dst<<"void";
    }

    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override
    {
        dst<<"";
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{

        return "";


    }

};



#endif
