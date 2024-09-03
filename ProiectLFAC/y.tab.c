/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "TemaLFAC.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
extern FILE* yyin;
FILE* symbol_table;
FILE* symbol_table_functions;
extern char* yytext;
extern int yylineno;
int yylex();
int error=0;
int number_of_int_vars = 0;
int number_of_float_vars = 0;
int number_of_char_vars = 0;
int number_of_bool_vars = 0;
int number_of_string_vars = 0;
int number_of_arrays_vars = 0;
int number_of_functions = 0;
int number_of_classes = 0;

void set_error()
{
     error=1;
     printf("Eroare la linia %d: ", yylineno);
}

struct var_int {
    int value;
    char name[32];
    int init;
     int is_const;
} vars_int[32];

struct var_float{
     float value;
     char name[32];
     int init;
     int is_const;
} vars_float[32];

struct var_string{
     char* value;
     char name[32];
     int init;
     int is_const;
}vars_string[32];

struct var_bool{
     bool value;
     char name[32];
     int init;
     int is_const;
}vars_bool[32];

struct var_array{
     char name[32];
     int* values;
     int length;
} vars_arrays[32];

struct var_class{
     char name[32];
} vars_classes[32];

struct var_function{
     char name[32];
} vars_functions[32];

// FUNCTIONS FOR THE INT DECLARATION
int name_exists(char x[])
{
     for(int i=0;i<=number_of_int_vars;i++)
     if(strcmp(x,vars_int[i].name)==0)
     return -1;
     for(int i=0;i<=number_of_float_vars;i++)
     if(strcmp(x,vars_float[i].name)==0)
     return -1;
     for(int i=0;i<=number_of_string_vars;i++)
     if(strcmp(x,vars_string[i].name)==0)
     return -1;
     for(int i=0;i<=number_of_bool_vars;i++)
     if(strcmp(x,vars_bool[i].name)==0)
     return -1;
     for(int i=0;i<=number_of_functions;i++)
     if(strcmp(x,vars_functions[i].name)==0)
     return -1;
     for(int i=0;i<=number_of_classes;i++)
     if(strcmp(x,vars_classes[i].name)==0)
     return -1;
     for(int i=0;i<=number_of_arrays_vars;i++)
     if(strcmp(x,vars_arrays[i].name)==0)
     return -1;

     return 1;
}

void declaration_int(char x[], int _const)
{

     strcpy(vars_int[number_of_int_vars].name, x);
     vars_int[number_of_int_vars].init = 0;
     vars_int[number_of_int_vars].is_const = _const;
     number_of_int_vars++;
}

int if_declared_int(char x[])
{
     if(name_exists(x)==-1)
     return 0;
    for(int i=0;i< number_of_int_vars;i++)
        if(strcmp(x,vars_int[i].name)==0)
        return i;
return -1;
}

int if_initialized_int(char x[]) {
     int i;
     for(i = 0; i < number_of_int_vars; i++)
        if(strcmp(x, vars_int[i].name) == 0)
            if(vars_int[i].init == 0)
                return -1;
            else
                return 1;
     return -1;
}

void assignment_int(int v, int index) {
     vars_int[index].value = v;
     vars_int[index].init = 1;
}

//FUNCTIONS FOR FLOAT DECLARATION

void declaration_float(char x[], int _const) {
     strcpy(vars_float[number_of_float_vars].name, x);
     vars_float[number_of_float_vars].init = 0;
     vars_float[number_of_float_vars].is_const = _const;
     number_of_float_vars++;
}

int if_declared_float(char x[])
{
if(name_exists(x)==-1)
     return 0;
    for(int i=0;i< number_of_float_vars;i++)
        if(strcmp(x,vars_float[i].name)==0)
        return i;
return -1;
}

int if_initialized_float(char x[]) {
     for(int i = 0; i < number_of_float_vars; i++)
        if(strcmp(x, vars_float[i].name) == 0)
            if(vars_float[i].init == 0)
                return -1;
            else
                return 1;
     return -1;
}

void assignment_float(float v, int index) {
     vars_float[index].value = v;
     vars_float[index].init = 1;
}

//FUNCTION FOR STRING DECLARATIONS


void declaration_string(char x[], int _const) {
     strcpy(vars_string[number_of_string_vars].name,x);
     vars_string[number_of_string_vars].init = 0;
     vars_string[number_of_string_vars].is_const = _const;
     number_of_string_vars++;
}
int if_declared_string(char x[])
{
if(name_exists(x)==-1)
     return 0;
     for(int i = 0; i < number_of_string_vars; i++)
          if(strcmp(x, vars_string[i].name) == 0)
               return i;
     return -1;
}

int if_initialized_string(char x[])
{
     for(int i = 0; i < number_of_string_vars; i++)
          if(strcmp(x, vars_string[i].name) == 0)
             if(vars_string[i].init == 0)
                    return -1;
               else
                    return 1;
     return -1;
}

void copy_string(int index, char content[], int size) {
     free(vars_string[index].value);
     vars_string[index].value = (char*) malloc(size);
     strcpy(vars_string[index].value, content);
     vars_string[index].init = 1;
}

void concat_string(int index, char append[], int size) {
     char* aux = (char*) malloc(size + strlen(append) + 1);
     strcpy(aux, vars_string[index].value);
     strcat(aux, append);
     free(vars_string[index].value);
     vars_string[index].value = (char*) malloc(size + strlen(append));
     strcpy(vars_string[index].value, aux);
}

//FUNCTION FOR BOOL DECLARATION

void declaration_bool(char x[], int _const) {
     strcpy(vars_bool[number_of_bool_vars].name, x);
     vars_bool[number_of_bool_vars].init = 0;
     vars_bool[number_of_bool_vars].is_const = _const;
     number_of_bool_vars++;
}

int if_declared_bool(char x[])
{
if(name_exists(x)==-1)
     return 0;
    for(int i=0;i< number_of_bool_vars;i++)
        if(strcmp(x,vars_bool[i].name)==0)
        return i;
return -1;
}

int if_initialized_bool(char x[]) {
     for(int i = 0; i < number_of_bool_vars; i++)
        if(strcmp(x, vars_bool[i].name) == 0)
            if(vars_bool[i].init == 0)
                return -1;
            else
                return 1;
     return -1;
}

