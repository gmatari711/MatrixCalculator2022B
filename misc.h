
#ifndef PARSER_MISC_H
#define PARSER_MISC_H

#define NULL_STRING NULL
#define SAFETY_GAP 4
#define SPACE ' '
#define COMMA ','

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef         enum{False = 0, True =1}    Boolean;
typedef         char *                      String;
typedef         char                        Byte;



String getString();

Boolean endedWithEOF(String s);

#endif 
