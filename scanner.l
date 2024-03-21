/* CMSC 430 Compiler Theory and Design
   Project 1 Skeleton
   UMGC CITE
   Summer 2023 */

/* This file contains flex input file */

%{
#include <cstdio>
#include <string>

using namespace std;

#include "listing.h"
#include "tokens.h"
%}


%option noyywrap

ws          [ \t\r]+
comment     "//".*\n
line        [\n]
id          ([A-Za-z]([A-Za-z0-9]|_[A-Za-z0-9]{0,30}[A-Za-z0-9])?)|_[A-Za-z0-9]{1,31}|[A-Za-z0-9]{1,30}_
digit       [0-9]
dec         {digit}+
hex         [0-9A-Fa-f]
char        '.'
punc        [\(\),:;]
escape      \\[btnfr]

%%


{ws}        { ECHO; }
{comment}   { ECHO; nextLine(); }
{line}      { ECHO; nextLine(); }
"+"         { ECHO; return(ADDOP); } // Addition operator
"-"         { ECHO; return(SUBOP); } // Subtraction operator
"*"         { ECHO; return(MULOP); } // Multiplication operator
"/"         { ECHO; return(DIVOP); } // Division operator
"%"         { ECHO; return(REMOP); } // Remainder operator
"&"         { ECHO; return(ANDOP); } // Logical operator (AND)
"|"         { ECHO; return(OROP); }  // Logical operator (OR)
"!"         { ECHO; return(NOTOP); } // Logical operator (NOT)
"<"         { ECHO; return(RELOP); } // Relational operator
"<>"        { ECHO; return(RELOP); } // Relational operator
">"         { ECHO; return(RELOP); } // Relational operator
">="        { ECHO; return(RELOP); } // Relational operator
"<="        { ECHO; return(RELOP); } // Relational operator
"="         { ECHO; return(RELOP); } // Relational operator
"=>"        { ECHO; return(ARROW); }  // Arrow operator
"begin"     { ECHO; return(BEGIN_); }  // Reserved word
"case"      { ECHO; return(CASE); }    // Reserved word
"character" { ECHO; return(CHARACTER); } // Reserved word
"else"      { ECHO; return(ELSE); }    // Reserved word
"elsif"     { ECHO; return(ELSIF); }   // Reserved word
"endfold"   { ECHO; return(ENDFOLD); } // Reserved word
"endif"     { ECHO; return(ENDIF); }   // Reserved word
"fold"      { ECHO; return(FOLD); }    // Reserved word
"if"        { ECHO; return(IF); }      // Reserved word
"left"      { ECHO; return(LEFT); }    // Reserved word
"real"      { ECHO; return(REAL); }    // Reserved word
"right"     { ECHO; return(RIGHT); }   // Reserved word
"then"      { ECHO; return(THEN); }    // Reserved word

{id}        { ECHO; return(IDENTIFIER);}
{hex}       { ECHO; return(HEX_LITERAL); }
{dec}       { ECHO; return(INT_LITERAL); } // Decimal integer literals
{dec}(\.{dec})?(e[-+]?{dec})? { ECHO; return(REAL_LITERAL); } // Real literals
"'"         { ECHO; return(CHAR_LITERAL); }
"\\b"       { ECHO; return(CHAR_LITERAL); } // Additional escape character (backspace)
"\\t"       { ECHO; return(CHAR_LITERAL); } // Additional escape character (tab)
"\\n"       { ECHO; return(CHAR_LITERAL); } // Additional escape character (newline)
"\\r"       { ECHO; return(CHAR_LITERAL); } // Additional escape character (carriage return)
"\\f"       { ECHO; return(CHAR_LITERAL); } // Additional escape character (form feed)
{punc}      { ECHO; return(yytext[0]); }
.           { ECHO; appendError(LEXICAL, yytext); }


%%

int main() {
    firstLine();
    
    FILE *file = fopen("lexemes.txt", "wa"); 
    int token = yylex();
    while
    (token) {
        fprintf(file, "%d %s\n", token, yytext);
        token = yylex();
    }
    lastLine();
    fclose(file);
    return 0;
}