void assignment_bool(bool v, int index) {
     vars_bool[index].value = v;
     vars_bool[index].init = 1;
}

//FUNCTION FOR INT ARRAY DECLARATION


void declaration_array(char x[], int size) {
     strcpy(vars_arrays[number_of_arrays_vars].name, x);
     vars_arrays[number_of_arrays_vars].values = (int*) calloc(size,sizeof(int));
     vars_arrays[number_of_arrays_vars].length = size;
     number_of_arrays_vars++;
}

int if_declared_array(char variable_name[]) {
if(name_exists(variable_name)==-1)
     return 0;
     int i;
     for(i = 0; i < number_of_arrays_vars; i++)
         if(strcmp(variable_name, vars_arrays[i].name) == 0)
             return i;
     return -1;
}

void assignment_arrays(char variable_name[], int value, int position, int index)
{
     vars_arrays[index].values[position] = value;
}

//FUNCTIONS FOR CLASS DECLARATIONS

void declaration_classes(char x[]) {
     strcpy(vars_classes[number_of_classes].name, x);
     number_of_classes++;
}

int if_declared_class(char variable_name[]) {
if(name_exists(variable_name)==-1)
     return 0;
     int i;
     for(i = 0; i < number_of_classes; i++)
         if(strcmp(variable_name, vars_classes[i].name) == 0)
             return i;
     return -1;
}

//FUNCTIONS FOR FUNCTION DECLARATIONS

void declaration_function(char x[]) {
     strcpy(vars_functions[number_of_functions].name, x);
     number_of_functions++;
}
int if_declared_function(char variable_name[]) {
if(name_exists(variable_name)==-1)
     return 0;
     int i;
     for(i = 0; i < number_of_functions; i++)
         if(strcmp(variable_name, vars_functions[i].name) == 0)
             return i;
     return -1;
}


