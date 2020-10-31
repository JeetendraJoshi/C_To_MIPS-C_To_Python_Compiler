%option noyywrap
%option warn
%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "maths_parser.tab.hpp"

%}

%%
[*]             { return T_TIMES; }
[+]             { return T_PLUS; }
[\/]            { return T_DIVIDE; }
[-]             { return T_MINUS; }
[&][&]			{ return T_LOGICALAND;}
[|][|]			{ return T_LOGICALOR;}
[<]				{ return T_LESSTHAN;}
[>]				{ return T_GREATERTHAN;}
[=][=]			{ return T_CONDEQUALSTO;}
[=]				{ return T_EQUALS;}
[<][<]			{ return T_LEFTSHIFT;}
[>][>]			{ return T_RIGHTSHIFT;}
[<][=]			{ return T_LESSTHANEQ;}
[>][=]			{ return T_GREATERTHANEQ;}
[!][=]			{ return T_NOTEQ;}


[+][+]			{return T_INCREMENT;}
[-][-]			{ return T_DECREMENT;}


[~]				{return T_TILDE;}
[!]				{return T_LOGNOT;}


[*][=]			{ return T_MULTEQUALS;}
[\/][=]			{ return T_DIVEQUALS;}
[%][=]			{ return T_MODULOEQUALS;}
[+][=]			{ return T_PLUSEQUALS;}
[-][=]			{ return T_SUBEQUALS;}

[<][<][=]		{ return T_LEFTSHIFTEQUALS;}
[>][>][=]		{ return T_RIGHTSHIFTEQUALS;}
[&][=]			{ return T_ANDEQUALS;}
[\^][=]			{ return T_XOREQUALS;}
[|][=]			{ return T_OREQUALS;}


[%]				{ return T_MODULO;}
[?]				{ return T_QMARK;}
[:]				{ return T_COLON;}
[\^]			{ return T_XOR;}
[&]				{ return T_BITAND;}
[|]				{ return T_BITOR;}


[\[]             { return T_LSBRACKET; }
[\]]             { return T_RSBRACKET; }
[(]             { return T_LBRACKET; }
[)]             { return T_RBRACKET; }
[{]				{ return T_LCURLYBRACKET;}
[}]				{ return T_RCURLYBRACKET;}
[,]				{ return T_COMMA;}
[;]				{ return T_SEMICOLON;}

main			{ return T_MAIN;}
int				{ return T_INT;}
void			{ return T_VOID;}
if				{ return T_IF;}
while			{ return T_WHILE;}
else			{ return T_ELSE;}
return			{ return T_RETURN;}
for				{ return T_FOR;}
break			{ return T_BREAK;}
continue		{ return T_CONTINUE;}
switch			{ return T_SWITCH;}
case			{ return T_CASE;}
default			{ return T_DEFAULT;}
enum      		{return T_ENUM;}




[0][0-7]+				  { yylval.number = std::stoi(yytext, nullptr,0); return T_NUMBER;}
[0][xX][A-Fa-f0-9]+		  { yylval.number = std::stoi(yytext, nullptr,0); return T_NUMBER;}
[0-9]+          		  { yylval.number=strtod(yytext, 0); return T_NUMBER; }
[A-Za-z_][A-Za-z0-9_]*    { yylval.string=new std::string(yytext); return T_VARIABLE; }

[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
