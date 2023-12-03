
#include "mat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _matrix{
    double matrix[DIM][DIM];
};

mat createMatrix(){
    return calloc(1,sizeof(struct _matrix));
}

void destroyMatrix(mat *m){
    if(NULL != *m){
        free(*m);
        *m=NULL;
    }

}

mat add(mat m1,mat m2, mat res){
    int     i=0,
            j=0;

    for(i=0;i<DIM;++i){
        for(j=0;j<DIM;++j){
            res->matrix[i][j] = m1->matrix[i][j] + m2->matrix[i][j];
        }
    }

    return res;
}

mat sub(mat m1, mat m2, mat res){
    int     i=0,
            j=0;

    for(i = 0 ; i < DIM ; ++i){
        for( j = 0 ; j < DIM ; ++j){
            res->matrix[i][j] = m1->matrix[i][j] - m2->matrix[i][j];
        }
    }

    return res;
}

mat mult(mat m1, mat m2, mat a_res){
    int             i=0,
                    j=0,
                    k=0;

    struct _matrix  res;

    for(i = 0 ; i < DIM; ++i){
        memset(res.matrix[i],0,DIM*sizeof(double));
    }

    for(i = 0; i < DIM ; ++i){
        for(j = 0 ; j < DIM ; ++j){
            for(k = 0 ; k < DIM ; ++k ){
                res.matrix[i][j]+=m1->matrix[i][k]*m2->matrix[k][j];
            }
        }
    }
    for(i = 0; i<DIM; ++i){
        memcpy(a_res->matrix[i],res.matrix[i],DIM*sizeof(double));
    }

    return a_res;

}


mat multScalar(mat m1, double scalar, mat res){
    int     i=0,
            j=0;

    for(i = 0; i < DIM; ++i){
        for(j = 0; j < DIM; ++j){
            res->matrix[i][j]=m1->matrix[i][j]*scalar;
        }
    }

    return res;

}

mat readMat(mat m,double v[N_VALS]){
    size_t  i;

    for(i=0 ; i<N_VALS; ++i){
        m->matrix[i/DIM][i%DIM] = v[i];
    }

    return m;
}

void printMat(mat m){
    size_t i = 0;

    for(i = 0; i<N_VALS ; ++i){
        if(i%DIM == 0){
            putchar('\n');
        }
        printf("%7.2f ",m->matrix[i/DIM][i%DIM]);/* SET FORMAT ACCORDING TO DEMANDS */
    }
    putchar('\n');
}

mat transMat(mat a_m1, mat a_res){
    size_t          i = 0;
    struct _matrix  res;

    for(i = 0; i < N_VALS; ++i){
        res.matrix[i / DIM][i % DIM] = a_m1->matrix[i % DIM][i / DIM];
    }

    for(i = 0; i< N_VALS; ++i){
        a_res->matrix[i / DIM][i % DIM] = res.matrix[i / DIM][i % DIM];
    }

    return a_res;
}