#line 377 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 491 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_CHAR = 4,                       /* CHAR  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_BOOL = 7,                       /* BOOL  */
  YYSYMBOL_CLASS = 8,                      /* CLASS  */
  YYSYMBOL_CONST = 9,                      /* CONST  */
  YYSYMBOL_PRIVATE = 10,                   /* PRIVATE  */
  YYSYMBOL_PUBLIC = 11,                    /* PUBLIC  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_THEN = 13,                      /* THEN  */
  YYSYMBOL_ASSIGN = 14,                    /* ASSIGN  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_BGIN = 18,                      /* BGIN  */
  YYSYMBOL_END = 19,                       /* END  */
  YYSYMBOL_NAME = 20,                      /* NAME  */
  YYSYMBOL_NR = 21,                        /* NR  */
  YYSYMBOL_SIR = 22,                       /* SIR  */
  YYSYMBOL_NR_FLOAT = 23,                  /* NR_FLOAT  */
  YYSYMBOL_NR_BOOL = 24,                   /* NR_BOOL  */
  YYSYMBOL_FUNCTION = 25,                  /* FUNCTION  */
  YYSYMBOL_END_FUNCTION = 26,              /* END_FUNCTION  */
  YYSYMBOL_END_CLASS = 27,                 /* END_CLASS  */
  YYSYMBOL_CREATE_OBJ = 28,                /* CREATE_OBJ  */
  YYSYMBOL_DO = 29,                        /* DO  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* '='  */
  YYSYMBOL_36_ = 36,                       /* '#'  */
  YYSYMBOL_37_ = 37,                       /* '@'  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_40_ = 40,                       /* ':'  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_43_ = 43,                       /* '('  */
  YYSYMBOL_44_ = 44,                       /* ')'  */
  YYSYMBOL_45_ = 45,                       /* '<'  */
  YYSYMBOL_46_ = 46,                       /* '>'  */
  YYSYMBOL_47_ = 47,                       /* '!'  */
  YYSYMBOL_48_ = 48,                       /* '|'  */
  YYSYMBOL_49_ = 49,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_progr = 51,                     /* progr  */
  YYSYMBOL_declarations = 52,              /* declarations  */
  YYSYMBOL_classes = 53,                   /* classes  */
  YYSYMBOL_class_create = 54,              /* class_create  */
  YYSYMBOL_functions = 55,                 /* functions  */
  YYSYMBOL_function_call = 56,             /* function_call  */
  YYSYMBOL_params = 57,                    /* params  */
  YYSYMBOL_list = 58,                      /* list  */
  YYSYMBOL_instruction = 59,               /* instruction  */
  YYSYMBOL_assignment = 60,                /* assignment  */
  YYSYMBOL_conditional = 61,               /* conditional  */
  YYSYMBOL_repetitive = 62,                /* repetitive  */
  YYSYMBOL_arithmetic_int = 63,            /* arithmetic_int  */
  YYSYMBOL_arithmetic_float = 64,          /* arithmetic_float  */
  YYSYMBOL_boolean = 65,                   /* boolean  */
  YYSYMBOL_exp_int = 66,                   /* exp_int  */
  YYSYMBOL_exp_float = 67,                 /* exp_float  */
  YYSYMBOL_exp_bool = 68                   /* exp_bool  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   368

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  247

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    36,     2,     2,    49,     2,
      43,    44,    32,    30,     2,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    34,
      45,    35,    46,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,    48,    42,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   315,   315,   317,   320,   334,   350,   367,   381,   398,
     414,   429,   446,   464,   479,   496,   513,   537,   540,   555,
     565,   568,   584,   594,   597,   599,   601,   603,   605,   607,
     609,   612,   615,   617,   619,   621,   623,   627,   648,   667,
     686,   705,   723,   725,   729,   731,   735,   737,   739,   741,
     744,   746,   748,   750,   754,   756,   758,   760,   762,   764,
     766,   768,   770,   772,   774,   776,   778,   780,   782,   784,
     787,   789,   801,   803,   806,   808,   820,   822,   824,   826
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "CHAR", "FLOAT",
  "STRING", "BOOL", "CLASS", "CONST", "PRIVATE", "PUBLIC", "IF", "THEN",
  "ASSIGN", "FOR", "ELSE", "WHILE", "BGIN", "END", "NAME", "NR", "SIR",
  "NR_FLOAT", "NR_BOOL", "FUNCTION", "END_FUNCTION", "END_CLASS",
  "CREATE_OBJ", "DO", "'+'", "'-'", "'*'", "'/'", "';'", "'='", "'#'",
  "'@'", "'['", "']'", "':'", "'{'", "'}'", "'('", "')'", "'<'", "'>'",
  "'!'", "'|'", "'&'", "$accept", "progr", "declarations", "classes",
  "class_create", "functions", "function_call", "params", "list",
  "instruction", "assignment", "conditional", "repetitive",
  "arithmetic_int", "arithmetic_float", "boolean", "exp_int", "exp_float",
  "exp_bool", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-173)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -173,    17,   252,  -173,    28,    46,    -7,    49,   220,    85,
      66,    82,    96,    98,   101,    90,   102,   100,   119,    -3,
    -173,    38,    38,    29,    94,   142,   107,   131,   136,   143,
     166,  -173,   162,  -173,  -173,    38,  -173,   164,   213,  -173,
       4,  -173,   185,  -173,    83,    38,   174,   175,   182,   192,
     252,   208,   140,    38,    38,    38,    38,  -173,   226,  -173,
     234,     4,  -173,   232,   248,  -173,   291,   278,   237,     4,
     292,    83,   303,   138,  -173,  -173,   112,   112,  -173,  -173,
    -173,  -173,   209,     4,     4,     4,     4,  -173,  -173,  -173,
    -173,  -173,   242,   281,   282,   279,   274,   275,   280,  -173,
     165,   300,   301,   302,  -173,  -173,  -173,  -173,  -173,  -173,
       5,  -173,   169,   169,  -173,  -173,  -173,  -173,  -173,  -173,
      74,    36,    74,   304,    38,    38,  -173,   290,   293,   294,
     285,   252,    74,   283,   183,   189,    22,    74,   286,   297,
     247,   217,   168,   310,     4,    83,  -173,    40,   320,   299,
     -14,    -2,   305,   287,   288,   306,    19,    76,   307,   295,
     289,   311,   315,  -173,  -173,   312,   296,   314,   316,   317,
    -173,   253,   258,   318,   319,   263,   321,   252,   309,   313,
      38,    38,   273,    38,   273,    38,    38,    38,     4,     4,
     277,     4,   277,     4,     4,     4,    36,   322,    38,  -173,
     323,  -173,  -173,  -173,  -173,  -173,  -173,  -173,     8,  -173,
    -173,   273,   273,   273,   273,   273,   273,   277,   277,   277,
     277,   277,   277,   324,  -173,   268,  -173,   330,   252,    54,
     329,    72,  -173,  -173,   -12,   334,   325,  -173,   332,   326,
    -173,  -173,  -173,   110,   123,  -173,  -173
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,    17,     1,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     0,    71,    70,     0,    73,     0,     0,     7,
       0,    10,     0,    13,     0,     0,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     6,     0,    74,
       0,     0,    77,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     3,    72,    46,    47,    48,    49,
      16,    75,     0,     0,     0,     0,     0,     9,    12,    79,
      15,     5,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     0,    36,    33,    31,    32,    34,    35,
       0,    76,    50,    51,    52,    53,     8,    11,    14,     3,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       0,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    37,     0,    71,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,    30,     0,     0,
       0,     0,    54,     0,    55,     0,     0,     0,     0,     0,
      62,     0,    63,     0,     0,     0,     0,     0,     0,    28,
       0,    22,    24,    25,    26,    38,    39,    40,     0,     3,
      30,    58,    56,    57,    59,    60,    61,    66,    64,    65,
      67,    68,    69,     0,    30,     0,    29,     0,    20,     0,
       0,     0,    41,    21,     0,    43,     0,    44,     0,     0,
      30,    18,    30,     0,     0,    45,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,  -173,   -31,  -173,  -173,  -130,   204,  -173,  -172,  -173,
    -117,  -173,  -173,  -173,  -173,   -91,   -19,    -8,   -62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     9,   104,    19,   105,   142,    73,   106,
     107,   108,   109,    36,    62,   133,   134,   135,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,   147,    37,    38,   137,   208,    33,    34,     4,    94,
       5,     6,     7,    32,     8,    31,    52,     3,    33,    34,
      96,   181,    32,    97,    12,    98,    68,    59,   100,    35,
     238,   138,    63,   183,    76,    77,    78,    79,   229,   101,
      60,    35,    59,   110,   102,   103,   161,    61,    10,   130,
     227,   178,   231,    82,   189,    60,   136,   124,    33,    34,
     125,    92,    61,    39,    40,    32,    96,   101,   243,    97,
     244,    98,   102,   103,   100,   112,   113,   114,   115,   223,
     173,    35,    11,   176,    96,   101,    13,    97,   131,    98,
     102,   103,   100,    18,    33,    34,   235,    59,   234,    59,
      20,    21,    23,   101,    22,   140,   141,    65,   102,   103,
      60,   191,    60,    52,   237,   177,    24,   132,    25,    61,
      66,    26,    96,   171,    82,    97,    27,    98,    41,    42,
     100,   182,   184,    28,   172,    96,   175,    29,    97,    30,
      98,   101,    45,   100,    55,    56,   102,   103,   190,   192,
      96,    46,   245,    97,   101,    98,    47,    99,   100,   102,
     103,   211,   212,    48,   213,   246,   214,   215,   216,   101,
      53,    54,    55,    56,   102,   103,    43,    44,   228,   225,
     217,   218,    51,   219,    75,   220,   221,   222,   166,    34,
     167,    59,    65,   123,    53,    54,    55,    56,    57,   168,
     124,    85,    86,   125,    60,    66,    49,    64,   126,    69,
      70,   132,   169,    53,    54,    55,    56,    71,   149,    83,
      84,    85,    86,    14,   155,    15,    16,    17,   150,   151,
     152,   153,   154,    72,   156,   157,   158,   159,   160,    83,
      84,    85,    86,    53,    54,    55,    56,    53,    54,    55,
      56,    74,    58,   111,    81,     4,   165,     5,     6,     7,
      80,     8,    83,    84,    85,    86,    87,    53,    54,    55,
      56,    91,    83,    84,    85,    86,   116,    53,    54,    55,
      56,   164,    88,    53,    54,    55,    56,   202,    83,    84,
      85,    86,   203,    83,    84,    85,    86,   206,    53,    54,
      55,    56,   232,    53,    54,    55,    56,    83,    84,    85,
      86,    89,    90,    95,    93,   117,   118,   120,   121,   119,
     127,   128,   129,   122,   139,   143,   146,   148,   144,   145,
     162,   163,   174,   179,   180,   186,   200,   187,   195,   126,
     185,   188,   193,   194,   197,   196,   170,   198,   199,   209,
     239,   201,   204,   205,   210,   207,   233,   226,   236,   241,
       0,     0,     0,   224,     0,     0,   240,   242,   230
};

static const yytype_int16 yycheck[] =
{
      31,   131,    21,    22,   121,   177,    20,    21,     3,    71,
       5,     6,     7,    25,     9,    18,    35,     0,    20,    21,
      12,    35,    25,    15,    31,    17,    45,    23,    20,    43,
      42,   122,    40,    35,    53,    54,    55,    56,   210,    31,
      36,    43,    23,    74,    36,    37,   137,    43,    20,    44,
      42,    11,   224,    61,    35,    36,    20,    35,    20,    21,
      38,    69,    43,    34,    35,    25,    12,    31,   240,    15,
     242,    17,    36,    37,    20,    83,    84,    85,    86,   196,
     142,    43,    36,   145,    12,    31,    37,    15,   119,    17,
      36,    37,    20,     8,    20,    21,    42,    23,   228,    23,
      34,    35,    20,    31,    38,   124,   125,    24,    36,    37,
      36,    35,    36,   132,    42,   146,    20,    43,    20,    43,
      37,    20,    12,   142,   132,    15,    36,    17,    34,    35,
      20,   150,   151,    31,   142,    12,   144,    37,    15,    20,
      17,    31,    35,    20,    32,    33,    36,    37,   156,   157,
      12,    20,    42,    15,    31,    17,    20,    19,    20,    36,
      37,   180,   181,    20,   183,    42,   185,   186,   187,    31,
      30,    31,    32,    33,    36,    37,    34,    35,   209,   198,
     188,   189,    20,   191,    44,   193,   194,   195,    20,    21,
      22,    23,    24,    28,    30,    31,    32,    33,    34,    31,
      35,    32,    33,    38,    36,    37,    40,    22,    43,    35,
      35,    43,    44,    30,    31,    32,    33,    35,    35,    30,
      31,    32,    33,     3,    35,     5,     6,     7,    45,    46,
      47,    48,    49,    41,    45,    46,    47,    48,    49,    30,
      31,    32,    33,    30,    31,    32,    33,    30,    31,    32,
      33,    43,    39,    44,    20,     3,    39,     5,     6,     7,
      34,     9,    30,    31,    32,    33,    34,    30,    31,    32,
      33,    34,    30,    31,    32,    33,    34,    30,    31,    32,
      33,    34,    34,    30,    31,    32,    33,    34,    30,    31,
      32,    33,    34,    30,    31,    32,    33,    34,    30,    31,
      32,    33,    34,    30,    31,    32,    33,    30,    31,    32,
      33,    20,    34,    10,    22,    34,    34,    43,    43,    40,
      20,    20,    20,    43,    20,    35,    41,    44,    35,    35,
      44,    34,    22,    13,    35,    48,    20,    49,    49,    43,
      35,    35,    35,    48,    29,    34,   142,    35,    34,    40,
      16,    34,    34,    34,    41,    34,    26,    34,    29,    27,
      -1,    -1,    -1,    41,    -1,    -1,    41,    41,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    52,     0,     3,     5,     6,     7,     9,    53,
      20,    36,    31,    37,     3,     5,     6,     7,     8,    55,
      34,    35,    38,    20,    20,    20,    20,    36,    31,    37,
      20,    18,    25,    20,    21,    43,    63,    66,    66,    34,
      35,    34,    35,    34,    35,    35,    20,    20,    20,    40,
      52,    20,    66,    30,    31,    32,    33,    34,    39,    23,
      36,    43,    64,    67,    22,    24,    37,    68,    66,    35,
      35,    35,    41,    58,    43,    44,    66,    66,    66,    66,
      34,    20,    67,    30,    31,    32,    33,    34,    34,    20,
      34,    34,    67,    22,    68,    10,    12,    15,    17,    19,
      20,    31,    36,    37,    54,    56,    59,    60,    61,    62,
      52,    44,    67,    67,    67,    67,    34,    34,    34,    40,
      43,    43,    43,    28,    35,    38,    43,    20,    20,    20,
      44,    52,    43,    65,    66,    67,    20,    60,    65,    20,
      66,    66,    57,    35,    35,    35,    41,    55,    44,    35,
      45,    46,    47,    48,    49,    35,    45,    46,    47,    48,
      49,    65,    44,    34,    34,    39,    20,    22,    31,    44,
      56,    66,    67,    68,    22,    67,    68,    52,    11,    13,
      35,    35,    66,    35,    66,    35,    48,    49,    35,    35,
      67,    35,    67,    35,    48,    49,    34,    29,    35,    34,
      20,    34,    34,    34,    34,    34,    34,    34,    58,    40,
      41,    66,    66,    66,    66,    66,    66,    67,    67,    67,
      67,    67,    67,    60,    41,    66,    34,    42,    52,    58,
      44,    58,    34,    26,    55,    42,    29,    42,    42,    16,
      41,    27,    41,    58,    58,    42,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    53,    53,    54,
      55,    55,    56,    57,    57,    57,    57,    57,    57,    57,
      58,    58,    59,    59,    59,    59,    59,    60,    60,    60,
      60,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      64,    64,    64,    64,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      66,    66,    66,    66,    67,    67,    67,    67,    68,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     0,     4,     7,     6,     5,     8,     7,
       5,     8,     7,     5,     8,     7,     7,     0,    15,     4,
       0,    11,     5,     0,     3,     3,     3,     2,     3,     4,
       0,     2,     1,     1,     1,     1,     1,     4,     5,     5,
       5,     7,    12,     8,     8,    11,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     4,     4,     4,
       4,     4,     3,     3,     4,     4,     4,     4,     4,     4,
       1,     1,     3,     1,     1,     2,     3,     1,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* progr: declarations classes functions BGIN declarations list END  */
