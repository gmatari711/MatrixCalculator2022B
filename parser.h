

#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#include <stdio.h>
#define NULL_STRING NULL
#include "misc.h"


typedef     struct      parser *Parser;


/* Params:  void
 * Task:    Create a Parser object.
 * Output:  Returns new Object.
 * */
Parser buildParser();

/* Params:  A pointer to Parser object
 * Task:    Destroys Object - free all allocated memory. a_prs set with NULL ptr.
 * Output:  void.
 *          
 * */
void destroyParser(Parser *a_prs);

/* Params:  Parser object 'a_prs', a c-string 'a_str', and an array of const c-strings 
            'a_delims'.
 * Task:    Break a_str according to tokens given by 'a_delims'. Last delimiter is reused 
 *          until reached end of string.
 * Output:  void.
 * */
void parseString(Parser a_prs, String a_str, const String *a_delims);

/* Params:  A Parser object.
 * Task:    retrieve next token and point to next item.
 * Output:  return value is next token.
 * */
String getNextToken(Parser a_prs);

/* Params:  A Parser object
 * Task:    check if points to a token or NULL.
 * Output:  returns True i points to a token. False otherwise.
 * */
Boolean hasNextToken(Parser a_prs);

#endif 
