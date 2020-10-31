#ifndef ast_operators_hpp
#define ast_operators_hpp

#include <string>
#include <iostream>
#include <cmath>

class AddOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    AddOperator(ExpressionPtr _left, ExpressionPtr _right)
       : left(_left)
       , right(_right)
    {}
    virtual ~AddOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }
    
    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<<" ";
        dst<<"+";
        dst<<" ";
        right->printpython(dst, n, globals);
    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result = x+n.result;
            return "$2";
        }
        left->printmips(dst, n, globals);
        storeStack(dst,n,"$2");
        right->printmips(dst, n, globals);
        retrieveStack(dst,n,"$9");
        dst<< "addu $2 , $9, $2" <<std::endl;
        return "$2";
        

    }

};


class SubOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    SubOperator(ExpressionPtr _left, ExpressionPtr _right)
       : left(_left)
       , right(_right)
    {}
    virtual ~SubOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }
    
    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<<" ";
        dst<<"-";
        dst<<" ";
        right->printpython(dst, n, globals);
    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result = x-n.result;
            return "$2";
        }
        left->printmips(dst, n, globals);
        storeStack(dst,n,"$2");
        right->printmips(dst, n, globals);
        retrieveStack(dst,n,"$9");
        dst<< "subu $2 , $9, $2" <<std::endl;
        return "$2";

    }

};



class MulOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    MulOperator(ExpressionPtr _left, ExpressionPtr _right)
       : left(_left)
       , right(_right)
    {}
    virtual ~MulOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }
    
    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<<" ";
        dst<<"*";
        dst<<" ";
        right->printpython(dst, n, globals);
    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result = x*n.result;
            return "$2";
        }
        left->printmips(dst, n, globals);
        storeStack(dst, n, "$2");
        right->printmips(dst, n, globals);
        retrieveStack(dst, n, "$9");
        dst<< "multu $2, $9"<<std::endl;
        dst<< "mflo $2"<<std::endl;
        return "$2";
    }

};

class DivOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    DivOperator(ExpressionPtr _left, ExpressionPtr _right)
       : left(_left)
       , right(_right)
    {}
    virtual ~DivOperator()
    {
        delete left;
        delete right;
    }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result = x/n.result;
            return "$2";
        }
        left->printmips(dst, n, globals);
        storeStack(dst, n, "$2");
        right->printmips(dst, n, globals);
        retrieveStack(dst, n, "$9");
        dst<< "divu $9, $2"<<std::endl;
        dst<< "mflo $2"<<std::endl;
        return "$2";


    }

};


class ModuloOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    ModuloOperator(ExpressionPtr _left, ExpressionPtr _right)
       : left(_left)
       , right(_right)
    {}
    virtual ~ModuloOperator()
    {
        delete left;
        delete right;
    }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result = x%n.result;
            return "$2";
        }
        left->printmips(dst, n, globals);
        storeStack(dst, n, "$2");
        right->printmips(dst, n, globals);
        retrieveStack(dst, n, "$9");
        dst<< "divu $9, $2"<<std::endl;
        dst<< "mfhi $2"<<std::endl;
        return "$2";


    }

};
class PreIncrementOperator
    : public Expression
{
private:
    ExpressionPtr left;
public:
    PreIncrementOperator(ExpressionPtr _left)
       : left(_left)
    {}
    virtual ~PreIncrementOperator()
    {
        delete left;
    }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        n.leftHand = true;
        n.findSize = false;
        n.isArray = false;
        n.isGlobal = false;
        left->printmips(dst, n, globals);
        n.leftHand = false;
        if(n.isGlobal){
            n.isGlobal = false;
            std::string id = n.labname;
            storeStack(dst, n, "$2");
            left->printmips(dst, n, globals);
            dst<< "addiu $2, $2, 1"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, "<<id<<"($8)"<<std::endl;
        }
        else{

        
        if(n.findSize){
            n.isArray = false;
            n.findSize = false;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            dst<< "addiu $2, $2, 1"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
            
            
        }
        else{
            dst<< "addi $2, $sp, "<<n.varaddress<<std::endl;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            dst<< "addiu $2, $2, 1"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
        }
        }
        return "$2";

    }

};