#line 315 "TemaLFAC.y"
                                                                 {printf("program corect sintactic\n");}
#line 1703 "y.tab.c"
    break;

  case 4: /* declarations: declarations INT NAME ';'  */
#line 321 "TemaLFAC.y"
     {
          if(if_declared_int((yyvsp[-1].name)) == -1)
          {
                declaration_int((yyvsp[-1].name), 0);
                //fprintf(symbol_table, "int main::%s\n", $3);
          }
          else
          {
               set_error();
               printf("Variabila \"%s\" deja a fost declarata.\n", (yyvsp[-1].name));
          }
     }
#line 1720 "y.tab.c"
    break;

  case 5: /* declarations: declarations CONST INT NAME '=' exp_int ';'  */
#line 335 "TemaLFAC.y"
     {
          int index = if_declared_int((yyvsp[-3].name));
          if(index == -1)
          {
               declaration_int((yyvsp[-3].name), 1);
               assignment_int((yyvsp[-1].val), number_of_int_vars-1);
               //fprintf(symbol_table.txt, "const int main::%s\n", $4);
          }
          else
          {
               set_error();
               printf("Variabila \"%s\" deja a fost declarata.\n", (yyvsp[-3].name));
          }
     }
#line 1739 "y.tab.c"
    break;

  case 6: /* declarations: declarations INT NAME '=' exp_int ';'  */
