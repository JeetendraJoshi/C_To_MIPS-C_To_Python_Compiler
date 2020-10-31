#ifndef ast_declarations_hpp
#define ast_declarations_hpp

#include "ast_expression.hpp"

#include <cmath>



class Decl1Operator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
   
public:
    Decl1Operator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~Decl1Operator()
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
        dst<<"(";
        right->print(dst);
        dst<<" )";

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        left->printpython(dst, n, globals);
        dst<<"(";
        right->printpython(dst, n, globals);
        dst<<" )";
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{

        if(!n.initFunc){

            left->printmips(dst,n,globals);
            right->printmips(dst,n,globals);
        }
        return "";

    }
};

class Decl2Operator
    : public Expression
{
private:
    ExpressionPtr left;

   
public:
    Decl2Operator(ExpressionPtr _left)
        : left(_left)
    {}
    virtual ~Decl2Operator()
    {
        delete left;
    }

    ExpressionPtr getLeft() const
    { return left; }


    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        dst<<"(";
        dst<<" )";

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<<"(";
        dst<<" )";
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if(!n.initFunc){
        left->printmips(dst,n,globals);
        }
        return "";

    }
};

class ParamDeclOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:

    ParamDeclOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~ParamDeclOperator()
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
        dst<< " ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        right->printpython(dst, n, globals);
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{

        if(n.registercounter < 4){
            std::string sourcereg = "$" + std::to_string(4+n.registercounter);
        n.funcDec = 5;
        right->printmips(dst, n, globals);
        n.funcDec = 3;
        dst<< "addi $8, $sp, "<<n.varaddress<<std::endl;
        dst<< "sw "<<sourcereg<<", 0($8)"<<std::endl;
        }
        else{
        n.funcDec = 5;
        right->printmips(dst, n, globals);
        n.funcDec = 3;
        dst<< "addi $8, $sp, "<<n.varaddress<<std::endl;
        dst<< "addi $9, $fp, "<<-(n.registercounter+1)*4<<std::endl;
        dst<< "lw $2, 0($9)"<<std::endl;
        dst<< "sw $2, 0($8)"<<std::endl;
        }
        n.registercounter++;
        return "";

    }
};


class ParamOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    ParamOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~ParamOperator()
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
        dst<< " , ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<<" , ";
        right->printpython(dst, n, globals);
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        left->printmips(dst, n, globals);
        right->printmips(dst, n, globals);
        return "";


    }
};




class InitDeclOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    InitDeclOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~InitDeclOperator()
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
        dst<< " = ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<< " = ";
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if(n.global){
            n.isAssign = true;
            n.funcDec = 5;
            getLeft()->printmips(dst, n, globals);
            n.funcDec = 3;
            n.isAssign = false;
            n.isArray = false;
            dst << ".word ";
            n.realsize = true;
            n.result = 0;
            getRight()->printmips(dst, n, globals);
            n.realsize = false;
            dst <<n.result<< std::endl;
            return "$2";
        }
        else{
        n.funcDec = 5;
        n.whatever = false;
        getLeft()->printmips(dst, n, globals);
        
        n.funcDec = 3;
        if(n.findSize){
            //if found to be an array
            n.findSize = false;
            getRight()->printmips(dst, n, globals);
        }
        else if(n.whatever){
        getRight()->printmips(dst, n, globals);
        n.whatever = false;
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

class InitDeclListOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    InitDeclListOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~InitDeclListOperator()
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
        dst<< " , ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<< " , ";
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        left->printmips(dst, n, globals);
        right->printmips(dst, n, globals);
        return "";


    }
};

class DeclarationOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    DeclarationOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~DeclarationOperator()
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
        dst<< " ";
        right->print(dst);
        dst<< ";";

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        right->printpython(dst, n, globals);


    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{

        n.initFunc = true;
        left->printmips(dst, n, globals);
        right->printmips(dst, n, globals);
        n.initFunc = false;
        return "";

    }
};

class DeclarationListOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    DeclarationListOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~DeclarationListOperator()
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
        dst<< " ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<< std::endl;
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        left->printmips(dst, n, globals);
        right->printmips(dst, n, globals);
        return "";


    }
};


class ExpressionOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    ExpressionOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~ExpressionOperator()
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
        dst<< " , ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<< " , ";
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        left->printmips(dst, n, globals);
        right->printmips(dst, n, globals);
        return "";


    }
};

class StatListOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    StatListOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~StatListOperator()
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
       // printtabs(dst, n.tabnumber);
        left->printpython(dst, n, globals);
        dst<<std::endl;
       // printtabs(dst, n.tabnumber);
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        left->printmips(dst, n, globals);
        right->printmips(dst, n, globals);

        return "";

    }
};

