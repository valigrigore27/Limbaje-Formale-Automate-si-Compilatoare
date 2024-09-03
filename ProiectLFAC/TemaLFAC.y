%{
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

%}
%token INT CHAR FLOAT STRING BOOL CLASS CONST PRIVATE PUBLIC IF THEN ASSIGN FOR ELSE WHILE BGIN END NAME NR SIR NR_FLOAT NR_BOOL FUNCTION END_FUNCTION END_CLASS CREATE_OBJ DO
%union { int val; char *name; }
%type<name> NAME SIR
%type<val> NR NR_FLOAT NR_BOOL exp_int exp_float exp_bool arithmetic_int arithmetic_float boolean
%start progr
%left '+' '-'
%left '*' '/'
%%

progr: declarations classes functions BGIN declarations list END {printf("program corect sintactic\n");}
     ;
declarations :
          /*EMPTY*/
          |
          declarations INT NAME ';'
     {
          if(if_declared_int($3) == -1)
          {
                declaration_int($3, 0);
                //fprintf(symbol_table, "int main::%s\n", $3);
          }
          else
          {
               set_error();
               printf("Variabila \"%s\" deja a fost declarata.\n", $3);
          }
     }
          |
          declarations CONST INT NAME '=' exp_int ';'
     {
          int index = if_declared_int($4);
          if(index == -1)
          {
               declaration_int($4, 1);
               assignment_int($6, number_of_int_vars-1);
               //fprintf(symbol_table.txt, "const int main::%s\n", $4);
          }
          else
          {
               set_error();
               printf("Variabila \"%s\" deja a fost declarata.\n", $4);
          }
     }
          |
          declarations INT NAME '=' exp_int ';'
     {
          int index = if_declared_int($3);
          if(index == -1)
          {
               declaration_int($3, 0);
               assignment_int($5, number_of_int_vars-1);
               //fprintf(symbol_table, "int main::%s\n", $3);

          }
          else
          {
               set_error();
               printf("Variabila \"%s\" deja a fost declarata.\n", $3);
          }
     }
          |
          declarations FLOAT '#' NAME ';'
     {
          if(if_declared_float($4) == -1)
          {
                declaration_float($4, 0);
                //fprintf(symbol_table, "float::%s\n", $4);
          }
          else
          {
               set_error();
               printf("Variabila \"%s\" deja a fost declarata.\n", $4);
          }
     }
          |
          declarations CONST FLOAT '#' NAME '=' exp_float ';'
     {
          int index = if_declared_float($5);
          if(index == -1)
          {
               declaration_float($5, 1);
               assignment_float($7, number_of_float_vars-1);
               //fprintf(symbol_table, "const float::%s\n", $5);

          }
          else
          {
               set_error();
               printf("Variabila \"%s\" deja a fost declarata.\n", $5);
          }
     }
          |
          declarations FLOAT '#' NAME '=' exp_float ';'
     {
          int index = if_declared_float($4);
          if(index == -1)
          {
               declaration_float($4, 0);
               assignment_float($6, number_of_float_vars-1);
               //fprintf(symbol_table, "float::%s\n", $4);
          }
          else
          {
               set_error();
               printf("Variabila \"%s\" deja a fost declarata.\n", $4);
          }
     }
          |
          declarations STRING '-' NAME ';'
     {
          if(if_declared_string($4) == -1)
          {
          declaration_string($4, 0);
          //fprintf(symbol_table, "string::%s\n", $4);

          }
          else
          {
          set_error();
          printf("Variabila \"%s\" deja a fost declarata.\n", $4);
          }
     }
          |
          declarations CONST STRING '-' NAME '=' SIR ';'
     {
          int index = if_declared_string($5);
          if(index == -1)
          {
               declaration_string($5, 1);
               copy_string(number_of_string_vars-1, $7, strlen($7));
               //fprintf(symbol_table, "const string::%s\n", $5);

          }
          else
          {
               set_error();
               printf("Variabila \"-%s\" deja a fost declarata.\n", $5);
          }
     }
          |
          declarations STRING '-' NAME '=' SIR ';'
     {
          int index=if_declared_string($4);
          if(index == -1)
          {
               declaration_string($4,0);
               copy_string(number_of_string_vars-1, $6, strlen($6));
                         //fprintf(symbol_table, "string::%s\n", $4);

          }
          else
          {
               set_error();
               printf("Variabila \"-%s\" deja a fost declarata.\n",$4);
          }

     }
          |
          declarations BOOL '@' NAME ';'
     {
          if(if_declared_bool($4) == -1)
          {
                declaration_bool($4, 0);
                          //fprintf(symbol_table, "bool::%s\n", $4);

          }
          else
          {
               set_error();
               printf("Variabila \"%s\" deja a fost declarata.\n", $4);
          }
     }
          |
          declarations CONST BOOL '@' NAME '=' exp_bool ';'
     {
          int index = if_declared_bool($5);
          if(index == -1)
          {
               declaration_bool($5, 1);
               assignment_bool($7, number_of_bool_vars-1);
                         //fprintf(symbol_table, "const bool::%s\n", $5);

          }
          else
          {
               set_error();
               printf("Variabila \"%s\" deja a fost declarata.\n", $5);
          }
     }
          |
          declarations BOOL '@' NAME '=' exp_bool ';'
     {
          int index = if_declared_bool($4);
          if(index == -1)
          {
               declaration_bool($4, 0);
               assignment_bool($6, number_of_bool_vars-1);
                         //fprintf(symbol_table, "bool::%s\n", $4);

          }
          else
          {
               set_error();
               printf("Variabila \"%s\" deja a fost declarata.\n", $4);
          }
     }
          |
          declarations INT NAME '[' exp_int ']' ';'
          {
          if($5<0)
          {
               set_error();
               printf("Size-ul array-ului %s nu poate fi negativ.\n", $3);
          }
          else if($5>10000)
          {
               set_error();
               printf("Nu am alocat array-ul \"%s\". Size prea mare.\n", $3);
          }
          else if(if_declared_array($3) == -1 && if_declared_int($3) == -1)
          {
               declaration_array($3, $5);
               //fprintf(symbol_table, "array[%d] main::%s\n", $5, $3);
          }
          else
          {
          set_error();
          printf("Variabila \"%s\" deja a fost declarata.\n", $3);
          }
     }