#line 351 "TemaLFAC.y"
     {
          int index = if_declared_int((yyvsp[-3].name));
          if(index == -1)
          {
               declaration_int((yyvsp[-3].name), 0);
               assignment_int((yyvsp[-1].val), number_of_int_vars-1);
               //fprintf(symbol_table, "int main::%s\n", $3);

          }
          else
          {
               set_error();
               printf("Variabila \"%s\" deja a fost declarata.\n", (yyvsp[-3].name));
          }
     }
#line 1759 "y.tab.c"
    break;

  case 7: /* declarations: declarations FLOAT '#' NAME ';'  */
#line 368 "TemaLFAC.y"
     {
          if(if_declared_float((yyvsp[-1].name)) == -1)
          {
                declaration_float((yyvsp[-1].name), 0);
                //fprintf(symbol_table, "float::%s\n", $4);
          }
          else
          {
               set_error();
               printf("Variabila \"%s\" deja a fost declarata.\n", (yyvsp[-1].name));
          }
     }
#line 1776 "y.tab.c"
    break;

  case 8: /* declarations: declarations CONST FLOAT '#' NAME '=' exp_float ';'  */
#line 382 "TemaLFAC.y"
     {
          int index = if_declared_float((yyvsp[-3].name));
          if(index == -1)
          {
               declaration_float((yyvsp[-3].name), 1);
               assignment_float((yyvsp[-1].val), number_of_float_vars-1);
               //fprintf(symbol_table, "const float::%s\n", $5);

          }
          else
          {
               set_error();
               printf("Variabila \"%s\" deja a fost declarata.\n", (yyvsp[-3].name));
          }
     }
#line 1796 "y.tab.c"
    break;

  case 9: /* declarations: declarations FLOAT '#' NAME '=' exp_float ';'  */
#line 399 "TemaLFAC.y"
     {
          int index = if_declared_float((yyvsp[-3].name));
          if(index == -1)
          {
               declaration_float((yyvsp[-3].name), 0);
               assignment_float((yyvsp[-1].val), number_of_float_vars-1);
               //fprintf(symbol_table, "float::%s\n", $4);
          }
          else
          {
               set_error();
               printf("Variabila \"%s\" deja a fost declarata.\n", (yyvsp[-3].name));
          }
     }
#line 1815 "y.tab.c"
    break;

  case 10: /* declarations: declarations STRING '-' NAME ';'  */
#line 415 "TemaLFAC.y"
     {
          if(if_declared_string((yyvsp[-1].name)) == -1)
          {
          declaration_string((yyvsp[-1].name), 0);
          //fprintf(symbol_table, "string::%s\n", $4);

          }
          else
          {
          set_error();
          printf("Variabila \"%s\" deja a fost declarata.\n", (yyvsp[-1].name));
          }
     }
#line 1833 "y.tab.c"
    break;

  case 11: /* declarations: declarations CONST STRING '-' NAME '=' SIR ';'  */
#line 430 "TemaLFAC.y"
     {
          int index = if_declared_string((yyvsp[-3].name));
          if(index == -1)
          {
               declaration_string((yyvsp[-3].name), 1);
               copy_string(number_of_string_vars-1, (yyvsp[-1].name), strlen((yyvsp[-1].name)));
               //fprintf(symbol_table, "const string::%s\n", $5);

          }
          else
          {
               set_error();
               printf("Variabila \"-%s\" deja a fost declarata.\n", (yyvsp[-3].name));
          }
     }
#line 1853 "y.tab.c"
    break;

  case 12: /* declarations: declarations STRING '-' NAME '=' SIR ';'  */
#line 447 "TemaLFAC.y"
     {
          int index=if_declared_string((yyvsp[-3].name));
          if(index == -1)
          {
               declaration_string((yyvsp[-3].name),0);
               copy_string(number_of_string_vars-1, (yyvsp[-1].name), strlen((yyvsp[-1].name)));
                         //fprintf(symbol_table, "string::%s\n", $4);

          }
          else
          {
               set_error();
               printf("Variabila \"-%s\" deja a fost declarata.\n",(yyvsp[-3].name));
          }

     }
#line 1874 "y.tab.c"
    break;

  case 13: /* declarations: declarations BOOL '@' NAME ';'  */
#line 465 "TemaLFAC.y"
     {
          if(if_declared_bool((yyvsp[-1].name)) == -1)
          {
                declaration_bool((yyvsp[-1].name), 0);
                          //fprintf(symbol_table, "bool::%s\n", $4);

          }
          else
          {
               set_error();
               printf("Variabila \"%s\" deja a fost declarata.\n", (yyvsp[-1].name));
          }
     }
#line 1892 "y.tab.c"
    break;

  case 14: /* declarations: declarations CONST BOOL '@' NAME '=' exp_bool ';'  */
