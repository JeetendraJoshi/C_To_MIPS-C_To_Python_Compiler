%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Expression *expr;
  double number;
  std::string *string;
}
%define parse.error verbose

%token T_TIMES T_DIVIDE T_PLUS T_MINUS T_LOGICALAND T_LOGICALOR T_LESSTHAN T_CONDEQUALSTO T_EQUALS
%token T_LBRACKET T_RBRACKET T_LCURLYBRACKET T_RCURLYBRACKET T_COMMA T_SEMICOLON
%token T_NUMBER T_VARIABLE T_INT T_VOID T_IF T_WHILE T_ELSE T_RETURN T_MAIN

%type <expr> EXPR TERM UNARY FACTOR ASSIGN SEQ FUNC COND DECLARATOR FUNCDECL
%type <number> T_NUMBER
%type <string> T_VARIABLE 

%start ROOT

%%

//  :D Also need to program operators and test. Function declarations.
/* Operators needing to be created:
    AndOperator
    OrOperator
    CondEqualsOperator
    LessThanOperator
    EqualsOperator
    DeclOperator
    InitOperator
    ExecOperator
    FuncInOperator(Overloaded Twice)
    RetOperator
    DeclListOperator
    IfOperator
    WhileOperator
    ElseOperator
    */

ROOT : EXPR { g_root = $1; }



FUNCDECL : 


SEQ: ASSIGN { $$ = $1;}
    | T_IF COND T_LCURLYBRACKET SEQ T_RBRACKET { $$ = new IfOperator($2, $4);}
    | T_WHILE COND T_LCURLYBRACKET SEQ T_RBRACKET { $$ = new WhileOperator($2, $4);}
    | T_ELSE COND T_LCURLYBRACKET SEQ T_RBRACKET { $$ = new ElseOperator($2, $4);}
    | SEQ SEQ {$$ = new SequenceOperator($1 , $2);}

COND :  T_LBRACKET DECLARATOR T_LOGICALAND DECLARATOR T_RBRACKET { $$ = new AndOperator($2, $4);}
     |  T_LBRACKET DECLARATOR T_LOGICALOR DECLARATOR T_RBRACKET { $$ = new OrOperator ($2 , $4);}
     |  T_LBRACKET DECLARATOR T_CONDEQUALSTO DECLARATOR T_RBRACKET { $$ = new CondEqualsOperator ($2, $4);}
     |  T_LBRACKET DECLARATOR T_LESSTHAN DECLARATOR T_RBRACKET {$$ = new LessThanOperator($2 , $4); }


ASSIGN: T_VARIABLE T_EQUALS DECLARATOR T_SEMICOLON{ $$ = new EqualsOperator($1, $3);}
       | T_INT T_VARIABLE T_SEMICOLON{ $$ = new DeclOperator($2);} 
       | T_INT T_VARIABLE T_EQUALS FUNC T_SEMICOLON {$$ = new InitOperator($2, $4);}
       | DECLARATOR T_SEMICOLON { $$ =  new ExecOperator($1);}
       | T_RETURN DECLARATOR T_SEMICOLON { $$ = new RetOperator($2);}

DECLARATOR: FUNC { $$ = $1}
          | DECLARATOR T_COMMA FUNC { $$ = new DeclListOperator($1 , $3); }




FUNC : EXPR {$$ = $1; }
      |T_VARIABLE L_BRACKET R_BRACKET {$$ = new FuncInOperator($1);}
      | T_VARIABLE L_BRACKET DECLARATOR R_BRACKET {$$ = new FuncInOperator($1, $3);}



EXPR : TERM           { $$ = $1; }
        | EXPR T_PLUS TERM{ $$ = new AddOperator( $1, $3 );}
        | EXPR T_MINUS TERM { $$ = new SubOperator( $1, $3 );}

TERM : UNARY          { $$ = $1; }
        | TERM T_TIMES UNARY { $$ = new MulOperator( $1, $3 );}
        | TERM T_DIVIDE UNARY { $$ = new DivOperator( $1, $3 );}

UNARY : FACTOR        { $$ = $1; }
        | T_MINUS UNARY { $$ = new NegOperator( $2 );}

FACTOR : T_NUMBER     { $$ = new Number( $1 );}
       | T_VARIABLE     { $$ = new Variable( *$1 );}
       | T_LBRACKET EXPR T_RBRACKET { $$ = $2; }



%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
