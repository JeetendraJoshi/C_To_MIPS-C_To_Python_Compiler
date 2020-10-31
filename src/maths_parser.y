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
%token T_LBRACKET T_RBRACKET T_LCURLYBRACKET T_RCURLYBRACKET T_COMMA T_SEMICOLON T_LSBRACKET T_RSBRACKET 
%token T_NUMBER T_VARIABLE T_INT T_VOID T_IF T_WHILE T_ELSE T_RETURN T_MAIN T_BITAND T_BITOR T_GREATERTHAN T_XOR T_LESSTHANEQ T_GREATERTHANEQ T_NOTEQ
%token T_MULTEQUALS T_DIVEQUALS T_MODULOEQUALS T_PLUSEQUALS T_SUBEQUALS T_LEFTSHIFT T_RIGHTSHIFT T_LEFTSHIFTEQUALS T_RIGHTSHIFTEQUALS T_ANDEQUALS T_XOREQUALS T_OREQUALS T_MODULO T_QMARK T_COLON  T_FOR T_DO T_BREAK T_CONTINUE T_SWITCH T_DEFAULT T_CASE T_ENUM T_INCREMENT T_DECREMENT T_LOGNOT T_TILDE

%type <expr> EXPR TERM UNARY FACTOR TRANSUNIT EXTDECL FUNCDECL JUMPSTAT ITSTAT VAR SELSTAT COMPSTAT EXPRSTAT STATLIST STAT EXPRESSION DECLLIST DECLARATION INITDECLLIST INITDECL ASSEXPR LOGOREXPR LOGANDEXPR EQUEXPR RELEXPR PARAMLIST PARAMDECL DECLARATOR DECLSPEC POSTFIX ARGEXPRLIST SHIFTEXPR XOREXPR INCLEXPR ANDEXPR CONDEXPR LABSTAT INITIALIZ INITIALIZLIST NUM DIRECTDECL ENUMERATOR ENUMERATORLIST ENUMSPECIFIER
%type <number> T_NUMBER
%type <string> T_VARIABLE 

%start ROOT

%%


ROOT : TRANSUNIT{ g_root = $1; }




TRANSUNIT: EXTDECL { $$ = $1;}
          | TRANSUNIT EXTDECL { $$ = new TransUnitOperator($1, $2);}

EXTDECL : FUNCDECL { $$ = $1;}
        | DECLARATION { $$ = new GlobalOperator($1);}


FUNCDECL : DECLSPEC DECLARATOR DECLLIST COMPSTAT { $$ = new FuncDeclOperator3($1, $2, $3, $4);}
          | DECLARATOR DECLLIST COMPSTAT { $$ = new FuncDeclOperator2 ( $1, $2, $3);}
          | DECLSPEC DECLARATOR COMPSTAT { $$ = new FuncDeclOperator2 ( $1, $2, $3);}
          | DECLARATOR COMPSTAT { $$ = new FuncDeclOperator1($1, $2);}
          | T_INT T_MAIN T_LBRACKET T_RBRACKET COMPSTAT { $$ = new MainDeclOperator ( $5);}


JUMPSTAT: T_RETURN EXPRESSION T_SEMICOLON{ $$ = new RetOperator2($2);}
        | T_RETURN T_SEMICOLON {$$ = new RetOperator1();} 
        | T_BREAK T_SEMICOLON {$$ = new BreakOperator();}
        | T_CONTINUE T_SEMICOLON {$$ = new ContinueOperator();}