#line 480 "TemaLFAC.y"
     {
          int index = if_declared_bool((yyvsp[-3].name));
          if(index == -1)
          {
               declaration_bool((yyvsp[-3].name), 1);
               assignment_bool((yyvsp[-1].val), number_of_bool_vars-1);
                         //fprintf(symbol_table, "const bool::%s\n", $5);

          }
          else
          {
               set_error();
               printf("Variabila \"%s\" deja a fost declarata.\n", (yyvsp[-3].name));
          }
     }
#line 1912 "y.tab.c"
    break;

  case 15: /* declarations: declarations BOOL '@' NAME '=' exp_bool ';'  */
#line 497 "TemaLFAC.y"
     {
          int index = if_declared_bool((yyvsp[-3].name));
          if(index == -1)
          {
               declaration_bool((yyvsp[-3].name), 0);
               assignment_bool((yyvsp[-1].val), number_of_bool_vars-1);
                         //fprintf(symbol_table, "bool::%s\n", $4);

          }
          else
          {
               set_error();
               printf("Variabila \"%s\" deja a fost declarata.\n", (yyvsp[-3].name));
          }
     }
#line 1932 "y.tab.c"
    break;

  case 16: /* declarations: declarations INT NAME '[' exp_int ']' ';'  */
#line 514 "TemaLFAC.y"
          {
          if((yyvsp[-2].val)<0)
          {
               set_error();
               printf("Size-ul array-ului %s nu poate fi negativ.\n", (yyvsp[-4].name));
          }
          else if((yyvsp[-2].val)>10000)
          {
               set_error();
               printf("Nu am alocat array-ul \"%s\". Size prea mare.\n", (yyvsp[-4].name));
          }
          else if(if_declared_array((yyvsp[-4].name)) == -1 && if_declared_int((yyvsp[-4].name)) == -1)
          {
               declaration_array((yyvsp[-4].name), (yyvsp[-2].val));
               //fprintf(symbol_table, "array[%d] main::%s\n", $5, $3);
          }
          else
          {
          set_error();
          printf("Variabila \"%s\" deja a fost declarata.\n", (yyvsp[-4].name));
          }
     }
#line 1959 "y.tab.c"
    break;

  case 18: /* classes: classes CLASS NAME ':' '{' PRIVATE ':' declarations functions PUBLIC ':' declarations functions '}' END_CLASS  */
#line 541 "TemaLFAC.y"
     {
          int index=if_declared_class((yyvsp[-12].name));
          if(index == -1)
          {
          declaration_classes((yyvsp[-12].name));
          }
          else
          {
          set_error();
          printf("Clasa \"%s\" deja a fost declarata.\n", (yyvsp[-12].name));
          }
     }
#line 1976 "y.tab.c"
    break;

  case 19: /* class_create: NAME CREATE_OBJ NAME ';'  */
#line 556 "TemaLFAC.y"
     {
          int index=if_declared_class((yyvsp[-3].name));
          if(index==-1)
          {
               set_error();
               printf("Clasa \"%s\" nu a fost declarata. \n ",(yyvsp[-3].name));
          }
     }
#line 1989 "y.tab.c"
    break;

  case 21: /* functions: functions FUNCTION NAME '(' declarations ')' '{' declarations list '}' END_FUNCTION  */
#line 569 "TemaLFAC.y"
     {
          if(if_declared_function((yyvsp[-8].name)) == -1)
          {
               declaration_function((yyvsp[-8].name));
               //fprintf(symbol_table_functions, "FUNCTION::%s\n", $2);

          }
          else
          {
          set_error();
          printf("Functia \"%s\" deja a fost declarata.\n", (yyvsp[-8].name));
          }
     }
#line 2007 "y.tab.c"
    break;

  case 22: /* function_call: NAME '(' params ')' ';'  */
#line 585 "TemaLFAC.y"
     {
          int index = if_declared_function((yyvsp[-4].name));
          if(index==-1)
          {
               set_error();
               printf("Functia \"%s\" nu a fost declarata.\n", (yyvsp[-4].name));
          }
     }
#line 2020 "y.tab.c"
    break;

  case 37: /* assignment: NAME '=' exp_int ';'  */
#line 628 "TemaLFAC.y"
     {
          int index=if_declared_int((yyvsp[-3].name));
          if(index== -1)
          {
          set_error();
          printf("Variabila \"%s\" nu a fost declarata.\n", (yyvsp[-3].name));
          }
          else if(vars_int[index].is_const == 1)
          {
          set_error();
          printf("Variabila \"%s\" nu poate fi modificata.\n", (yyvsp[-3].name));
          }
          else if(error==0)
          {assignment_int((yyvsp[-1].val),index);
        //fprintf(symbol_table_functions, "int ::%s\n", $3);
          }


     }
#line 2044 "y.tab.c"
    break;

  case 38: /* assignment: '-' NAME '=' SIR ';'  */
#line 649 "TemaLFAC.y"
     {
          int index=if_declared_string((yyvsp[-3].name));
          if(index == -1)
          {
          set_error();
          printf("Variabila \"-%s\" nu a fost declarata.\n", (yyvsp[-3].name));
          }
          else if(vars_string[index].is_const == 1)
          {
          set_error();
          printf("Variabila \"-%s\" nu poate fi modificata.\n", (yyvsp[-3].name));
          }
          else if(error==0)
          {copy_string(index ,(yyvsp[-1].name), strlen((yyvsp[-1].name)));
            //fprintf(symbol_table_functions, "sir ::%s\n", $4);
}
     }
#line 2066 "y.tab.c"
    break;

  case 39: /* assignment: '#' NAME '=' exp_float ';'  */
#line 668 "TemaLFAC.y"
     {
          int index=if_declared_float((yyvsp[-3].name));
          if(index== -1)
          {
          set_error();
          printf("Variabila \"%s\" nu a fost declarata.\n", (yyvsp[-3].name));
          }
          else if(vars_float[index].is_const == 1)
          {
          set_error();
          printf("Variabila \"%s\" nu poate fi modificata.\n", (yyvsp[-3].name));
          }
          else if(error==0)
          {assignment_float((yyvsp[-1].val),index);
                                    //fprintf(symbol_table_functions, "float ::%s\n", $4);
}
     }
