#ifndef ast_unary_hpp
#define ast_unary_hpp

#include <string>
#include <iostream>

class Unary
    : public Expression
{
private:
    ExpressionPtr expr;
protected:
    Unary(const ExpressionPtr _expr)
        : expr(_expr)
    {}
public:
    virtual ~Unary()
    {
        delete expr;
    }

    virtual const char *getOpcode() const =0;

    ExpressionPtr getExpr() const
    { return expr; }

    virtual void print(std::ostream &dst) const override
    {
        dst << "( ";
        dst << getOpcode();
        dst << " ";
        expr->print(dst);
        dst << " )";
    }

    virtual void printpython(std::ostream &dst, struct context n, std::vector<std::string> &globals) const override
    {
        dst << getOpcode();
        expr->printpython(dst, n, globals);

    }
    virtual std::string printmips(std::ostream &dst, struct mipscontext &n, std::vector<std::string> &globals) const override{
        expr->printmips(dst, n, globals);
        dst<< "subu $2, $0, $2"<<std::endl;
        return "$2";



    }
};

class NegOperator
    : public Unary
{
public:
    NegOperator(const ExpressionPtr _expr)
        : Unary(_expr)
    {}

    virtual const char *getOpcode() const override
    { return "-"; }

};

#endif
