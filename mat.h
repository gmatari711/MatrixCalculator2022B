
#ifndef PARSER_MAT_H
#define PARSER_MAT_H


#define DIM 4
#define N_VALS 16
typedef struct _matrix *mat;

/* Params:
 * Task:
 * Output:
 * */
mat createMatrix();

/* Params:
 * Task:
 * Output:
 * */
void destroyMatrix(mat* m);

/* Params:
 * Task:
 * Output:
 * */
mat readMat(mat m,double v[]);

/* Params:
 * Task:
 * Output:
 * */
mat add(mat m1,mat m2, mat res);

/* Params:
 * Task:
 * Output:
 * */
mat sub(mat m1, mat m2, mat res);

/* Params:
 * Task:
 * Output:
 * */
mat mult(mat m1, mat m2, mat res);

/* Params:
 * Task:
 * Output:
 * */
mat multScalar(mat m1, double scalar, mat res);

/* Params:
 * Task:
 * Output:
 * */
mat transMat(mat m1, mat res);

/* Params:
 * Task:
 * Output:
 * */
void printMat(mat m);


#endif 