#line 2088 "y.tab.c"
    break;

  case 40: /* assignment: '@' NAME '=' exp_bool ';'  */
#line 687 "TemaLFAC.y"
     {
          int index=if_declared_bool((yyvsp[-3].name));
          if(index== -1)
          {
          set_error();
          printf("Variabila \"%s\" nu a fost declarata.\n", (yyvsp[-3].name));
          }
          else if(vars_bool[index].is_const == 1)
          {
          set_error();
          printf("Variabila \"%s\" nu poate fi modificata.\n", (yyvsp[-3].name));
          }
          else if(error==0)
          {assignment_bool((yyvsp[-1].val),index);
                                    //fprintf(symbol_table_functions, "bool ::%s\n", $4);
}
     }
#line 2110 "y.tab.c"
    break;

  case 41: /* assignment: NAME '[' exp_int ']' '=' exp_int ';'  */
#line 706 "TemaLFAC.y"
     {
          int index=if_declared_array((yyvsp[-6].name));
          if(index == -1)
          {
               set_error();
               printf("Variabila \"%s\" nu a fost declarata.\n", (yyvsp[-6].name));
          }
          else if((yyvsp[-4].val)<0 || (yyvsp[-4].val)>=vars_arrays[index].length)
          {
               set_error();
               printf("Index out of range.\n");
          }
          else if(error==0)
               assignment_arrays((yyvsp[-6].name), (yyvsp[-1].val), (yyvsp[-4].val), index);
     }
#line 2130 "y.tab.c"
    break;

  case 46: /* arithmetic_int: exp_int '+' exp_int  */
#line 735 "TemaLFAC.y"
                        { (yyval.val) = (yyvsp[-2].val) + (yyvsp[0].val); }
#line 2136 "y.tab.c"
    break;

  case 47: /* arithmetic_int: exp_int '-' exp_int  */
#line 737 "TemaLFAC.y"
                        { (yyval.val) = (yyvsp[-2].val) - (yyvsp[0].val); }
#line 2142 "y.tab.c"
    break;

  case 48: /* arithmetic_int: exp_int '*' exp_int  */
#line 739 "TemaLFAC.y"
                        { (yyval.val) = (yyvsp[-2].val) * (yyvsp[0].val); }
#line 2148 "y.tab.c"
    break;

  case 49: /* arithmetic_int: exp_int '/' exp_int  */
#line 741 "TemaLFAC.y"
                        { (yyval.val) = (yyvsp[-2].val) / (yyvsp[0].val); }
#line 2154 "y.tab.c"
    break;

  case 50: /* arithmetic_float: exp_float '+' exp_float  */
#line 744 "TemaLFAC.y"
                            { (yyval.val) = (yyvsp[-2].val) + (yyvsp[0].val); }
#line 2160 "y.tab.c"
    break;

  case 51: /* arithmetic_float: exp_float '-' exp_float  */
#line 746 "TemaLFAC.y"
                            { (yyval.val) = (yyvsp[-2].val) - (yyvsp[0].val); }
#line 2166 "y.tab.c"
    break;

  case 52: /* arithmetic_float: exp_float '*' exp_float  */
#line 748 "TemaLFAC.y"
                            { (yyval.val) = (yyvsp[-2].val) * (yyvsp[0].val); }
#line 2172 "y.tab.c"
    break;

  case 53: /* arithmetic_float: exp_float '/' exp_float  */
#line 750 "TemaLFAC.y"
                            { (yyval.val) = (yyvsp[-2].val) / (yyvsp[0].val); }
#line 2178 "y.tab.c"
    break;

  case 54: /* boolean: exp_int '<' exp_int  */
#line 754 "TemaLFAC.y"
                        { (yyval.val) = (yyvsp[-2].val) < (yyvsp[0].val); }
#line 2184 "y.tab.c"
    break;

  case 55: /* boolean: exp_int '>' exp_int  */
#line 756 "TemaLFAC.y"
                        { (yyval.val) = (yyvsp[-2].val) > (yyvsp[0].val); }
#line 2190 "y.tab.c"
    break;

  case 56: /* boolean: exp_int '<' '=' exp_int  */
#line 758 "TemaLFAC.y"
                           { (yyval.val) = (yyvsp[-3].val) <= (yyvsp[0].val); }
#line 2196 "y.tab.c"
    break;

  case 57: /* boolean: exp_int '>' '=' exp_int  */
#line 760 "TemaLFAC.y"
                           { (yyval.val) = (yyvsp[-3].val) >= (yyvsp[0].val); }
#line 2202 "y.tab.c"
    break;

  case 58: /* boolean: exp_int '=' '=' exp_int  */
#line 762 "TemaLFAC.y"
                           { (yyval.val) = (yyvsp[-3].val) == (yyvsp[0].val); }
#line 2208 "y.tab.c"
    break;

  case 59: /* boolean: exp_int '!' '=' exp_int  */
#line 764 "TemaLFAC.y"
                           { (yyval.val) = (yyvsp[-3].val) != (yyvsp[0].val); }
#line 2214 "y.tab.c"
    break;

  case 60: /* boolean: exp_int '|' '|' exp_int  */
#line 766 "TemaLFAC.y"
                           { (yyval.val) = (yyvsp[-3].val) || (yyvsp[0].val); }
#line 2220 "y.tab.c"
    break;

  case 61: /* boolean: exp_int '&' '&' exp_int  */
#line 768 "TemaLFAC.y"
                           { (yyval.val) = (yyvsp[-3].val) && (yyvsp[0].val); }
#line 2226 "y.tab.c"
    break;

  case 62: /* boolean: exp_float '<' exp_float  */
#line 770 "TemaLFAC.y"
                            { (yyval.val) = (yyvsp[-2].val) < (yyvsp[0].val); }
#line 2232 "y.tab.c"
    break;

  case 63: /* boolean: exp_float '>' exp_float  */
#line 772 "TemaLFAC.y"
                            { (yyval.val) = (yyvsp[-2].val) > (yyvsp[0].val); }
#line 2238 "y.tab.c"
    break;

  case 64: /* boolean: exp_float '<' '=' exp_float  */
#line 774 "TemaLFAC.y"
                               { (yyval.val) = (yyvsp[-3].val) <= (yyvsp[0].val); }
