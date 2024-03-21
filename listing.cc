// CMSC 430 Compiler Theory and Design
// Project 1 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the bodies of the functions that produce the 
// compilation listing

#include <cstdio>
#include <string>
#include <queue>
#include <iostream> // Include for cout and endl

using namespace std;

#include "listing.h"

static int lineNumber;
static int lexicalErrors = 0;
static int syntaxErrors = 0;
static int semanticErrors = 0;
static queue<pair<ErrorCategories, string>> errorQueue;

void displayErrors();

void firstLine()
{
    lineNumber = 1;
    printf("\n%4d  ", lineNumber);
}

void nextLine()
{
    displayErrors();
    lineNumber++;
    printf("%4d  ", lineNumber);
}

int lastLine()
{
    printf("\r");
    displayErrors();
    if (lexicalErrors > 0 || syntaxErrors > 0 || semanticErrors > 0) {
        printf("Lexical Errors: %d\n", lexicalErrors);
        printf("Syntax Errors: %d\n", syntaxErrors);
        printf("Semantic Errors: %d\n", semanticErrors);
    } else {
        printf("Compiled Successfully\n");
    }
    return lexicalErrors + syntaxErrors + semanticErrors;
}

void appendError(ErrorCategories errorCategory, const std::string& message) {
    // Function implementation
      switch (errorCategory) {
        case LEXICAL:
            lexicalErrors++;
            break;
        case SYNTAX:
            syntaxErrors++;
            break;
        case SEMANTIC:
        case GENERAL_SEMANTIC:
        case DUPLICATE_IDENTIFIER:
        case UNDECLARED:
            semanticErrors++;
            break;
    }
    errorQueue.push({errorCategory, message});
}

void displayErrors()
{
    while (!errorQueue.empty()) {
        auto error = errorQueue.front();
        errorQueue.pop();
        switch (error.first) {
            case LEXICAL:
                cout << "Lexical Error: " << error.second << endl;
                break;
            case SYNTAX:
                cout << "Syntax Error: " << error.second << endl;
                break;
            case GENERAL_SEMANTIC:
                cout << "Semantic Error: " << error.second << endl;
                break;
            case DUPLICATE_IDENTIFIER:
                cout << "Semantic Error: Duplicate " << error.second << endl;
                break;
            case UNDECLARED:
                cout << "Semantic Error: Undeclared " << error.second << endl;
                break;
        }
    }
}
