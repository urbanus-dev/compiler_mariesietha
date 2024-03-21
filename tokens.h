// CMSC 430 Compiler Theory and Design
// Project 1 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the enumerated type definition for tokens

enum Tokens {
    ADDOP = 256, // Addition operator
    ANDOP,       // Logical operator (AND)
    SUBOP,       // Subtraction operator
    MULOP,       // Multiplication operator
    DIVOP,       // Division operator
    REMOP,       // Remainder operator
    EXPOP,       // Exponentiation operator
    NEGOP,       // Unary minus operator
    OROP,        // Logical operator (OR)
    NOTOP,       // Logical operator (NOT)
    RELOP,       // Relational operator
    ARROW,       // Arrow operator
    BEGIN_,      // Reserved word
    CASE,        // Reserved word
    CHARACTER,   // Reserved word
    ELSE,        // Reserved word
    ELSIF,       // Reserved word
    ENDFOLD,     // Reserved word
    ENDIF,       // Reserved word
    FOLD,        // Reserved word
    IF,          // Reserved word
    LEFT,        // Reserved word
    REAL,        // Reserved word
    RIGHT,       // Reserved word
    THEN,        // Reserved word
    IDENTIFIER,  // Identifier token
    INT_LITERAL, // Integer literal token
    REAL_LITERAL,// Real literal token
    CHAR_LITERAL,// Character literal token
    END,         // Reserved word
    HEX_LITERAL, // Hexadecimal integer literals

};