#line 2244 "y.tab.c"
    break;

  case 65: /* boolean: exp_float '>' '=' exp_float  */
#line 776 "TemaLFAC.y"
                               { (yyval.val) = (yyvsp[-3].val) >= (yyvsp[0].val); }
#line 2250 "y.tab.c"
    break;

  case 66: /* boolean: exp_float '=' '=' exp_float  */
#line 778 "TemaLFAC.y"
                               { (yyval.val) = (yyvsp[-3].val) == (yyvsp[0].val); }
#line 2256 "y.tab.c"
    break;

  case 67: /* boolean: exp_float '!' '=' exp_float  */
#line 780 "TemaLFAC.y"
                               { (yyval.val) = (yyvsp[-3].val) != (yyvsp[0].val); }
#line 2262 "y.tab.c"
    break;

  case 68: /* boolean: exp_float '|' '|' exp_float  */
#line 782 "TemaLFAC.y"
                               { (yyval.val) = (yyvsp[-3].val) || (yyvsp[0].val); }
#line 2268 "y.tab.c"
    break;

  case 69: /* boolean: exp_float '&' '&' exp_float  */
#line 784 "TemaLFAC.y"
                               { (yyval.val) = (yyvsp[-3].val) && (yyvsp[0].val); }
#line 2274 "y.tab.c"
    break;

  case 70: /* exp_int: NR  */
#line 787 "TemaLFAC.y"
        { (yyval.val) = (yyvsp[0].val); }
#line 2280 "y.tab.c"
    break;

  case 71: /* exp_int: NAME  */
#line 789 "TemaLFAC.y"
         { int index = if_declared_int((yyvsp[0].name));
      if(index == -1)
      {
      set_error(); printf("Variabila \"%s\" nu a fost declarata ca int.\n", (yyvsp[0].name));
      }
      else if (if_initialized_int((yyvsp[0].name)) == -1)
      {
      set_error();
      printf("Variabila \"%s\" nu a fost initializata sau nu este de tip int .\n", (yyvsp[0].name));
      }
      else (yyval.val) = vars_int[index].value; }
#line 2296 "y.tab.c"
    break;

  case 72: /* exp_int: '(' exp_int ')'  */
#line 801 "TemaLFAC.y"
                      { (yyval.val) = (yyvsp[-1].val);}
#line 2302 "y.tab.c"
    break;

  case 74: /* exp_float: NR_FLOAT  */
#line 806 "TemaLFAC.y"
              { (yyval.val) = (yyvsp[0].val); }
#line 2308 "y.tab.c"
    break;

  case 75: /* exp_float: '#' NAME  */
#line 808 "TemaLFAC.y"
             { int index = if_declared_float((yyvsp[0].name));
      if(index == -1)
      {
      set_error(); printf("Variabila \"%s\" nu a fost declarata ca float.\n", (yyvsp[0].name));
      }
      else if (if_initialized_float((yyvsp[0].name)) == -1)
      {
      set_error();
      printf("Variabila \"%s\" nu a fost initializata sau nu este de tip float.\n", (yyvsp[0].name));
      }
      else (yyval.val) = vars_float[index].value; }
#line 2324 "y.tab.c"
    break;

  case 76: /* exp_float: '(' exp_float ')'  */
#line 820 "TemaLFAC.y"
                        { (yyval.val) = (yyvsp[-1].val); }
#line 2330 "y.tab.c"
    break;

  case 78: /* exp_bool: NR_BOOL  */
#line 824 "TemaLFAC.y"
              { (yyval.val) = (yyvsp[0].val); }
#line 2336 "y.tab.c"
    break;

  case 79: /* exp_bool: '@' NAME  */
#line 826 "TemaLFAC.y"
              { int index = if_declared_bool((yyvsp[0].name));
      if(index == -1)
      {
      set_error(); printf("Variabila \"%s\" nu a fost declarata ca bool.\n", (yyvsp[0].name));
      }
      else if (if_initialized_bool((yyvsp[0].name)) == -1)
      {
      set_error();
      printf("Variabila \"%s\" nu a fost initializata sau nu este de tip bool.\n", (yyvsp[0].name));
      }
      else (yyval.val) = vars_bool[index].value; }
#line 2352 "y.tab.c"
    break;


#line 2356 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 838 "TemaLFAC.y"

int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){

symbol_table=fopen("symbol_table.txt","w");
yyin=fopen(argv[1],"r");
yyparse();

printf("am ajuns in main");
for (int i=0;i<number_of_int_vars;i++) {
          if (vars_int[i].is_const) 
          fprintf(symbol_table, "const ");
          fprintf(symbol_table, "int :%s  -> %d\n", vars_int[i].name, vars_int[i].value);
     }
     for (int i=0;i<number_of_string_vars;i++) {
          if (vars_string[i].is_const) 
          fprintf(symbol_table, "const ");
          fprintf(symbol_table, "string :%s    -> %s\n", vars_string[i].name, vars_string[i].value);
     }
     for (int i=0;i<number_of_float_vars;i++) {
          if (vars_float[i].is_const) 
          fprintf(symbol_table, "const ");
          fprintf(symbol_table, "float :%s    -> %f\n", vars_float[i].name, vars_float[i].value);
     }
     for (int i=0;i<number_of_bool_vars;i++) {
          if (vars_bool[i].is_const) 
          fprintf(symbol_table, "const ");
          fprintf(symbol_table, "bool :%s    -> %d\n", vars_bool[i].name, vars_bool[i].value);
     }
     for (int i=0;i<number_of_arrays_vars;i++) {
          fprintf(symbol_table, "array[%d] :%s -> ",vars_arrays[i].length,  vars_arrays[i].name);
          for(int j = 0; j<vars_arrays[i].length-1;j++)
               fprintf(symbol_table, " %d, ", vars_arrays[i].values[j]);
               fprintf(symbol_table, "%d\n", vars_arrays[i].values[vars_arrays[i].length-1]);
     }

     for (int i=0;i<number_of_functions;i++) {
          fprintf(symbol_table, "def :%s()\n", vars_functions[i].name);
     }

     for (int i=0;i<number_of_classes;i++) {
          fprintf(symbol_table, "class :%s()\n", vars_classes[i].name);
     }

}
