#ifndef LISTING_H
#define LISTING_H

#include <string>
#include <queue>

enum ErrorCategories { LEXICAL, SYNTAX, SEMANTIC, GENERAL_SEMANTIC, DUPLICATE_IDENTIFIER, UNDECLARED };

void firstLine();
void nextLine();
int lastLine();
void appendError(ErrorCategories errorCategory, const std::string& message);
void displayErrors();

#endif // LISTING_H