class ExprStatOperator1
    : public Expression
{
private:
    ExpressionPtr left;
    
public:
    ExprStatOperator1(ExpressionPtr _left)
        : left(_left)
    {}
    virtual ~ExprStatOperator1()
    {
        delete left;
    }

    ExpressionPtr getLeft() const
    { return left; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        dst<< ";";
    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
       // dst << n.tabnumber<<std::endl;
        left->printpython(dst, n, globals);
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        left->printmips(dst, n, globals);
        return "";


    }
};
class ExprStatOperator2
    : public Expression
{
    
public:
 
    virtual void print(std::ostream &dst) const override
    {
        dst<< ";";
    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{

        dst<<"";

        return "";

    }
};
class CompStatOperator1
    : public Expression
{
    
public:
 
    virtual void print(std::ostream &dst) const override
    {
        dst<< "{";
        dst<< "}";
    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
    	dst<< std::endl;
    	printtabs(dst, n.tabnumber);
    	dst<< "pass"<<std::endl;
        n.globaldec = false;

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        return "";

    }
};
class CompStatOperator2
    : public Expression
{
private:
    ExpressionPtr left;
    
public:
    CompStatOperator2(ExpressionPtr _left)
        : left(_left)
    {}
    virtual ~CompStatOperator2()
    {
        delete left;
    }

    ExpressionPtr getLeft() const
    { return left; }

    virtual void print(std::ostream &dst) const override
    {   
         dst<< "{";
        left->print(dst);
        dst << "}";
    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
    
        if(n.globaldec){
            for (int i = 0 ; i < globals.size(); i++){
            printtabs(dst, n.tabnumber);
            dst<< "global " << globals[i] << std::endl;
            }
        }
        n.globaldec = false;
        left->printpython(dst, n, globals);
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        
        int stackstart = n.address;
        
        std::map<std::string, int> vartoadd = n.vartoadd;
        std::map<std::string, int> arraytoadd = n.arraytoadd;
        left->printmips(dst, n, globals);
        n.vartoadd = vartoadd;
        n.arraytoadd = arraytoadd;

        dst<< "addi $sp, $sp, "<< stackstart -n.address<<std::endl;
        n.address = stackstart;

        
        return "";


    }
};


class CompStatOperator3
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    CompStatOperator3(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~CompStatOperator3()
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
        dst<< "{";
        left->print(dst);
        right->print(dst);
        dst<< "}";

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        
        if(n.globaldec){
            for (int i = 0 ; i < globals.size(); i++){
            printtabs(dst, n.tabnumber);
            dst<< "global " << globals[i] << std::endl;
            }
        }
        n.globaldec = false;
        left->printpython(dst, n, globals);
        dst << std::endl;
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        int stackstart = n.address;
        std::map<std::string, int> vartoadd = n.vartoadd;
        std::map<std::string, int> arraytoadd = n.arraytoadd;
        left->printmips(dst, n, globals);
        right->printmips(dst, n, globals);
        
        
        n.vartoadd = vartoadd;
        n.arraytoadd = arraytoadd;
        
        dst<< "addi $sp, $sp, "<< stackstart -n.address<<std::endl;
        n.address = stackstart;
       return "";


    }
};

class IfOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    IfOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~IfOperator()
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

        dst<< "if (";
        left->print(dst);
        dst<< ")";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        dst<< "if (";
        left->printpython(dst, n, globals);
        dst<< ") :"<< std::endl;
        n.tabnumber = n.tabnumber +1 ;
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        std::string leftstring = left->printmips(dst, n, globals); 
        n.labelcounter+=1;
        int z = n.labelcounter;
        dst << "beq $2, $zero, if"<<z<<std::endl;
        std::string rightstring = right->printmips(dst, n , globals);
        dst<< "if"<<z<<":"<<std::endl;
        return "$2"; 



    }
};

class IfElseOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr middle;
    ExpressionPtr right;
    
public:
    IfElseOperator(ExpressionPtr _left,ExpressionPtr _middle,  ExpressionPtr _right)
        : left(_left)
        , right(_right)
        , middle(_middle)
    {}
    virtual ~IfElseOperator()
    {
        delete left;
        delete middle;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }
    ExpressionPtr getMiddle() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {   

        dst<< "if (";
        left->print(dst);
        dst<< ")";
        middle->print(dst);
        dst<< "else";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        n.tabnumber = n.tabnumber +1 ;
        dst<< "if (";
        left->printpython(dst, n, globals);
        dst<< ") :" << std::endl;
        middle->printpython(dst, n, globals);
        dst << std::endl;
        n.tabnumber = n.tabnumber -1 ;
        printtabs(dst, n.tabnumber);
        dst << "else :" << std::endl;
        n.tabnumber = n.tabnumber +1 ;
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        
        n.labelcounter+=1;
        int z = n.labelcounter;
        left->printmips(dst, n, globals); 
        dst << "beq $2, $zero, else"<<z<<std::endl;
        middle->printmips(dst, n , globals);
        dst<< "j endif"<<z<<std::endl;
        dst<< "else"<<z<<":"<<std::endl;
        right->printmips(dst, n, globals);
        dst<< "endif"<<z<<":"<<std::endl;
        return "$2"; 

    }
};


class WhileOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    WhileOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~WhileOperator()
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

        dst<< "while (";
        left->print(dst);
        dst<< ") ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        n.tabnumber = n.tabnumber +1 ;
        dst<< "while (";
        left->printpython(dst, n, globals);
        dst<< ") :" <<std::endl;
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        n.labelcounter+=1;
        int z = n.labelcounter;
        n.latestloopstart.push_back("while"+std::to_string(z));
        n.latestloopend.push_back("whileend" + std::to_string(z));
        dst<< "while"<<z<<":"<<std::endl;
        left->printmips(dst, n, globals); 
        dst << "beq $2, $zero, whileend"<<z<<std::endl;
        right->printmips(dst, n , globals);
        dst<< "j while"<<z<<std::endl;
        dst<< "whileend"<<z<<":"<<std::endl;
        n.latestloopend.pop_back();
        n.latestloopstart.pop_back();
        return "$2";


    }
};