ITSTAT: T_WHILE T_LBRACKET EXPRESSION T_RBRACKET STAT { $$ = new WhileOperator($3, $5);}
      | T_FOR T_LBRACKET EXPRESSION T_SEMICOLON EXPRESSION T_SEMICOLON EXPRESSION  T_RBRACKET STAT {$$ = new ForLoopOperator1($3, $5, $7, $9);}
      | T_FOR T_LBRACKET EXPRESSION T_SEMICOLON EXPRESSION T_SEMICOLON T_RBRACKET STAT{$$ = new ForLoopOperator2($3, $5, $8);}
      | T_FOR T_LBRACKET EXPRESSION T_SEMICOLON T_SEMICOLON EXPRESSION T_RBRACKET STAT {$$ = new ForLoopOperator3($3, $6, $8);}
      | T_FOR T_LBRACKET T_SEMICOLON EXPRESSION T_SEMICOLON EXPRESSION  T_RBRACKET STAT {$$ = new ForLoopOperator4($4, $6, $8);}
      | T_FOR T_LBRACKET EXPRESSION T_SEMICOLON  T_SEMICOLON T_RBRACKET STAT {$$ = new ForLoopOperator5($3, $7);}
      | T_FOR T_LBRACKET  T_SEMICOLON  T_SEMICOLON EXPRESSION T_RBRACKET STAT {$$ = new ForLoopOperator6($5, $7);}
      | T_FOR T_LBRACKET  T_SEMICOLON EXPRESSION T_SEMICOLON T_RBRACKET STAT {$$ = new ForLoopOperator7($4, $7);}
      | T_FOR T_LBRACKET  T_SEMICOLON  T_SEMICOLON  T_RBRACKET STAT {$$ = new ForLoopOperator8($6);}

SELSTAT: T_IF T_LBRACKET EXPRESSION T_RBRACKET STAT { $$ = new IfOperator($3 , $5);}
        | T_IF T_LBRACKET EXPRESSION T_RBRACKET STAT T_ELSE STAT { $$ = new IfElseOperator( $3 , $5 , $7);}
        | T_SWITCH T_LBRACKET EXPRESSION T_RBRACKET STAT{$$ = new SwitchOperator($3, $5);}

COMPSTAT: T_LCURLYBRACKET DECLLIST STATLIST T_RCURLYBRACKET { $$ = new CompStatOperator3($2, $3);}
        | T_LCURLYBRACKET DECLLIST T_RCURLYBRACKET { $$ = new CompStatOperator2($2);}
        | T_LCURLYBRACKET STATLIST T_RCURLYBRACKET { $$ = new CompStatOperator2($2);}
        | T_LCURLYBRACKET T_RCURLYBRACKET  {$$ = new CompStatOperator1();}

EXPRSTAT: EXPRESSION T_SEMICOLON{ $$ = new ExprStatOperator1($1);}
        | T_SEMICOLON { $$ = new ExprStatOperator2();}

LABSTAT: VAR T_COLON STAT{$$ = new LabstatOperator($1, $3);}
        | T_CASE CONDEXPR T_COLON STAT{$$ = new CaseOperator($2, $4);}
        | T_DEFAULT T_COLON STAT {$$ = new DefaultOperator($3);}

STATLIST: STAT { $$ = $1;}
        | STATLIST STAT { $$ = new StatListOperator($1, $2);}

STAT: COMPSTAT { $$ = $1;}
    | SELSTAT {$$ = $1;}
    | ITSTAT { $$ = $1;}
    | JUMPSTAT{ $$ = $1;}
    | EXPRSTAT { $$ = $1;}
    | LABSTAT {$$= $1;}




EXPRESSION: ASSEXPR { $$ = $1;}
      | EXPRESSION T_COMMA ASSEXPR { $$ = new ExpressionOperator($1 , $3);}

DECLLIST: DECLARATION { $$ = $1;}
        | DECLLIST DECLARATION { $$ = new DeclarationListOperator($1, $2);}


DECLARATION: DECLSPEC INITDECLLIST T_SEMICOLON {$$ = new DeclarationOperator($1 , $2);};
          | DECLSPEC T_SEMICOLON {$$ = $1;}

INITDECLLIST: INITDECL { $$ = $1;}
          | INITDECLLIST T_COMMA INITDECL{ $$ = new InitDeclListOperator($1 , $3);}

INITDECL: DECLARATOR { $$ = new DeclaratorOperator($1);}
        | DECLARATOR T_EQUALS INITIALIZ{ $$ = new InitDeclOperator($1 , $3);}