classes :
     /*EMPTY*/
     |
     classes CLASS NAME ':' '{' PRIVATE ':' declarations functions PUBLIC ':' declarations functions '}' END_CLASS
     {
          int index=if_declared_class($3);
          if(index == -1)
          {
          declaration_classes($3);
          }
          else
          {
          set_error();
          printf("Clasa \"%s\" deja a fost declarata.\n", $3);
          }
     }

class_create:
     NAME CREATE_OBJ NAME ';'
     {
          int index=if_declared_class($1);
          if(index==-1)
          {
               set_error();
               printf("Clasa \"%s\" nu a fost declarata. \n ",$1);
          }
     }

functions:
     /*EMPTY*/
     |
     functions FUNCTION NAME '(' declarations ')' '{' declarations list '}' END_FUNCTION
     {
          if(if_declared_function($3) == -1)
          {
               declaration_function($3);
               //fprintf(symbol_table_functions, "FUNCTION::%s\n", $2);

          }
          else
          {
          set_error();
          printf("Functia \"%s\" deja a fost declarata.\n", $3);
          }
     }

function_call:
          NAME '(' params ')' ';'
     {
          int index = if_declared_function($1);
          if(index==-1)
          {
               set_error();
               printf("Functia \"%s\" nu a fost declarata.\n", $1);
          }
     }

params:
     /*EMPTY*/
     |
     params exp_int ';'
     |
     params exp_float ';'
     |
     params exp_bool ';'
     |
     params function_call
     |
     params SIR ';'
     |
     params '-' NAME ';'

list:
     /*EMPTY*/
     |
     list instruction

instruction:
     assignment
     |
     function_call
     |
     conditional
     |
     repetitive
     |
     class_create
     ;

assignment:
     NAME '=' exp_int ';'
     {
          int index=if_declared_int($1);
          if(index== -1)
          {
          set_error();
          printf("Variabila \"%s\" nu a fost declarata.\n", $1);
          }
          else if(vars_int[index].is_const == 1)
          {
          set_error();
          printf("Variabila \"%s\" nu poate fi modificata.\n", $1);
          }
          else if(error==0)
          {assignment_int($3,index);
        //fprintf(symbol_table_functions, "int ::%s\n", $3);
          }


     }
     |
     '-' NAME '=' SIR ';'
     {
          int index=if_declared_string($2);
          if(index == -1)
          {
          set_error();
          printf("Variabila \"-%s\" nu a fost declarata.\n", $2);
          }
          else if(vars_string[index].is_const == 1)
          {
          set_error();
          printf("Variabila \"-%s\" nu poate fi modificata.\n", $2);
          }
          else if(error==0)
          {copy_string(index ,$4, strlen($4));
            //fprintf(symbol_table_functions, "sir ::%s\n", $4);
}
     }
     |
     '#' NAME '=' exp_float ';'
     {
          int index=if_declared_float($2);
          if(index== -1)
          {
          set_error();
          printf("Variabila \"%s\" nu a fost declarata.\n", $2);
          }
          else if(vars_float[index].is_const == 1)
          {
          set_error();
          printf("Variabila \"%s\" nu poate fi modificata.\n", $2);
          }
          else if(error==0)
          {assignment_float($4,index);
                                    //fprintf(symbol_table_functions, "float ::%s\n", $4);
}
     }
     |
      '@' NAME '=' exp_bool ';'
     {
          int index=if_declared_bool($2);
          if(index== -1)
          {
          set_error();
          printf("Variabila \"%s\" nu a fost declarata.\n", $2);
          }
          else if(vars_bool[index].is_const == 1)
          {
          set_error();
          printf("Variabila \"%s\" nu poate fi modificata.\n", $2);
          }
          else if(error==0)
          {assignment_bool($4,index);
                                    //fprintf(symbol_table_functions, "bool ::%s\n", $4);
}
     }
     |
     NAME '[' exp_int ']' '=' exp_int ';'
     {
          int index=if_declared_array($1);
          if(index == -1)
          {
               set_error();
               printf("Variabila \"%s\" nu a fost declarata.\n", $1);
          }
          else if($3<0 || $3>=vars_arrays[index].length)
          {
               set_error();
               printf("Index out of range.\n");
          }
          else if(error==0)
               assignment_arrays($1, $6, $3, index);
     }