class ForLoopOperator1
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr middlel;
    ExpressionPtr middler;
    ExpressionPtr right;
    
public:
    ForLoopOperator1(ExpressionPtr _left, ExpressionPtr _middlel, ExpressionPtr  _middler, ExpressionPtr _right)
        : left(_left)
        , middlel(_middlel)
        , middler(_middler)
        , right(_right)
    {}
    virtual ~ForLoopOperator1()
    {
        delete left;
        delete middlel;
        delete middler;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getMiddlel() const
    { return middlel; }
    ExpressionPtr getMiddler() const
    { return middler; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {   

        dst<< "while (";
        left->print(dst);
        dst<< ") ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        n.tabnumber = n.tabnumber +1 ;
        dst<< "while (";
        left->printpython(dst, n, globals);
        dst<< ") :" <<std::endl;
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        n.labelcounter+=1;
        int z = n.labelcounter;
        n.latestloopend.push_back("forloopend"+std::to_string(z));
        n.latestloopstart.push_back("forloopstart"+std::to_string(z));
        left->printmips(dst,n,globals);
        dst<< "j expressionlabel"<<z<<std::endl;
        dst<< "forloopstart"<<z<<":"<<std::endl;
        right->printmips(dst, n , globals);
        middler->printmips(dst,n,globals);
        dst<< "expressionlabel"<<z<<":"<<std::endl;
        middlel->printmips(dst,n,globals);
        dst<< "bne $2, $0, forloopstart"<<z<<std::endl;
        dst<< "forloopend"<<z<<":"<<std::endl;
        n.latestloopend.pop_back();
        n.latestloopstart.pop_back();
        return "$2";

    }
};


class ForLoopOperator2
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr middle;
    ExpressionPtr right;
    
public:
    ForLoopOperator2(ExpressionPtr _left, ExpressionPtr _middle, ExpressionPtr _right)
        : left(_left)
        , middle(_middle)
        , right(_right)
    {}
    virtual ~ForLoopOperator2()
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

        dst<< "while (";
        left->print(dst);
        dst<< ") ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        n.tabnumber = n.tabnumber +1 ;
        dst<< "while (";
        left->printpython(dst, n, globals);
        dst<< ") :" <<std::endl;
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        n.labelcounter+=1;
        int z = n.labelcounter;
        n.latestloopend.push_back("forloopend"+std::to_string(z));
        n.latestloopstart.push_back("forloopstart"+std::to_string(z));
        left->printmips(dst,n,globals);
        dst<< "j expressionlabel"<<z<<std::endl;
        dst<< "forloopstart"<<z<<":"<<std::endl;
        right->printmips(dst, n , globals);
        
        dst<< "expressionlabel"<<z<<":"<<std::endl;
        middle->printmips(dst,n,globals);
        dst<< "bne $2, $0, forloopstart"<<z<<std::endl;
        dst<< "forloopend"<<z<<":"<<std::endl;
        n.latestloopend.pop_back();
        n.latestloopstart.pop_back();
        return "$2";

    }
};


class ForLoopOperator3
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr middle;
    ExpressionPtr right;
    
public:
    ForLoopOperator3(ExpressionPtr _left, ExpressionPtr _middle, ExpressionPtr _right)
        : left(_left)
        , middle(_middle)
        , right(_right)
    {}
    virtual ~ForLoopOperator3()
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

        dst<< "while (";
        left->print(dst);
        dst<< ") ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        n.tabnumber = n.tabnumber +1 ;
        dst<< "while (";
        left->printpython(dst, n, globals);
        dst<< ") :" <<std::endl;
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        n.labelcounter+=1;
        int z = n.labelcounter;
        n.latestloopend.push_back("forloopend"+std::to_string(z));
        n.latestloopstart.push_back("forloopstart"+std::to_string(z));
        

        left->printmips(dst,n,globals);
        dst<< "forloopstart"<<z<<":"<<std::endl;
        right->printmips(dst, n , globals);
        middle->printmips(dst,n,globals);
        dst<< "j forloopstart"<<z<<std::endl;
        dst<< "forloopend"<<z<<":"<<std::endl;
        n.latestloopend.pop_back();
        n.latestloopstart.pop_back();
        return "$2";

    }
};






class ForLoopOperator4
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr middle;
    ExpressionPtr right;
    