class PreDecrementOperator
    : public Expression
{
private:
    ExpressionPtr left;
public:
    PreDecrementOperator(ExpressionPtr _left)
       : left(_left)
    {}
    virtual ~PreDecrementOperator()
    {
        delete left;
    }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{

        n.leftHand = true;
        n.findSize = false;
        n.isArray = false;
        n.isGlobal = false;
        left->printmips(dst, n, globals);
        n.leftHand = false;
        if(n.isGlobal){
            n.isGlobal = false;
            std::string id = n.labname;
            storeStack(dst, n, "$2");
            left->printmips(dst, n, globals);
            dst<< "addiu $2, $2, -1"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, "<<id<<"($8)"<<std::endl;
        }
        else{

        
        if(n.findSize){
            n.isArray = false;
            n.findSize = false;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            dst<< "addiu $2, $2, -1"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
            
            
        }
        else{
            dst<< "addi $2, $sp, "<<n.varaddress<<std::endl;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            dst<< "addiu $2, $2, -1"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
        }
        }
        return "$2";

    }

};

class PostIncrementOperator
    : public Expression
{
private:
    ExpressionPtr left;
public:
    PostIncrementOperator(ExpressionPtr _left)
       : left(_left)
    {}
    virtual ~PostIncrementOperator()
    {
        delete left;
    }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{

         n.leftHand = true;
        n.findSize = false;
        n.isArray = false;
        n.isGlobal = false;
        left->printmips(dst, n, globals);
        n.leftHand = false;
        if(n.isGlobal){
            n.isGlobal = false;
            std::string id = n.labname;
            storeStack(dst, n, "$2");
            left->printmips(dst, n, globals);
            dst<< "addiu $10, $2, 1"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $10, "<<id<<"($8)"<<std::endl;
        }
        else{

        
        if(n.findSize){
            n.isArray = false;
            n.findSize = false;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            dst<< "addiu $10, $2, 1"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $10, 0($8)"<<std::endl;
            
            
        }
        else{
            dst<< "addi $2, $sp, "<<n.varaddress<<std::endl;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            dst<< "addiu $10, $2, 1"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $10, 0($8)"<<std::endl;
        }
        }
        return "$2";

    }

};



class PostDecrementOperator
    : public Expression
{
private:
    ExpressionPtr left;
public:
    PostDecrementOperator(ExpressionPtr _left)
       : left(_left)
    {}
    virtual ~PostDecrementOperator()
    {
        delete left;
    }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{

         n.leftHand = true;
        n.findSize = false;
        n.isArray = false;
        n.isGlobal = false;
        left->printmips(dst, n, globals);
        n.leftHand = false;
        if(n.isGlobal){
            n.isGlobal = false;
            std::string id = n.labname;
            storeStack(dst, n, "$2");
            left->printmips(dst, n, globals);
            dst<< "addiu $10, $2, -1"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $10, "<<id<<"($8)"<<std::endl;
        }
        else{

        
        if(n.findSize){
            n.isArray = false;
            n.findSize = false;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            dst<< "addiu $10, $2, -1"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $10, 0($8)"<<std::endl;
            
            
        }
        else{
            dst<< "addi $2, $sp, "<<n.varaddress<<std::endl;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            dst<< "addiu $10, $2, -1"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $10, 0($8)"<<std::endl;
        }
        }
        return "$2";
    }

    

};

class AddressOperator
    : public Expression
{
private:
    ExpressionPtr left;
public:
    AddressOperator(ExpressionPtr _left)
       : left(_left)
    {}
    virtual ~AddressOperator()
    {
        delete left;
    }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        left->printmips(dst, n, globals);
        dst<< "addi $2, $sp, "<< n.varaddress<<std::endl;
        return "$2";

    }

};

class MultEqualsOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    MultEqualsOperator(ExpressionPtr _left, ExpressionPtr _right)
       : left(_left)
       , right(_right)
    {}
    virtual ~MultEqualsOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{


           n.leftHand = true;
        n.findSize = false;
        n.isArray = false;
        n.isGlobal = false;
        getLeft()->printmips(dst, n, globals);
        n.leftHand = false;
        if(n.isGlobal){
            n.isGlobal = false;
            std::string id = n.labname;
            storeStack(dst, n, "$2");
            getLeft()->printmips(dst, n, globals);
            storeStack(dst, n, "$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n,"$8");
                  dst<< "mult $2, $8"<<std::endl;
        dst<< "mflo $2"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, "<<id<<"($8)"<<std::endl;
        }
        else{

        
        if(n.findSize){
            n.isArray = false;
            n.findSize = false;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "mult $2, $8"<<std::endl;
        dst<< "mflo $2"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
            
            
        }
        else{
            dst<< "addi $2, $sp, "<<n.varaddress<<std::endl;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "mult $2, $8"<<std::endl;
        dst<< "mflo $2"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
        }
        }
        return "$2";

    }

};

class DivEqualsOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    DivEqualsOperator(ExpressionPtr _left, ExpressionPtr _right)
       : left(_left)
       , right(_right)
    {}
    virtual ~DivEqualsOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{

        n.leftHand = true;
        n.findSize = false;
        n.isArray = false;
        n.isGlobal = false;
        getLeft()->printmips(dst, n, globals);
        n.leftHand = false;
        if(n.isGlobal){
            n.isGlobal = false;
            std::string id = n.labname;
            storeStack(dst, n, "$2");
            getLeft()->printmips(dst, n, globals);
            storeStack(dst, n, "$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n,"$8");
           dst<< "divu $8, $2"<<std::endl;
            dst<< "mflo $2"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, "<<id<<"($8)"<<std::endl;
        }
        else{

        
        if(n.findSize){
            n.isArray = false;
            n.findSize = false;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "divu $8, $2"<<std::endl;
            dst<< "mflo $2"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
            
            
        }
        else{
            dst<< "addi $2, $sp, "<<n.varaddress<<std::endl;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "divu $8, $2"<<std::endl;
            dst<< "mflo $2"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
        }
        }
        return "$2";



    }

};

class ModuloEqualsOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    ModuloEqualsOperator(ExpressionPtr _left, ExpressionPtr _right)
       : left(_left)
       , right(_right)
    {}
    virtual ~ModuloEqualsOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{

        n.leftHand = true;
        n.findSize = false;
        n.isArray = false;
        n.isGlobal = false;
        getLeft()->printmips(dst, n, globals);
        n.leftHand = false;
        if(n.isGlobal){
            n.isGlobal = false;
            std::string id = n.labname;
            storeStack(dst, n, "$2");
            getLeft()->printmips(dst, n, globals);
            storeStack(dst, n, "$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n,"$8");
            dst<< "divu $2, $8"<<std::endl;
            dst<< "mfhi $2"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, "<<id<<"($8)"<<std::endl;
        }
        else{

        
        if(n.findSize){
            n.isArray = false;
            n.findSize = false;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "divu $2, $8"<<std::endl;
            dst<< "mfhi $2"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
            
            
        }
        else{
            dst<< "addi $2, $sp, "<<n.varaddress<<std::endl;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "divu $2, $8"<<std::endl;
            dst<< "mfhi $2"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
        }
        }
        return "$2";

    }

};

class PlusEqualsOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    PlusEqualsOperator(ExpressionPtr _left, ExpressionPtr _right)
       : left(_left)
       , right(_right)
    {}
    virtual ~PlusEqualsOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{

         n.leftHand = true;
        n.findSize = false;
        n.isArray = false;
        n.isGlobal = false;
        getLeft()->printmips(dst, n, globals);
        n.leftHand = false;
        if(n.isGlobal){
            n.isGlobal = false;
            std::string id = n.labname;
            storeStack(dst, n, "$2");
            getLeft()->printmips(dst, n, globals);
            storeStack(dst, n, "$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n,"$8");
            dst<< "addu $2, $2, $8"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, "<<id<<"($8)"<<std::endl;
        }
        else{

        
        if(n.findSize){
            n.isArray = false;
            n.findSize = false;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "addu $2, $2, $8"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
            
            
        }
        else{
            dst<< "addi $2, $sp, "<<n.varaddress<<std::endl;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "addu $2, $2, $8"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
        }
        }
        return "$2";
    }

};

class SubEqualsOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    SubEqualsOperator(ExpressionPtr _left, ExpressionPtr _right)
       : left(_left)
       , right(_right)
    {}
    virtual ~SubEqualsOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{


        n.leftHand = true;
        n.findSize = false;
        n.isArray = false;
        n.isGlobal = false;
        getLeft()->printmips(dst, n, globals);
        n.leftHand = false;
        if(n.isGlobal){
            n.isGlobal = false;
            std::string id = n.labname;
            storeStack(dst, n, "$2");
            getLeft()->printmips(dst, n, globals);
            storeStack(dst, n, "$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n,"$8");
            dst<< "subu $2, $8, $2"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, "<<id<<"($8)"<<std::endl;
        }
        else{

        
        if(n.findSize){
            n.isArray = false;
            n.findSize = false;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "subu $2, $8, $2"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
            
            
        }
        else{
            dst<< "addi $2, $sp, "<<n.varaddress<<std::endl;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "subu $2, $8, $2"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
        }
        }
        return "$2";

    }

};

class LeftShiftEqualsOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    LeftShiftEqualsOperator(ExpressionPtr _left, ExpressionPtr _right)
       : left(_left)
       , right(_right)
    {}
    virtual ~LeftShiftEqualsOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        int z = n.labelcounter +1;
        n.labelcounter+=1;
        n.leftHand = true;
        n.findSize = false;
        n.isArray = false;
        n.isGlobal = false;
        getLeft()->printmips(dst, n, globals);
        n.leftHand = false;
        if(n.isGlobal){
            n.isGlobal = false;
            std::string id = n.labname;
            storeStack(dst, n, "$2");
            getLeft()->printmips(dst, n, globals);
            storeStack(dst, n, "$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n,"$8");
            dst<< "leftshifteq"<<z<<":"<<std::endl;
        dst<< "beq $2, $zero, leftshifteqend"<<z<<std::endl;
        dst<< "addi $2, $2, -1"<<std::endl;
        dst<< "sll $8, $8, 1"<<std::endl;
        dst<< "j leftshifteq"<<z<<std::endl;
        dst<< "leftshifteqend"<<z<<":"<<std::endl;
        dst<< "add $2, $8, $zero"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, "<<id<<"($8)"<<std::endl;
        }
        else{

        
        if(n.findSize){
            n.isArray = false;
            n.findSize = false;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "leftshifteq"<<z<<":"<<std::endl;
        dst<< "beq $2, $zero, leftshifteqend"<<z<<std::endl;
        dst<< "addi $2, $2, -1"<<std::endl;
        dst<< "sll $8, $8, 1"<<std::endl;
        dst<< "j leftshifteq"<<z<<std::endl;
        dst<< "leftshifteqend"<<z<<":"<<std::endl;
        dst<< "add $2, $8, $zero"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
            
            
        }
        else{
            dst<< "addi $2, $sp, "<<n.varaddress<<std::endl;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "leftshifteq"<<z<<":"<<std::endl;
        dst<< "beq $2, $zero, leftshifteqend"<<z<<std::endl;
        dst<< "addi $2, $2, -1"<<std::endl;
        dst<< "sll $8, $8, 1"<<std::endl;
        dst<< "j leftshifteq"<<z<<std::endl;
        dst<< "leftshifteqend"<<z<<":"<<std::endl;
        dst<< "add $2, $8, $zero"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
        }
        }
        return "$2";
    }

};

class RightShiftEqualsOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    RightShiftEqualsOperator(ExpressionPtr _left, ExpressionPtr _right)
       : left(_left)
       , right(_right)
    {}
    virtual ~RightShiftEqualsOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        int z = n.labelcounter +1;
        n.labelcounter+=1;
        n.leftHand = true;
        n.findSize = false;
        n.isArray = false;
        n.isGlobal = false;
        getLeft()->printmips(dst, n, globals);
        n.leftHand = false;
        if(n.isGlobal){
            n.isGlobal = false;
            std::string id = n.labname;
            storeStack(dst, n, "$2");
            getLeft()->printmips(dst, n, globals);
            storeStack(dst, n, "$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n,"$8");
            dst<< "rightshifteq"<<z<<":"<<std::endl;
        dst<< "beq $2, $zero, rightshifteqend"<<z<<std::endl;
        dst<< "addi $2, $2, -1"<<std::endl;
        dst<< "srl $8, $8, 1"<<std::endl;
        dst<< "j rightshifteq"<<z<<std::endl;
        dst<< "rightshifteqend"<<z<<":"<<std::endl;
        dst<< "add $2, $8, $zero"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, "<<id<<"($8)"<<std::endl;
        }
        else{

        
        if(n.findSize){
            n.isArray = false;
            n.findSize = false;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "rightshifteq"<<z<<":"<<std::endl;
        dst<< "beq $2, $zero, rightshifteqend"<<z<<std::endl;
        dst<< "addi $2, $2, -1"<<std::endl;
        dst<< "srl $8, $8, 1"<<std::endl;
        dst<< "j rightshifteq"<<z<<std::endl;
        dst<< "rightshifteqend"<<z<<":"<<std::endl;
        dst<< "add $2, $8, $zero"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
            
            
        }
        else{
            dst<< "addi $2, $sp, "<<n.varaddress<<std::endl;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "rightshifteq"<<z<<":"<<std::endl;
        dst<< "beq $2, $zero, rightshifteqend"<<z<<std::endl;
        dst<< "addi $2, $2, -1"<<std::endl;
        dst<< "srl $8, $8, 1"<<std::endl;
        dst<< "j rightshifteq"<<z<<std::endl;
        dst<< "rightshifteqend"<<z<<":"<<std::endl;
        dst<< "add $2, $8, $zero"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
        }
        }
        return "$2";

    }

};

class AndEqualsOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    AndEqualsOperator(ExpressionPtr _left, ExpressionPtr _right)
       : left(_left)
       , right(_right)
    {}
    virtual ~AndEqualsOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{


         n.leftHand = true;
        n.findSize = false;
        n.isArray = false;
        n.isGlobal = false;
        getLeft()->printmips(dst, n, globals);
        n.leftHand = false;
        if(n.isGlobal){
            n.isGlobal = false;
            std::string id = n.labname;
            storeStack(dst, n, "$2");
            getLeft()->printmips(dst, n, globals);
            storeStack(dst, n, "$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n,"$8");
            dst<< "and $2, $2, $8"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, "<<id<<"($8)"<<std::endl;
        }
        else{

        
        if(n.findSize){
            n.isArray = false;
            n.findSize = false;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "and $2, $2, $8"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
            
            
        }
        else{
            dst<< "addi $2, $sp, "<<n.varaddress<<std::endl;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "and $2, $2, $8"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
        }
        }
        return "$2";

    }

};

class CondExprOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr middle;
    ExpressionPtr right;
public:
    CondExprOperator(ExpressionPtr _left, ExpressionPtr _middle , ExpressionPtr _right)
       : left(_left)
       , middle(_middle)
       , right(_right)
    {}
    virtual ~CondExprOperator()
    {
        delete left;
        delete middle;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getMiddle() const
    { return middle; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
         if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            middle->printmips(dst, n, globals);
            int y = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result = x? y : n.result;
            return "$2";
        }
        int z = n.labelcounter+1;
        n.labelcounter++;
        getLeft()->printmips(dst, n, globals);
        dst<< "beq $2 , $0, condexprf"<<z<<std::endl;
        dst<< "bne $2 , $0, condexprt"<<z<<std::endl;
        dst<<"condexprf"<<z<<":"<<std::endl;
        getRight()->printmips(dst, n, globals);
        dst<<"beq $0, $0, condexprtend"<<z<<std::endl;
        dst<< "condexprt"<<z<<":"<<std::endl;
        getMiddle()-> printmips(dst, n, globals);
        dst<<"condexprtend"<<z<<":"<<std::endl;
        return "$2";

    }

};

class XorEqualsOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    XorEqualsOperator(ExpressionPtr _left, ExpressionPtr _right)
       : left(_left)
       , right(_right)
    {}
    virtual ~XorEqualsOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{


        n.leftHand = true;
        n.findSize = false;
        n.isArray = false;
        n.isGlobal = false;
        getLeft()->printmips(dst, n, globals);
        n.leftHand = false;
        if(n.isGlobal){
            n.isGlobal = false;
            std::string id = n.labname;
            storeStack(dst, n, "$2");
            getLeft()->printmips(dst, n, globals);
            storeStack(dst, n, "$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n,"$8");
            dst<< "xor $2, $2, $8"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, "<<id<<"($8)"<<std::endl;
        }
        else{

        
        if(n.findSize){
            n.isArray = false;
            n.findSize = false;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "xor $2, $2, $8"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
            
            
        }
        else{
            dst<< "addi $2, $sp, "<<n.varaddress<<std::endl;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "xor $2, $2, $8"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
        }
        }
        return "$2";

    }

};

class OrEqualsOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    OrEqualsOperator(ExpressionPtr _left, ExpressionPtr _right)
       : left(_left)
       , right(_right)
    {}
    virtual ~OrEqualsOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        

        n.leftHand = true;
        n.findSize = false;
        n.isArray = false;
        n.isGlobal = false;
        getLeft()->printmips(dst, n, globals);
        n.leftHand = false;
        if(n.isGlobal){
            n.isGlobal = false;
            std::string id = n.labname;
            storeStack(dst, n, "$2");
            getLeft()->printmips(dst, n, globals);
            storeStack(dst, n, "$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n,"$8");
            dst<< "or $2, $2, $8"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, "<<id<<"($8)"<<std::endl;
        }
        else{

        
        if(n.findSize){
            n.isArray = false;
            n.findSize = false;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "or $2, $2, $8"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
            
            
        }
        else{
            dst<< "addi $2, $sp, "<<n.varaddress<<std::endl;
            storeStack(dst, n, "$2");
            dst<< "lw $2, 0($2)"<<std::endl;
            storeStack(dst,n,"$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n , "$8");
            dst<< "or $2, $2, $8"<<std::endl;
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
        }
        }
        return "$2";

    }

};

class LessThanOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    LessThanOperator(ExpressionPtr _left, ExpressionPtr _right)
       : left(_left)
       , right(_right)
    {}
    virtual ~LessThanOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }
        virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<<" ";
        dst<<"<";
        dst<<" ";
        right->printpython(dst, n, globals);
    }


    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result = x<n.result;
            return "$2";
        }
        left->printmips(dst, n, globals);
        storeStack(dst, n, "$2");
        right->printmips(dst, n, globals);
        retrieveStack(dst, n, "$9");
        dst<< "slt $2, $9, $2"<<std::endl;
        return "$2";

    }

};


class CondEqualsOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    CondEqualsOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~CondEqualsOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<<" ";
        dst<<"==";
        dst<<" ";
        right->printpython(dst, n, globals);
    }


    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result =x==n.result;
            return "$2";
        }
        int z = n.labelcounter+1;
        n.labelcounter+=1;
        std::string leftstring = left->printmips(dst, n, globals);
        storeStack(dst, n,"$2");
        std::string rightstring = right->printmips(dst, n, globals);
        retrieveStack(dst, n, "$9");
        dst<< "addu $10, $zero, $2 "<<std::endl;
        dst<< "add $2, $0, $0"<<std::endl;
        dst<< "bne $10, $9, condequals"<<z<<std::endl;
        dst<< "addi $2, $zero, 1"<<std::endl;
        dst<< "condequals"<<z<<":"<<std::endl;
        return "$2";

    }

};

class LogAndOperator
: public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    LogAndOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~LogAndOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<<" ";
        dst<<"and";
        dst<<" ";
        right->printpython(dst, n, globals);
    }


    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result = x&&n.result;
            return "$2";
        }
        int z = n.labelcounter+1;
        n.labelcounter+=1;
        left->printmips(dst, n, globals);
        dst<< "beq $zero, $2, endand"<<z<<std::endl;
        right->printmips(dst, n, globals);
        dst<< "beq $zero, $2, endand"<<z<<std::endl;
        dst<< "addi $2, $zero, 1"<<std::endl;
        dst<< "endand"<<z<<":"<<std::endl;
        return "$2";

    }


};
class XorOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    XorOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~XorOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result = x^n.result;
            return "$2";
        }
        left->printmips(dst, n, globals);
        storeStack(dst, n, "$2");
        right->printmips(dst, n, globals);
        retrieveStack(dst, n, "$9");
        dst<< "xor $2, $2, $9"<<std::endl;
        return "$2";


    }


};

