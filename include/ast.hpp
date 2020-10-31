#ifndef ast_hpp
#define ast_hpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>
 struct context{
 	int  tabnumber;// remove later
 	bool globaldec;
 	bool mainbool;
 };
 struct mipscontext{
	 bool initFunc;
 	bool mainbool;
	 bool isArray;
	 bool isAssign;
	 bool isGlobal;
	bool leftHand;
	bool isEnum;
	int enumInt;
	int funcDec;
	std::string labname;
	std::vector<std::string> funcNames;
 	std::map<std::string, int> vartoadd;
	std::vector<std::string> globals;
	std::map<std::string, int> arraytoadd;
 	int address;
 	int varaddress;
 	int labelcounter;
	int registercounter;
	int stackstart;
	std::vector<std::string> latestloopend;
	std::vector<std::string> latestloopstart;
	bool global;
	bool findSize;
	std::vector<int> caseexpressions;
	bool casenumber;
	int caseid;
	bool default_;
	int maxlabelcounter;
	bool secondswitch; ;
	int switchcounter;
	int result;
	bool realsize;
	bool whatever;
 };


#include "ast/ast_expression.hpp"
#include "ast/ast_primitives.hpp"
#include "ast/ast_operators.hpp"
#include "ast/ast_unary.hpp"
#include "ast/ast_declarations.hpp"	

extern FILE *yyin;
extern FILE *yyout;
extern const Expression *parseAST();

//return $2
//jump back to $ra
//s0 for adding stack pointer into 4 some reason

#endif