public:
    ForLoopOperator4(ExpressionPtr _left, ExpressionPtr _middle, ExpressionPtr _right)
        : left(_left)
        , middle(_middle)
        , right(_right)
    {}
    virtual ~ForLoopOperator4()
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

        dst<< "while (";
        left->print(dst);
        dst<< ") ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        n.tabnumber = n.tabnumber +1 ;
        dst<< "while (";
        left->printpython(dst, n, globals);
        dst<< ") :" <<std::endl;
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        n.labelcounter+=1;
        int z = n.labelcounter;
        n.latestloopend.push_back("forloopend"+std::to_string(z));
        n.latestloopstart.push_back("forloopstart"+std::to_string(z));
        dst<< "j expressionlabel"<<z<<std::endl;
        dst<< "forloopstart"<<z<<":"<<std::endl;
        right->printmips(dst, n , globals);
        middle->printmips(dst,n,globals);
        dst<<" expressionlabel"<<z<<":"<<std::endl;
        left->printmips(dst,n,globals);
        dst<< "bne $2, $0, forloopstart"<<z<<std::endl;
        dst<< "forloopend"<<z<<":"<<std::endl;
        n.latestloopend.pop_back();
        n.latestloopstart.pop_back();
        return "$2";

    }
};





class ForLoopOperator5
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    ForLoopOperator5(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~ForLoopOperator5()
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

        dst<< "while (";
        left->print(dst);
        dst<< ") ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        n.tabnumber = n.tabnumber +1 ;
        dst<< "while (";
        left->printpython(dst, n, globals);
        dst<< ") :" <<std::endl;
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        n.labelcounter+=1;
        int z = n.labelcounter;
        n.latestloopend.push_back("forloopend"+std::to_string(z));
        n.latestloopstart.push_back("forloopstart"+std::to_string(z));
        left->printmips(dst, n , globals);
        dst<< "forloopstart"<<z<<":"<<std::endl;
        right->printmips(dst, n , globals);

        dst<< "j forloopstart"<<z<<std::endl;
        dst<< "forloopend"<<z<<":"<<std::endl;

        n.latestloopend.pop_back();
        n.latestloopstart.pop_back();
        return "$2";


    }
};




class ForLoopOperator6
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    ForLoopOperator6(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~ForLoopOperator6()
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

        dst<< "while (";
        left->print(dst);
        dst<< ") ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        n.tabnumber = n.tabnumber +1 ;
        dst<< "while (";
        left->printpython(dst, n, globals);
        dst<< ") :" <<std::endl;
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        n.labelcounter+=1;
        int z = n.labelcounter;
        n.latestloopend.push_back("forloopend"+std::to_string(z));
        n.latestloopstart.push_back("forloopstart"+std::to_string(z));
        dst<< "forloopstart"<<z<<":"<<std::endl;
        right->printmips(dst, n , globals);
        left->printmips(dst, n , globals);
        dst<< "j forloopstart"<<z<<std::endl;
        dst<< "forloopend"<<z<<":"<<std::endl;

        n.latestloopend.pop_back();
        n.latestloopstart.pop_back();
        return "$2";


    }
};



class ForLoopOperator7
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    ForLoopOperator7(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~ForLoopOperator7()
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

        dst<< "while (";
        left->print(dst);
        dst<< ") ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        n.tabnumber = n.tabnumber +1 ;
        dst<< "while (";
        left->printpython(dst, n, globals);
        dst<< ") :" <<std::endl;
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        n.labelcounter+=1;
        int z = n.labelcounter;
        n.latestloopend.push_back("forloopend"+std::to_string(z));
        n.latestloopstart.push_back("forloopstart"+std::to_string(z));
        dst<< "j expressionlabel"<<z<<std::endl;

        dst<< "forloopstart"<<z<<":"<<std::endl;
        right->printmips(dst, n , globals);
        dst<< "expressionlabel"<<z<<":"<<std::endl;     
        left->printmips(dst, n , globals);
        dst<< "bne $2, $0, forloopstart"<<z<<std::endl;

        dst<< "forloopend"<<z<<":"<<std::endl;

        n.latestloopend.pop_back();
        n.latestloopstart.pop_back();
        return "$2";


    }
};


class ForLoopOperator8
    : public Expression
{
private:
    ExpressionPtr left;
    
public:
    ForLoopOperator8(ExpressionPtr _left)
        : left(_left)
    {}
    virtual ~ForLoopOperator8()
    {
        delete left;
    }

    ExpressionPtr getLeft() const
    { return left; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        dst<< ";";
    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
       // dst << n.tabnumber<<std::endl;
        left->printpython(dst, n, globals);
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        n.labelcounter+=1;
        int z = n.labelcounter;
        n.latestloopend.push_back("forloopend"+std::to_string(z));
        n.latestloopstart.push_back("forloopstart"+std::to_string(z));
        dst<< "forloopstart"<<z<<":"<<std::endl;
        left->printmips(dst,n,globals);
        dst<< "j forloopstart"<<z<<std::endl;
        dst<< "forloopend"<<z<<":"<<std::endl;
        n.latestloopstart.pop_back();
        n.latestloopend.pop_back();
        return "$2";


    }
};

class SwitchOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    SwitchOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~SwitchOperator()
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

        dst<< "while (";
        left->print(dst);
        dst<< ") ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        n.tabnumber = n.tabnumber +1 ;
        dst<< "while (";
        left->printpython(dst, n, globals);
        dst<< ") :" <<std::endl;
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        int savedlabelcounter = n.labelcounter;
        std::vector<int> tempcases = n.caseexpressions;
        int remembercaseid = n.caseid;
        bool remdefault = n.default_;

        n.caseid = 0;
        n.caseexpressions.clear();
        n.default_ = false;
        n.labelcounter+=1;
        int z = n.labelcounter;
        n.maxlabelcounter = n.labelcounter;
        if(n.secondswitch){
            n.switchcounter++;
        }
        n.secondswitch = true;
        n.latestloopstart.push_back("switch"+std::to_string(z));
        n.latestloopend.push_back("switchend" + std::to_string(z));
        dst<< "j switch"<<z<<std::endl;

        right->printmips(dst, n, globals);
        dst<< "switch"<<z<<":"<<std::endl;
        left->printmips(dst,  n , globals);
        for(int i = 0; i< n.caseexpressions.size(); i++){
            dst<< "addi $8, $0, "<<n.caseexpressions[i]<<std::endl;
            dst<< "beq $2, $8, case"<<z<<"_"<<i<<std::endl;
        }
        n.caseexpressions.clear();
        if(n.default_){
            dst<< "j default"<<z<<std::endl;
            n.default_ = false;
        }
        if(n.switchcounter==0){
            n.secondswitch = false;
        }

        if(n.switchcounter>0){
            n.switchcounter--;
        }

        dst<<"switchend"<<z<<":"<<std::endl;
        n.labelcounter = savedlabelcounter;
        n.caseexpressions= tempcases;
        n.caseid= remembercaseid;
        n.default_ = remdefault;
        if (!n.secondswitch ){

            n.labelcounter = n.maxlabelcounter;
        }

        n.latestloopend.pop_back();
        n.latestloopstart.pop_back();
        return "$2";


    }
};


class DefaultOperator
    : public Expression
{
private:
    ExpressionPtr left;
    
public:
    DefaultOperator(ExpressionPtr _left)
        : left(_left)
    {}
    virtual ~DefaultOperator()
    {
        delete left;
    }

    ExpressionPtr getLeft() const
    { return left; }

    virtual void print(std::ostream &dst) const override
    {   


    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{


    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        n.default_ = true;
        int z = n.labelcounter;

        dst<< "default"<<z<<":"<<std::endl;
        std::vector<int> tmp = n.caseexpressions;
        n.caseexpressions.clear();
        left-> printmips(dst, n, globals);

        n.caseexpressions = tmp;     

        dst<< "j switchend"<<z<<std::endl;
        return "$2";
    }
};


class LabstatOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    LabstatOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~LabstatOperator()
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

        dst<< "while (";
        left->print(dst);
        dst<< ") ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        n.tabnumber = n.tabnumber +1 ;
        dst<< "while (";
        left->printpython(dst, n, globals);
        dst<< ") :" <<std::endl;
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        left->printmips(dst,n,globals);
        dst<< n.labelcounter<< ":"<<std::endl;
        right->printmips(dst, n, globals);
        return "$2";
    }
};
class CaseOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    CaseOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~CaseOperator()
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

        dst<< "while (";
        left->print(dst);
        dst<< ") ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        n.tabnumber = n.tabnumber +1 ;
        dst<< "while (";
        left->printpython(dst, n, globals);
        dst<< ") :" <<std::endl;
        right->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        int z = n.labelcounter;
        n.casenumber = true;
        left->printmips(dst,n,globals);
         n.casenumber = false;
        dst<<"case"<<z<<"_"<<n.caseid<< ":"<<std::endl;
        n.caseid++;
        std::vector<int> tmp = n.caseexpressions;
        int remcaseid = n.caseid;
        n.caseid = 0;
        bool remdefault = n.default_;
        n.caseexpressions.clear();
        n.default_ = false;
        right->printmips(dst, n, globals);

        n.labelcounter = z;
        n.caseexpressions = tmp;
        n.caseid = remcaseid;
        n.default_ = remdefault;
        return "$2";
    }
};


class BreakOperator
    : public Expression
{
    
public:
 
    virtual void print(std::ostream &dst) const override
    {
        dst<< "break;";
    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        dst<< "BreakOperator";
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        dst<< "j "<< n.latestloopend[n.latestloopend.size()-1] <<std::endl;

        return "$2";

    }
};


class ContinueOperator
    : public Expression
{
    
public:
 
    virtual void print(std::ostream &dst) const override
    {
        dst<< "break;";
    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        dst<< "BreakOperator";
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        dst<< "beq $0, $0,  "<< n.latestloopstart[n.latestloopstart.size()-1] <<std::endl;
        return "$2";

    }
};

class RetOperator1
    : public Expression
{
    
public:
 
    virtual void print(std::ostream &dst) const override
    {
        dst<< "return;";
    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        dst<< "return ";
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        dst<< "add $2, $2, $zero"<<std::endl;
        int dist = n.stackstart - n.address;
        //n.address = n.stackstart;
        dst << "addi $sp, $sp," <<dist <<std::endl;
      //  dst<< "addi $2, $zero, 4"<<std::endl;/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Testing
        dst<< "jr $ra"<<std::endl;
        return "$2";

    }
};

class RetOperator2
    : public Expression
{
private:
    ExpressionPtr left;
    
public:
    RetOperator2(ExpressionPtr _left)
        : left(_left)
    {}
    virtual ~RetOperator2()
    {
        delete left;
    }

    ExpressionPtr getLeft() const
    { return left; }

    virtual void print(std::ostream &dst) const override
    {   
         dst<< "return";
        left->print(dst);
    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        printtabs(dst, n.tabnumber);
        dst<< "return ";
        left->printpython(dst, n, globals);
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        left->printmips(dst, n, globals);
        int dist = n.stackstart - n.address;
        //n.address = n.stackstart;
        dst << "addi $sp, $sp," <<dist <<std::endl;
       // dst<< "addi $2, $zero, 4"<<std::endl; /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Testing
        dst<< "jr $ra"<<std::endl;
        return "$2";


    }
};

