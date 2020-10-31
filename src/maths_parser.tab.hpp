/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SRC_MATHS_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_MATHS_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/maths_parser.y" /* yacc.c:1909  */

  #include "ast.hpp"

  #include <cassert>
  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 57 "src/maths_parser.tab.hpp" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_TIMES = 258,
    T_DIVIDE = 259,
    T_PLUS = 260,
    T_MINUS = 261,
    T_LOGICALAND = 262,
    T_LOGICALOR = 263,
    T_LESSTHAN = 264,
    T_CONDEQUALSTO = 265,
    T_EQUALS = 266,
    T_LBRACKET = 267,
    T_RBRACKET = 268,
    T_LCURLYBRACKET = 269,
    T_RCURLYBRACKET = 270,
    T_COMMA = 271,
    T_SEMICOLON = 272,
    T_LSBRACKET = 273,
    T_RSBRACKET = 274,
    T_NUMBER = 275,
    T_VARIABLE = 276,
    T_INT = 277,
    T_VOID = 278,
    T_IF = 279,
    T_WHILE = 280,
    T_ELSE = 281,
    T_RETURN = 282,
    T_MAIN = 283,
    T_BITAND = 284,
    T_BITOR = 285,
    T_GREATERTHAN = 286,
    T_XOR = 287,
    T_LESSTHANEQ = 288,
    T_GREATERTHANEQ = 289,
    T_NOTEQ = 290,
    T_MULTEQUALS = 291,
    T_DIVEQUALS = 292,
    T_MODULOEQUALS = 293,
    T_PLUSEQUALS = 294,
    T_SUBEQUALS = 295,
    T_LEFTSHIFT = 296,
    T_RIGHTSHIFT = 297,
    T_LEFTSHIFTEQUALS = 298,
    T_RIGHTSHIFTEQUALS = 299,
    T_ANDEQUALS = 300,
    T_XOREQUALS = 301,
    T_OREQUALS = 302,
    T_MODULO = 303,
    T_QMARK = 304,
    T_COLON = 305,
    T_FOR = 306,
    T_DO = 307,
    T_BREAK = 308,
    T_CONTINUE = 309,
    T_SWITCH = 310,
    T_DEFAULT = 311,
    T_CASE = 312,
    T_ENUM = 313,
    T_INCREMENT = 314,
    T_DECREMENT = 315,
    T_LOGNOT = 316,
    T_TILDE = 317
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "src/maths_parser.y" /* yacc.c:1909  */

  const Expression *expr;
  double number;
  std::string *string;

#line 138 "src/maths_parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MATHS_PARSER_TAB_HPP_INCLUDED  */
