#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "matparser.h"
#include "mat.h"
#include "misc.h"



#define FIRST 0
#define SECOND 1
#define THIRD 2
#define NUM_OF_MATRICES 6
#define NUM_OF_ARGS 3
#define PROMPT "$>"
#define SPACE ' '
#define EOF_EXIT_PROMPT "Illegaly terminated by EOF. "
#define STOP_EXIT_PROMPT "See you again next time!"



typedef mat(*handler)(mat *, double *);
typedef struct {MatOp m_op; handler m_handler;}Handlers;

/* SET OF WRAPPER FUNCTIONS TO MATRIX OPERATORS. */
mat sub_mat_handler(mat *a_mats, double *a_scalar_vals);
mat mul_mat_handler(mat *a_mats, double *a_scalar_vals);
mat mul_scalar_mat_handler(mat *a_mats, double *a_scalar_vals);
mat trans_mat_handler(mat *a_mats, double *a_scalar_vals);
mat print_mat_handler(mat *a_mats, double *a_scalar_vals);
mat add_mat_handler(mat *a_mats, double *a_scalar_vals);
mat read_mat_handler(mat *a_mats, double *a_scalar_vals);

void mat_calc_introduction();

int main() {
    Args            args        ={ 
                        Print_Mat, 
                        {MAT_A,MAT_A,MAT_A},
                        {0.0}
                    };
                    
    mat             matrices[NUM_OF_MATRICES],
                    mat_args[NUM_OF_ARGS];
   
    size_t          index       = 0;
    String          s           = NULL_STRING;
    Status          status      = valid;

    Boolean         quit        = False,
                    eof_flag    = False;

    Handlers        handlers[]  ={
                        {Read_Mat,read_mat_handler},
                        {Add_Mat,add_mat_handler},
                        {Sub_Mat,sub_mat_handler},
                        {Mul_Mat, mul_mat_handler},
                        {Mul_Scalar,mul_scalar_mat_handler},
                        {Trans_Mat, trans_mat_handler},
                        {Print_Mat, print_mat_handler}, /* REDUNDANT BUT BETTER FOR FLOW. */
                        {Stop, NULL}
                    };

    

    for(index = 0 ; index < NUM_OF_MATRICES ; ++index){
        matrices[index] = createMatrix();
    }

    mat_calc_introduction();

    while(quit == False){
        printf("\n%s",PROMPT);
        if((s  = getString()) != NULL){
            
        }
        
        if(endedWithEOF(s)){
            quit        = True;
            eof_flag    = True;
        }
        
        s[strlen(s) - 1] = SPACE;
        
        status = processCommand(s, &args);

       
        
        if(valid == status){
            
       
            mat_args[FIRST]     = matrices[args.m_matrices[FIRST]];
            mat_args[SECOND]    = matrices[args.m_matrices[SECOND]];
            mat_args[THIRD]     = matrices[args.m_matrices[THIRD]];

            

            for(index = 0; handlers[index].m_handler ; ++index){
                if(handlers[index].m_op == args.m_operator){
                    printMat(handlers[index].m_handler(mat_args,args.m_scalars));
                    break;
                }
            }
            if(NULL == handlers[index].m_handler){
                quit = True;
            }
            
        }
        else if(status != empty_line){
            showError(status);
        }
    }

    printf("\n%s\n",(eof_flag == True)?EOF_EXIT_PROMPT:STOP_EXIT_PROMPT);
    

    for(index = 0 ; index < NUM_OF_MATRICES ; ++index){
        destroyMatrix(&matrices[index]);
    }

    free(s);

   return 0;

}


mat read_mat_handler(mat *a_mats, double *a_scalar_vals){
    return readMat(*a_mats,a_scalar_vals);
}


mat add_mat_handler(mat *a_mats, double *a_scalar_vals){
    mat             first_arg   = a_mats[FIRST],
                    second_arg  = a_mats[SECOND],
                    result      = a_mats[THIRD];
    
    return add(first_arg,second_arg,result);
}


mat sub_mat_handler(mat *a_mats, double *a_scalar_vals){
    mat             first_arg   = a_mats[FIRST],
                    second_arg  = a_mats[SECOND],
                    result      = a_mats[THIRD];
    
    return sub(first_arg,second_arg,result);
}


mat mul_mat_handler(mat *a_mats, double *a_scalar_vals){
    mat             first_arg   = a_mats[FIRST],
                    second_arg  = a_mats[SECOND],
                    result      = a_mats[THIRD];
    
    return mult(first_arg,second_arg,result);
}


mat mul_scalar_mat_handler(mat *a_mats, double *a_scalar_vals){
    mat             first_arg   = a_mats[FIRST],
                    res_arg     = a_mats[SECOND];
    double          second_arg  = *a_scalar_vals;
    
    return multScalar(first_arg,second_arg,res_arg);
}


mat trans_mat_handler(mat *a_mats, double *a_scalar_vals){
    mat             first_arg   = a_mats[FIRST],
                    res_arg     = a_mats[SECOND];

    return transMat(first_arg,res_arg);
}


mat print_mat_handler(mat *a_mats, double *a_scalar_vals){
    return *a_mats;
}



void mat_calc_introduction(){
    struct {
        const char *opname;
        const char *op;
        const char *detail;
    }info [] = {
        {
            "READ MATRIX",
            "read_mat MAT , REAL_NUMBER,....,REAL_NUMBER",
            "Set MAT values according to the list of real numbers provided, \npadding with zeros if entered less than 16 values."
        },
        {
            "ADDITION OPERATOR",
            "add_mat MAT1 , MAT2 , MAT3",
            "Addition of MAT1 and MAT2 - result assigned to MAT3."
        },
        {
            "SUBTRACTION OPERATOR",
            "sub_mat MAT1 , MAT2 , MAT3",
            "Subtract MAT2 from MAT1 - result assigned to MAT3."
        },        
        {
            "MULTIPLICATION OPERATOR",
            "mul_mat MAT1 , MAT2 , MAT3",
            "Multiplication of MAT1 and MAT2 - result assigned to MAT3."
        },
        {
            "MULTIPLICATION BY SCALAR OPERATOR",
            "mul_scalar MAT1 , REAL_NUMBER , MAT2",
            "The multiplication of REAL_NUMBER and MAT1 - result assigned to MAT2."
        },
        {
            "TRANSPOSE",
            "trans_mat MAT1 , MAT2",
            "Assign the transposition of MAT1 to MAT2."
        },
        {
            "PRINT MATRIX",
            "print_mat MAT",
            "Prints the matrix MAT."
        },
        {
            "QUIT - LEAVE NOW AND NEVER COME BACK (GOLLUM).",
            "stop",
            "Exit calculator."
        },
        {NULL,NULL}
    };
    size_t i = 0;
    printf("Welcome to the AWESOME MATRIX CALCULATOR\n\n");

    for(i = 0 ; info[i].detail;++i){
        printf("\n%s\n-------------------------------------\n",info[i].opname);        
        printf("DETAILS : %s\n\n",info[i].detail);
        printf("SYNTAX : %s\n",info[i].op);
        printf("\n\n");
    }
}