class FuncDeclOperator1
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    FuncDeclOperator1(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~FuncDeclOperator1()
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
        
        dst << "def ";
        left->printpython(dst, n, globals);
        n.globaldec = true;
        dst<< " :"<<std::endl;
        n.tabnumber = n.tabnumber +1 ;
        right->printpython(dst, n, globals);
        n.globaldec = false;


    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        n.vartoadd.clear();
        left->printmips(dst, n, globals);
        right->printmips(dst, n, globals);
        return "";


    }
};

class FuncDeclOperator2
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr middle;
    ExpressionPtr right;
    
public:
    FuncDeclOperator2(ExpressionPtr _left, ExpressionPtr _middle, ExpressionPtr _right)
        : left(_left)
        , middle(_middle)
        , right(_right)
    {}
    virtual ~FuncDeclOperator2()
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
        middle->print(dst);
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        dst << "def ";
        left->printpython(dst, n, globals);
        middle->printpython(dst, n, globals);
        n.globaldec = true;
        dst<< ":"<<std::endl;
        n.tabnumber = n.tabnumber +1 ;
        right->printpython(dst, n, globals);
        n.globaldec = false;


    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        //might need 2 funcdecl2s rather than sharing
        dst<< ".text" << std::endl;
        n.global = false;
        n.vartoadd.clear();
        n.stackstart = n.address;
        n.funcDec = 1;
        n.registercounter = 0;
        middle->printmips(dst,n, globals);
        n.funcDec = 0;   
        right->printmips(dst,n, globals);
        int dist = n.stackstart - n.address;
        n.address = n.stackstart;
        dst << "addi $sp, $sp," <<dist <<std::endl;
        dst << "jr $ra"<<std::endl;
        n.global = true;
        dst << ".data"<<std::endl;
        return "Declared another function!";
        

    }
};

class FuncDeclOperator3
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr middlel;
    ExpressionPtr middler;
    ExpressionPtr right;
    
public:
    FuncDeclOperator3(ExpressionPtr _left, ExpressionPtr _middlel, ExpressionPtr _middler, ExpressionPtr _right)
        : left(_left)
        , middlel(_middlel)
        , middler(_middler)
        , right(_right)
    {}
    virtual ~FuncDeclOperator3()
    {
        delete left;
        delete middlel;
        delete middler;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

     ExpressionPtr getMiddlel() const
    { return middlel; }

     ExpressionPtr getMiddler() const
    { return middler; }


    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {   
        left->print(dst);
        middlel->print(dst);
        middler->print(dst);
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        
        dst << "def ";
        left->printpython(dst, n, globals);
        middlel->printpython(dst, n, globals);
        middler->printpython(dst, n, globals);
        n.globaldec = true;
        dst<< ":"<<std::endl;
        n.tabnumber = n.tabnumber +1 ;
        right->printpython(dst, n, globals);
        n.globaldec = false;


    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        n.global =false;
        n.vartoadd.clear();
        n.stackstart = n.address;
        n.funcDec = 1;
        std::string a = middlel->printmips(dst,n, globals);
        n.funcDec = 1;
        a = right->printmips(dst,n, globals);
        int dist = n.stackstart - n.address;
        n.address = n.stackstart;
        dst << "addi $sp, $sp," <<dist <<std::endl;
        dst << "jr $ra"<<std::endl;
        n.global = true;
        return "Declared another function!";
    }
};

class TransUnitOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    TransUnitOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~TransUnitOperator()
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
        dst<< std::endl;
        right->printpython(dst, n, globals);


    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{

        left->printmips(dst, n, globals);
        right->printmips(dst, n, globals);
        return "";

    }
};


class ArgExprListOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    ArgExprListOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~ArgExprListOperator()
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
        dst<< " , ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<< " , ";
        right->printpython(dst, n, globals);
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{    
        left->printmips(dst, n, globals);
        storeStack(dst, n,"$2");  
        n.registercounter++;     
        right->printmips(dst, n, globals);
        retrieveStack(dst, n, "$8");
        storeStack(dst, n,"$2"); 
        dst << "addi $2, $8, 0"  <<std::endl;
        return "$2";
    }
};

class PostFixOperator1
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    PostFixOperator1(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~PostFixOperator1()
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
        dst<< "(";
        right->print(dst);
        dst<< ")";

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<< "(";
        right->printpython(dst, n, globals);
        dst<< ")";
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        //return to previous stack pointer
        n.registercounter = 1;
        storeStack(dst, n,"$fp");
        
        storeStack(dst, n,"$31");
        dst<<"addi $fp, $sp, 0"<<std::endl;
        storeStack(dst, n, "$2");
        std::string a = right->printmips(dst, n, globals);
        dst<< "addi $8, $sp, "<<(n.registercounter-1)*4<<std::endl;
        dst <<"sw $2, 0($8)"<<std::endl;
        n.funcDec = 2;
        left->printmips(dst, n, globals);
        retrieveStack(dst,n,"$31");
        retrieveStack(dst,n,"$fp");
        n.funcDec = 0;
        return "$2";


    }
};