conditional:
     IF '(' boolean ')' THEN '{' list '}' ELSE '{' list '}'
     |
     IF '(' boolean ')' THEN '{' list '}'
     ;

repetitive:
     WHILE '(' boolean ')' DO '{' list '}'
     |
     FOR '(' assignment boolean ';' assignment ')' DO '{' list '}'
     ;

arithmetic_int:
    exp_int '+' exp_int { $$ = $1 + $3; }
    |
    exp_int '-' exp_int { $$ = $1 - $3; }
    |
    exp_int '*' exp_int { $$ = $1 * $3; }
    |
    exp_int '/' exp_int { $$ = $1 / $3; }

arithmetic_float:
    exp_float '+' exp_float { $$ = $1 + $3; }
    |
    exp_float '-' exp_float { $$ = $1 - $3; }
    |
    exp_float '*' exp_float { $$ = $1 * $3; }
    |
    exp_float '/' exp_float { $$ = $1 / $3; }


boolean:
    exp_int '<' exp_int { $$ = $1 < $3; }
    |
    exp_int '>' exp_int { $$ = $1 > $3; }
    |
    exp_int '<''=' exp_int { $$ = $1 <= $4; }
    |
    exp_int '>''=' exp_int { $$ = $1 >= $4; }
    |
    exp_int '=''=' exp_int { $$ = $1 == $4; }
    |
    exp_int '!''=' exp_int { $$ = $1 != $4; }
    |
    exp_int '|''|' exp_int { $$ = $1 || $4; }
    |
    exp_int '&''&' exp_int { $$ = $1 && $4; }
    |
    exp_float '<' exp_float { $$ = $1 < $3; }
    |
    exp_float '>' exp_float { $$ = $1 > $3; }
    |
    exp_float '<''=' exp_float { $$ = $1 <= $4; }
    |
    exp_float '>''=' exp_float { $$ = $1 >= $4; }
    |
    exp_float '=''=' exp_float { $$ = $1 == $4; }
    |
    exp_float '!''=' exp_float { $$ = $1 != $4; }
    |
    exp_float '|''|' exp_float { $$ = $1 || $4; }
    |
    exp_float '&''&' exp_float { $$ = $1 && $4; }

exp_int:
     NR { $$ = $1; }
    |
    NAME { int index = if_declared_int($1);
      if(index == -1)
      {
      set_error(); printf("Variabila \"%s\" nu a fost declarata ca int.\n", $1);
      }
      else if (if_initialized_int($1) == -1)
      {
      set_error();
      printf("Variabila \"%s\" nu a fost initializata sau nu este de tip int .\n", $1);
      }
      else $$ = vars_int[index].value; }
      |
      '(' exp_int ')' { $$ = $2;}
      |
      arithmetic_int

exp_float:
     NR_FLOAT { $$ = $1; }
    |
    '#' NAME { int index = if_declared_float($2);
      if(index == -1)
      {
      set_error(); printf("Variabila \"%s\" nu a fost declarata ca float.\n", $2);
      }
      else if (if_initialized_float($2) == -1)
      {
      set_error();
      printf("Variabila \"%s\" nu a fost initializata sau nu este de tip float.\n", $2);
      }
      else $$ = vars_float[index].value; }
      |
      '(' exp_float ')' { $$ = $2; }
      |
      arithmetic_float
exp_bool:
      NR_BOOL { $$ = $1; }
     |
     '@' NAME { int index = if_declared_bool($2);
      if(index == -1)
      {
      set_error(); printf("Variabila \"%s\" nu a fost declarata ca bool.\n", $2);
      }
      else if (if_initialized_bool($2) == -1)
      {
      set_error();
      printf("Variabila \"%s\" nu a fost initializata sau nu este de tip bool.\n", $2);
      }
      else $$ = vars_bool[index].value; }

%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){

symbol_table=fopen("symbol_table.txt","w");
yyin=fopen(argv[1],"r");
yyparse();
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
