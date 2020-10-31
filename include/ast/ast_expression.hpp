#ifndef ast_expression_hpp
#define ast_expression_hpp

#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "ast.hpp"

class Expression;

typedef const Expression *ExpressionPtr;


class Expression
{
public:
    virtual ~Expression()
    {}

    //! Tell and expression to print itself to the given stream
    virtual void print(std::ostream &dst) const =0;

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const {};

    void loadreg(std::ostream &dst, std::string destination, std::string address) const {
        if (address[0]== '$'){
            dst<< "add "<< destination<< " , "<< address<< " , $zero "<<std::endl;
        }
        else{
            dst<< "lw "<< destination<< " , "<< address<<"($zero)"<<std::endl;
        }
    }
    void storeStack(std::ostream &dst, struct mipscontext &n, std::string source) const{
        dst<< "addi $sp, $sp, -4"<<std::endl;
        n.address -= 4;
        dst<< "sw "<<source<<", 0($sp)"<<std::endl;
        
    }
    void retrieveStack(std::ostream &dst, struct mipscontext &n, std::string destination)const{  
        dst<< "lw "<<destination<<", 0($sp)"<<std::endl;
        n.address += 4;
        dst<< "addi $sp, $sp, 4"<<std::endl;
    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const =0;

    void printtabs(std::ostream &dst, int n)const{
    for (int i = 0 ; i < n ; i ++){
        dst<< '\t';
        }
    }
};


#endif
						