class BitAndOperator
: public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    BitAndOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~BitAndOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result = x&n.result;
            return "$2";
        }
        left->printmips(dst, n, globals);
        storeStack(dst, n, "$2");
        right->printmips(dst, n, globals);
        retrieveStack(dst, n, "$9");
        dst<< "and $2, $2, $9"<<std::endl;
        return "$2";

    }


};
class LogNotOperator
: public Expression
{
private:
    ExpressionPtr left;
public:
    LogNotOperator(ExpressionPtr _left)
        : left(_left)
          {}
    virtual ~LogNotOperator()
    {
        delete left;
    }

    ExpressionPtr getLeft() const
    { return left; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<<" ";
        dst<<"not";
        dst<<" ";
    }


    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            n.result = !n.result;
            return "$2";
        }
        int z = n.labelcounter+1;
        n.labelcounter+=1;
        left->printmips(dst, n, globals);
        dst<< "bne $zero, $2, make0"<<z<<std::endl;
        dst<< "beq $zero, $2, make1"<<z<<std::endl;
        dst<< "make0"<<z<<":"<<std::endl;
        dst<<  "add $2, $0, $0"<<std::endl;
        dst<< "j endnot"<<z<<std::endl;
        dst<< "make1"<<z<<":"<<std::endl;
        dst<< "addi $2, $0, 1"<<std::endl;
        dst<< "endnot"<<z<<":"<<std::endl;
      
        return "$2";

    }


};

class BitNotOperator
: public Expression
{
private:
    ExpressionPtr left;
public:
    BitNotOperator(ExpressionPtr _left)
        : left(_left)
          {}
    virtual ~BitNotOperator()
    {
        delete left;
    }

    ExpressionPtr getLeft() const
    { return left; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<<" ";
        dst<<"not";
        dst<<" ";
    }


    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
             n.result = ~n.result;
            return "$2";
        }
        left->printmips(dst, n, globals);
        dst<< "nor $2, $2, $2"<<std::endl;
        return "$2";

    }


};


class NotEqOperator
: public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    NotEqOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~NotEqOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result =x!=n.result;
            return "$2";
        }
        left->printmips(dst, n, globals);
        storeStack(dst, n, "$2");
        right->printmips(dst, n, globals);
        retrieveStack(dst, n, "$9");
        dst<< "slt $10, $2, $9"<<std::endl;
        dst<< "slt $2, $9, $2"<<std::endl;
        dst<< "or $2, $2, $10"<<std::endl;
        return "$2";

    }


};

class LessThanEqOperator
: public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    LessThanEqOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~LessThanEqOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result =x<=n.result;
            return "$2";
        }

        left->printmips(dst, n, globals);
        storeStack(dst, n, "$2");
        right->printmips(dst, n, globals);
        retrieveStack(dst, n, "$9");
        dst<< "sub $2, $9, $2"<<std::endl;
        dst<< "slti $2, $2, 1"<<std::endl;
        return "$2";

    }

};

class GreaterThanEqOperator
: public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    GreaterThanEqOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~GreaterThanEqOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result =x>=n.result;
            return "$2";
        }
        left->printmips(dst, n, globals);
        storeStack(dst, n, "$2");
        right->printmips(dst, n, globals);
        retrieveStack(dst, n, "$9");
        dst<< "sub $2, $2, $9"<<std::endl;
        dst<< "slti $2, $2, 1"<<std::endl;
        return "$2";

    }


};