class PostFixOperator2
    : public Expression
{
private:
    ExpressionPtr left;
    
public:
    PostFixOperator2(ExpressionPtr _left)
        : left(_left)
    {}
    virtual ~PostFixOperator2()
    {
        delete left;
    }

    ExpressionPtr getLeft() const
    { return left; }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        dst<< "(";
        dst<< ")";

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<< "(";
        dst<< ")";
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        //return to previous stack pointer
        n.registercounter = 0;
        n.funcDec = 2;
        storeStack(dst, n,"$fp");
        dst<<"addi $fp, $sp, 0"<<std::endl;
        storeStack(dst, n,"$31");
        left->printmips(dst, n, globals);
        retrieveStack(dst,n,"$31");
        retrieveStack(dst,n,"$fp");
        n.funcDec = 0;
        return "done a func";

    }
};

class GlobalOperator
    : public Expression
{
private:
    ExpressionPtr left;
    
public:
    GlobalOperator(ExpressionPtr _left)
        : left(_left)
    {}
    virtual ~GlobalOperator()
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
        n.globaldec = true;
        left->printpython(dst, n, globals);
        n.globaldec = false;
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        left->printmips(dst, n, globals);
        return "";

    }
};

class DeclaratorOperator
    : public Expression
{
private:
    ExpressionPtr left;

   
public:
    DeclaratorOperator(ExpressionPtr _left)
        : left(_left)
    {}
    virtual ~DeclaratorOperator()
    {
        delete left;
    }

    ExpressionPtr getLeft() const
    { return left; }


    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        dst<<"(";
        dst<<" )";

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<< "= 0";
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        n.funcDec = 5;
        n.isArray = false;
        left->printmips(dst, n, globals);
        n.funcDec = 3;
        if(!n.isArray && !n.isAssign && n.global){
            dst << ".space 4"<<std::endl;
        }
        return "";



    }
};

class MainDeclOperator
    : public Expression
{
private:
    ExpressionPtr left;
    
public:
    MainDeclOperator(ExpressionPtr _left)
        : left(_left)
    {}
    virtual ~MainDeclOperator()
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
        dst << "def main():"<< std::endl;
        n.tabnumber = n.tabnumber +1 ;
        n.globaldec = true;
        left->printpython(dst, n, globals);
        n.globaldec = false;
        dst<< std::endl;
        dst<<"if __name__ == \"__main__\":"<<std::endl<<'\t'<< "import sys"<<std::endl;
        dst<<'\t' << "ret=main()"<<std::endl<< '\t' <<"sys.exit(ret)"<<std::endl;

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        dst<< ".globl main"<<std::endl;
        dst << "main:"<< std::endl;
        n.vartoadd.clear();
        n.stackstart = n.address;
        n.mainbool = true;
        left->printmips(dst, n, globals);
        dst<< std::endl;
        int dist = n.stackstart - n.address;
        n.address = n.stackstart;
        dst << "addi $sp, $sp," <<dist <<std::endl;
        //test if bash is working 
        //dst << "addi $2, $zero, 3"<<std::endl;
        dst<<"j end"<<std::endl;

        return "";

    }
};

class InitializerOperator
    : public Expression
{
private:
    ExpressionPtr left;

   
public:
    InitializerOperator(ExpressionPtr _left)
        : left(_left)
    {}
    virtual ~InitializerOperator()
    {
        delete left;
    }

    ExpressionPtr getLeft() const
    { return left; }


    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        dst<<"(";
        dst<<" )";

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<< "= 0";
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        //int startaddress = n.address;
        if(n.global){
            left->printmips(dst,n,globals);
        }
        else{
        dst<< "addi $sp, $sp, "<<n.varaddress<<std::endl;
        n.address += n.varaddress;
        left->printmips(dst, n, globals);
        dst<< "sw $2, 0($sp)"<<std::endl;
        n.address -= 4; 
        dst<< "addi $sp, $sp, -4"<<std::endl;
        }  
        return "";



    }
};
class Initializer2Operator
    : public Expression
{
private:
    ExpressionPtr left;

   
public:
    Initializer2Operator(ExpressionPtr _left)
        : left(_left)
    {}
    virtual ~Initializer2Operator()
    {
        delete left;
    }

    ExpressionPtr getLeft() const
    { return left; }


    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        dst<<"(";
        dst<<" )";

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<< "= 0";
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        if(n.global){
            left->printmips(dst,n,globals);
        }
        else{
        dst<< "addi $sp, $sp, "<<n.varaddress<<std::endl;
        left->printmips(dst, n, globals);        
        dst<< "sw $2, 0($sp)"<<std::endl;
        dst<< "addi $sp, $sp, -4"<<std::endl;
        n.address -= 4; 
        }  
        return "";



    }
};


class InitializerListOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    InitializerListOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~InitializerListOperator()
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
        dst<< " , ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<< " , ";
        right->printpython(dst, n, globals);
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{  
        //save initial address each changes var address  
        if(n.global){
            left->printmips(dst,n,globals);
            dst<<n.result;
            dst << ",";
            right->printmips(dst,n,globals);

        }
        else{

        
        left->printmips(dst, n, globals);
        dst<< "sw $2, 0($sp)"<<std::endl;
        dst<< "addi $sp, $sp, -4"<<std::endl;
        n.address -= 4;
        right->printmips(dst, n, globals);
        }
        return "$2";
    }
};


