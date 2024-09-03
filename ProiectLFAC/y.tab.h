/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    CHAR = 259,                    /* CHAR  */
    FLOAT = 260,                   /* FLOAT  */
    STRING = 261,                  /* STRING  */
    BOOL = 262,                    /* BOOL  */
    CLASS = 263,                   /* CLASS  */
    CONST = 264,                   /* CONST  */
    PRIVATE = 265,                 /* PRIVATE  */
    PUBLIC = 266,                  /* PUBLIC  */
    IF = 267,                      /* IF  */
    THEN = 268,                    /* THEN  */
    ASSIGN = 269,                  /* ASSIGN  */
    FOR = 270,                     /* FOR  */
    ELSE = 271,                    /* ELSE  */
    WHILE = 272,                   /* WHILE  */
    BGIN = 273,                    /* BGIN  */
    END = 274,                     /* END  */
    NAME = 275,                    /* NAME  */
    NR = 276,                      /* NR  */
    SIR = 277,                     /* SIR  */
    NR_FLOAT = 278,                /* NR_FLOAT  */
    NR_BOOL = 279,                 /* NR_BOOL  */
    FUNCTION = 280,                /* FUNCTION  */
    END_FUNCTION = 281,            /* END_FUNCTION  */
    END_CLASS = 282,               /* END_CLASS  */
    CREATE_OBJ = 283,              /* CREATE_OBJ  */
    DO = 284                       /* DO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT 258
#define CHAR 259
#define FLOAT 260
#define STRING 261
#define BOOL 262
#define CLASS 263
#define CONST 264
#define PRIVATE 265
#define PUBLIC 266
#define IF 267
#define THEN 268
#define ASSIGN 269
#define FOR 270
#define ELSE 271
#define WHILE 272
#define BGIN 273
#define END 274
#define NAME 275
#define NR 276
#define SIR 277
#define NR_FLOAT 278
#define NR_BOOL 279
#define FUNCTION 280
#define END_FUNCTION 281
#define END_CLASS 282
#define CREATE_OBJ 283
#define DO 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 307 "TemaLFAC.y"
 int val; char *name; 

#line 128 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
