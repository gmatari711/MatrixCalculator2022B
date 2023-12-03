

#include "misc.h"
#include <string.h>

#define BLOCK_SIZE 256


String getString(){ /* BREAK DOWN OR RECEIVE CHAR AS ARGUMENT (?) */
    static String       s = NULL_STRING;
    static size_t       capacity = 0;

    size_t              size = 0;
    char                ch = 0;

 
    
    do{
        ch = getchar();
        putchar(ch);/* NOT GOOD PRACTICE */
        if(size + SAFETY_GAP>= capacity){
            size_t new_capacity = (capacity + SAFETY_GAP) * 2;
            String temp = realloc(s,new_capacity);
            assert(NULL != temp);
            s = temp;
            capacity = new_capacity;
        }
       
        if(ch == COMMA){
            s[size++] = SPACE;
            s[size++] = SPACE;
        }
        s[size++] = ch;
        s[size] = 0;
    }while(ch !='\n'  && ch != EOF);

   
    
    return s;

}

Boolean endedWithEOF(String s){
    if(s[strlen(s) - 1] == EOF){
        return True;
    }

    return False;
}

