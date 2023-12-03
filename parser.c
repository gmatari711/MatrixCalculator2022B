

#include "parser.h"
#include <string.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

struct parser{
    String      m_arr[MAX_CAPACITY];
    size_t      m_size;
    size_t      m_pos;
    size_t      m_capcity;
};

Parser buildParser(){
    Parser      result;

    result = calloc(1,sizeof(struct parser));
    result->m_capcity = MAX_CAPACITY;

    return result;
}

void destroyParser(Parser *a_prs){
    if(*a_prs != NULL){
        free(*a_prs);
        *a_prs = NULL;
    }
}


void parseString(Parser a_prs, String a_str, const String *a_delims){


    a_prs->m_arr[a_prs->m_size] = strtok(a_str, *a_delims);
    
    while(a_prs->m_arr[a_prs->m_size] != NULL){
    
        a_delims = (*(a_delims + 1) != NULL)? a_delims + 1 : a_delims;
        a_prs->m_arr[++a_prs->m_size] = strtok(NULL,*a_delims);
        
    }
    
}

String getNextToken(Parser a_prs){
    return (a_prs->m_size > a_prs->m_pos)? a_prs->m_arr[a_prs->m_pos++] : NULL_STRING;
}

Boolean hasNextToken(Parser a_prs){
    return ( a_prs->m_pos < a_prs->m_size )? True : False;
}