ASSEXPR: CONDEXPR{ $$ = $1;}
        | UNARY T_EQUALS ASSEXPR {$$ = new AssExprOperator($1, $3);}
        | UNARY T_MULTEQUALS ASSEXPR {$$ = new MultEqualsOperator($1, $3);}
        | UNARY T_DIVEQUALS ASSEXPR {$$ = new DivEqualsOperator($1, $3);}
        | UNARY T_MODULOEQUALS ASSEXPR {$$ = new ModuloEqualsOperator($1, $3);}
        | UNARY T_PLUSEQUALS ASSEXPR {$$ = new PlusEqualsOperator($1, $3);}
        | UNARY T_SUBEQUALS ASSEXPR {$$ = new SubEqualsOperator($1, $3);}
        | UNARY T_LEFTSHIFTEQUALS ASSEXPR {$$ = new LeftShiftEqualsOperator($1, $3);}
        | UNARY T_RIGHTSHIFTEQUALS ASSEXPR {$$ = new RightShiftEqualsOperator($1, $3);}
        | UNARY T_ANDEQUALS ASSEXPR {$$ = new AndEqualsOperator($1, $3);}
        | UNARY T_XOREQUALS ASSEXPR {$$ = new XorEqualsOperator($1, $3);}
        | UNARY T_OREQUALS ASSEXPR {$$ = new OrEqualsOperator($1, $3);}

CONDEXPR: LOGOREXPR { $$= $1;}
        | LOGOREXPR T_QMARK EXPRESSION T_COLON CONDEXPR {$$ = new CondExprOperator($1, $3, $5);}

LOGOREXPR: LOGANDEXPR { $$ = $1;}
          | LOGOREXPR T_LOGICALOR LOGANDEXPR {$$ = new LogOrOperator($1 , $3); }

LOGANDEXPR: INCLEXPR { $$ = $1;}
          | LOGANDEXPR T_LOGICALAND INCLEXPR {$$ = new LogAndOperator($1 , $3); }

INCLEXPR : XOREXPR { $$= $1;}
        | INCLEXPR T_BITOR XOREXPR { $$ = new BitOrOperator($1, $3);}

XOREXPR: ANDEXPR {$$= $1;}
        | XOREXPR T_XOR ANDEXPR { $$ = new XorOperator($1, $3);}

ANDEXPR: EQUEXPR { $$ = $1;}
        | ANDEXPR T_BITAND EQUEXPR { $$ = new BitAndOperator($1, $3);}

EQUEXPR: RELEXPR { $$ = $1;}
        | EQUEXPR T_CONDEQUALSTO RELEXPR {$$ = new CondEqualsOperator($1 , $3);}
        | EQUEXPR T_NOTEQ RELEXPR {$$ = new NotEqOperator($1 , $3);}

RELEXPR: SHIFTEXPR { $$ = $1;}
        | RELEXPR T_LESSTHAN SHIFTEXPR { $$ = new LessThanOperator($1 , $3);}
        | RELEXPR T_GREATERTHAN SHIFTEXPR { $$ = new GreaterThanOperator($1 , $3);}
        | RELEXPR T_LESSTHANEQ SHIFTEXPR { $$ = new LessThanEqOperator($1 , $3);}
        | RELEXPR T_GREATERTHANEQ SHIFTEXPR { $$ = new GreaterThanEqOperator($1 , $3);}
INITIALIZLIST: INITIALIZ {$$ = $1;}
        | INITIALIZLIST T_COMMA INITIALIZ {$$ = new InitializerListOperator($1, $3);}
INITIALIZ: ASSEXPR {$$ = $1;}
        | T_LCURLYBRACKET INITIALIZLIST T_RCURLYBRACKET {$$ = new InitializerOperator($2);}
        | T_LCURLYBRACKET INITIALIZLIST T_COMMA T_RCURLYBRACKET {$$ = new Initializer2Operator($2);}
PARAMLIST: PARAMDECL { $$ = $1;}
          | PARAMLIST T_COMMA PARAMDECL { $$ = new ParamOperator($1, $3);}

PARAMDECL : DECLSPEC DECLARATOR {$$ = new ParamDeclOperator($1, $2);}
ENUMSPECIFIER: T_ENUM  T_LCURLYBRACKET ENUMERATORLIST T_RCURLYBRACKET {$$ = new EnumSpecifier1($3);}
          | T_ENUM  VAR T_LCURLYBRACKET ENUMERATORLIST T_RCURLYBRACKET {$$ = new EnumSpecifier1($4);}
          | T_ENUM VAR {$$ = new IntOperator();}