class PostFixOperator3
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
   
public:
    PostFixOperator3(ExpressionPtr _left,ExpressionPtr _right)
        : left(_left),right(_right)
    {}
    virtual ~PostFixOperator3()
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
        dst<<"(";
        dst<<" )";

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<< "= 0";
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        bool whichHand = n.leftHand;
        n.leftHand = false;
        right->printmips(dst,n,globals);
        n.isArray = true;
        dst << "sll $2, $2, 2"<<std::endl;
        storeStack(dst, n, "$2");
        left->printmips(dst, n, globals);       
        dst<< "addi $2, $sp, "<<n.varaddress<<std::endl;
        retrieveStack(dst, n, "$9");
        if(n.isGlobal){
            if(whichHand){
                //dst << "subu $2, $zero, $9"<<std::endl;
                dst << "add $2, $zero, $9"<<std::endl;
                 n.isArray = false;
                return "";
            }
            else{
                //dst << "subu $2, $zero, $9"<<std::endl;
                dst << "add $2, $zero, $9"<<std::endl;
                dst << "lw $2, "<<n.labname<<"($2)"<<std::endl;
                 n.isArray = false;
                return "";
            }
        }
        dst<< "subu $2, $2, $9"<<std::endl;
        if(whichHand){
            n.findSize = true;
            n.isArray = false;
            return "";
        }
        dst<< "lw $2, 0($2)"<<std::endl;
         n.isArray = false;
        return "";


    }
};

class DirectDeclOperator1
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
   
public:
    DirectDeclOperator1(ExpressionPtr _left,ExpressionPtr _right)
        : left(_left),right(_right)
    {}
    virtual ~DirectDeclOperator1()
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
        dst<<"(";
        dst<<" )";

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<< "= 0";
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
       // n.funcDec = 7;
        n.funcDec = 5;
        n.isArray = true;
        left->printmips(dst,n,globals);
        n.funcDec = 3;
        n.findSize = true;
        n.realsize = true;
        n.result = 0;
        if(n.global && !n.isAssign){
            dst << ".space ";
            right->printmips(dst, n, globals);
        }
        else if (!n.global){
            right->printmips(dst, n, globals);
            n.address -= n.result*4;
            n.varaddress = (n.result)*4;
            dst<< "addi $sp, $sp, "<<-4*(n.result)<<std::endl; 
            n.whatever = true;
        }    
        n.findSize = false;
        n.realsize = false;
        n.isArray = false;
        return "";



    }
};
class DirectDeclOperator2
    : public Expression
{
private:
    ExpressionPtr left;
   
public:
    DirectDeclOperator2(ExpressionPtr _left)
        : left(_left)
    {}
    virtual ~DirectDeclOperator2()
    {
        delete left;
    }

    ExpressionPtr getLeft() const
    { return left; }


    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        dst<<"(";
        dst<<" )";

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<< "= 0";
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
            n.funcDec = 5;
            left->printmips(dst,n,globals);
            n.funcDec = 3;

        
        return "";



    }
};


class EnumeratorOperator2
    : public Expression
{
private:
    ExpressionPtr left;
    
public:
   EnumeratorOperator2(ExpressionPtr _left)
        : left(_left)
    {}
    virtual ~EnumeratorOperator2()
    {
        delete left;
    }

    ExpressionPtr getLeft() const
    { return left; }


    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        dst<< " , ";

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<< " , ";
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{  
        n.funcDec = 10;
        left->printmips(dst, n, globals);
        dst << ".word "<<n.enumInt<<std::endl;
        n.enumInt++;
        n.funcDec = 0;
        return "$2";
    }
};

class EnumeratorOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    EnumeratorOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~EnumeratorOperator()
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
        dst<< " , ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<< " , ";
        right->printpython(dst, n, globals);
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{  
        n.funcDec = 10;
        left->printmips(dst, n, globals);
        
        dst << ".word ";
        right->printmips(dst, n, globals);
        dst<<n.result<<std::endl;
        n.enumInt++;
        n.funcDec = 0;
        return "$2";
    }
};

class EnumeratorListOperator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;
    
public:
    EnumeratorListOperator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    virtual ~EnumeratorListOperator()
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
        dst<< " , ";
        right->print(dst);

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<< " , ";
        right->printpython(dst, n, globals);
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{  
        n.enumInt = 0;
        left->printmips(dst, n, globals);
        right->printmips(dst, n, globals);
        return "$2";
    }
};

class EnumSpecifier1
    : public Expression
{
private:
    ExpressionPtr left;
    
public:
   EnumSpecifier1(ExpressionPtr _left)
        : left(_left)
    {}
    virtual ~EnumSpecifier1()
    {
        delete left;
    }

    ExpressionPtr getLeft() const
    { return left; }


    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        dst<< " , ";

    }
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override{
        left->printpython(dst, n, globals);
        dst<< " , ";
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{  
        left->printmips(dst, n, globals);
        return "$2";
    }
};



#endif