class LeftShiftOperator
: public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    LeftShiftOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~LeftShiftOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result =x<<n.result;
            return "$2";
        }
        int z = n.labelcounter +1;
        n.labelcounter+=1;
        left->printmips(dst, n, globals);
        storeStack(dst, n, "$2");
        right->printmips(dst, n, globals);
        retrieveStack(dst, n, "$9");
        dst<< "leftshift"<<z<<":"<<std::endl;
        dst<< "beq $2, $zero, leftshiftend"<<z<<std::endl;
        dst<< "addi $2, $2, -1"<<std::endl;
        dst<< "sll $9, $9, 1"<<std::endl;
        dst<< "j leftshift"<<z<<std::endl;
        dst<< "leftshiftend"<<z<<":"<<std::endl;
        dst<< "add $2, $9, $zero"<<std::endl;
        return "$2";

    }


};
class RightShiftOperator
: public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    RightShiftOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~RightShiftOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result =x>>n.result;
            return "$2";
        }
        int z = n.labelcounter +1;
        n.labelcounter+=1;
        left->printmips(dst, n, globals);
        storeStack(dst, n, "$2");
        right->printmips(dst, n, globals);
        retrieveStack(dst, n, "$9");
        dst<< "rightshift"<<z<<":"<<std::endl;
        dst<< "beq $2, $zero, rightshiftend"<<z<<std::endl;
        dst<< "addi $2, $2, -1"<<std::endl;
        dst<< "srl $9, $9, 1"<<std::endl;
        dst<< "j rightshift"<<z<<std::endl;
        dst<< "rightshiftend"<<z<<":"<<std::endl;
        dst<< "add $2, $9, $zero"<<std::endl;
        return "$2";

    }


};
class BitOrOperator
: public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    BitOrOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~BitOrOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result =x|n.result;
            return "$2";
        }
        left->printmips(dst, n, globals);
        storeStack(dst, n, "$2");
        right->printmips(dst, n, globals);
        retrieveStack(dst, n, "$9");
        dst<< "or $2, $2, $9"<<std::endl;
        return "$2";


    }


};
class GreaterThanOperator
: public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    GreaterThanOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~GreaterThanOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }

    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result =x>n.result;
            return "$2";
        }
        left->printmips(dst, n, globals);
        storeStack(dst, n, "$2");
        right->printmips(dst, n, globals);
        retrieveStack(dst, n, "$9");
        dst<< "slt $2, $2, $9"<<std::endl;
        return "$2";

    }


};

class LogOrOperator
: public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    LogOrOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~LogOrOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<<" ";
        dst<<"or";
        dst<<" ";
        right->printpython(dst, n, globals);
    }


    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if (n.realsize){
            left->printmips(dst, n, globals);
            int x = n.result;
            n.result = 0;
            right->printmips(dst, n, globals);
            n.result =x||n.result;
            return "$2";
        }
        int z = n.labelcounter+1;
        n.labelcounter+=1;
        left->printmips(dst, n, globals);
        dst<< "bne $zero, $2, endor"<<z<<std::endl;
        right->printmips(dst, n, globals);
        dst<< "bne $zero, $2, endor"<<z<<std::endl;
        dst<< "j eqzeroor"<<z<<std::endl;
        dst<< "endor"<<z<<":"<<std::endl;
        dst<< "addi $2, $zero, 1"<<std::endl;
        dst<< "eqzeroor"<<z<<":"<<std::endl;
        return "$2";

    }


};

class AssExprOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    virtual ~AssExprOperator()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }
    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {   
        left->print(dst);

    }
    AssExprOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        getLeft()->printpython(dst, n, globals);
        dst<<" ";
        dst<< "=";
        dst<<" ";
        getRight()->printpython(dst, n, globals);
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        n.leftHand = true;
        n.findSize = false;
        n.isArray = false;
        n.isGlobal = false;
        getLeft()->printmips(dst, n, globals);
        n.leftHand = false;
        if(n.isGlobal){
            n.isGlobal = false;
            std::string id = n.labname;
            storeStack(dst, n, "$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, "<<id<<"($8)"<<std::endl;
        }
        else{

        
        if(n.findSize){
            n.isArray = false;
            n.findSize = false;
            storeStack(dst, n, "$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
            
            
        }
        else{
            dst<< "addi $2, $sp, "<<n.varaddress<<std::endl;
            storeStack(dst, n, "$2");
            getRight()->printmips(dst, n, globals);
            retrieveStack(dst, n,"$8");
            dst<< "sw $2, 0($8)"<<std::endl;
        }
        }
        return "$2";

    }

};








#endif
