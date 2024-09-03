%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
"int" {return INT;}
"char" {return STRING;}
"float" {return FLOAT;}
"string" {return STRING;}
"bool" {return BOOL;}
"class" {return CLASS;}
"const" {return CONST;}
"PRIVATE" {return PRIVATE;}
"PUBLIC" {return PUBLIC;}
"end_function" {return END_FUNCTION;}
"function" {return FUNCTION;}
"create_obj" {return CREATE_OBJ;}
"end_class" {return END_CLASS;}
"if" {return IF;}
"then" {return THEN;}
"for" {return FOR;}
"else" {return ELSE;}
"while" {return WHILE;}
"main" {return BGIN;}
"end" {return END;}
"do" {return DO;}
"true" {yylval.val=1; return NR_BOOL;}
"false" {yylval.val=0; return NR_BOOL;}
[_a-zA-Z][_a-zA-Z0-9]* { yylval.name = strdup(yytext) ;return NAME;}
-?[1-9][0-9]*|0 { yylval.val = atoi(yytext); return NR;}
[0-9]+\.[0-9]* {yylval.val = atof(yytext); return NR_FLOAT;}
\"[^"]*\" { yylval.name=strdup(yytext+1); yylval.name[yyleng-2]=0;
			return SIR;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}

 