ENUMERATORLIST: ENUMERATOR {$$ = $1;}
          | ENUMERATORLIST T_COMMA ENUMERATOR {$$ = new EnumeratorListOperator($1, $3);}
ENUMERATOR : VAR {$$ = new EnumeratorOperator2($1);}
          | VAR T_EQUALS NUM {$$ = new EnumeratorOperator($1,$3);}




DECLARATOR: DIRECTDECL { $$ = $1;}
           | T_TIMES DIRECTDECL{ $$ = $2;}
          
          





DIRECTDECL: VAR { $$ = $1;}
          | DIRECTDECL T_LSBRACKET ASSEXPR T_RSBRACKET {$$ = new DirectDeclOperator1($1,$3);}
          | DIRECTDECL T_LSBRACKET T_RSBRACKET {$$ = new DirectDeclOperator2($1);}
          | DIRECTDECL T_LBRACKET PARAMLIST T_RBRACKET { $$ = new Decl1Operator($1, $3);}
          | T_LBRACKET DECLARATOR T_RBRACKET { $$ = $2;}
          | DIRECTDECL T_LBRACKET T_RBRACKET { $$ = new Decl2Operator($1);}


SHIFTEXPR: EXPR {$$ = $1;}
        | SHIFTEXPR T_LEFTSHIFT EXPR { $$ = new LeftShiftOperator($1, $3);}
        | SHIFTEXPR T_RIGHTSHIFT EXPR { $$ = new RightShiftOperator($1, $3);}

EXPR : TERM           { $$ = $1; }
        | EXPR T_PLUS TERM{ $$ = new AddOperator( $1, $3 );}
        | EXPR T_MINUS TERM { $$ = new SubOperator( $1, $3 );}

TERM : UNARY          { $$ = $1; }
        | TERM T_TIMES UNARY { $$ = new MulOperator( $1, $3 );}
        | TERM T_DIVIDE UNARY { $$ = new DivOperator( $1, $3 );}
        | TERM T_MODULO UNARY { $$ = new ModuloOperator($1, $3);}

UNARY : POSTFIX        { $$ = $1; }
        | T_MINUS UNARY { $$ = new NegOperator( $2 );}
        | T_PLUS UNARY  { $$ = $2;}
        | T_INCREMENT UNARY {$$ = new  PreIncrementOperator($2);}
        | T_DECREMENT UNARY  { $$ = new  PreDecrementOperator($2);}
        | T_BITAND UNARY { $$ = new AddressOperator($2);}
        | T_TIMES UNARY { $$ = $2;}
        | T_TILDE UNARY {$$ = new BitNotOperator($2);}
        | T_LOGNOT UNARY {$$ = new LogNotOperator($2);}

ARGEXPRLIST : ASSEXPR { $$ = $1;}
            | ARGEXPRLIST T_COMMA ASSEXPR { $$ = new ArgExprListOperator($1, $3);}

POSTFIX: FACTOR { $$ = $1;}
        | POSTFIX T_LBRACKET ARGEXPRLIST T_RBRACKET  { $$ = new PostFixOperator1($1, $3);}
        | POSTFIX T_LBRACKET T_RBRACKET { $$ = new PostFixOperator2($1);}
        | POSTFIX T_LSBRACKET EXPRESSION T_RSBRACKET {$$ = new PostFixOperator3($1,$3);}
        |  UNARY T_INCREMENT{$$ = new PostIncrementOperator($1);}
        |  UNARY T_DECREMENT{$$ = new PostDecrementOperator($1);}

FACTOR : NUM    { $$ = $1;}
       | VAR          { $$ = $1;}
       | T_LBRACKET EXPRESSION T_RBRACKET { $$ = $2; }
NUM : T_NUMBER  { $$ = new Number( $1 );}
VAR :  T_VARIABLE     {$$ = new Variable( *$1 );}


DECLSPEC: T_INT { $$ = new IntOperator();}
        | T_VOID { $$ = new VoidOperator();}
        | ENUMSPECIFIER {$$ = $1;}


%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
