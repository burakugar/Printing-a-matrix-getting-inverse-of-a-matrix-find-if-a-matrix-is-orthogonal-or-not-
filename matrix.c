#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct matrix{ /* creating the struct elements */
	double array[3][3];
	double det;
}matrix;
typedef struct vector{
	double array[3];
}vector;
typedef struct third_order_polynomial{
	double array[3];
}third_order_polynomial;

void print_matrix( matrix initial_matrix){ /*printing the matrix's elements */
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		printf("%lf " ,initial_matrix.array[i][j]);
		}
			printf("\n");
	}
}
int determinant_of_matrix(matrix* initial_matrix){
	double det; /* calculating the determinant */
	int i;
	for(i=0;i<3;i++)
      det = det + (initial_matrix->array[0][i])*(initial_matrix->array[1][(i+1)%3]*initial_matrix->array[2][(i+2)%3] - initial_matrix->array[1][(i+2)%3]*initial_matrix->array[2][(i+1)%3]);
	
  		initial_matrix->det= det;
  		return det;
	}
void inverse_matrix(matrix* initial_matrix, matrix* inverted_matrix){
	int i,j;
	double det= determinant_of_matrix(initial_matrix);
	if(det==0){
		printf("Not invertible");
		goto z;
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++)
		inverted_matrix->array[i][j]=((initial_matrix->array[(j+1)%3][(i+1)%3] * initial_matrix->array[(j+2)%3][(i+2)%3]) - (initial_matrix->array[(j+1)%3][(i+2)%3] * initial_matrix->array[(j+2)%3][(i+1)%3]))/ det;
	}
	printf("\nInverse of matrix is: \n");
	z:;
}
double find_orthogonal(vector vec_1, vector vec_2, vector* output_vec){
	double ab= vec_1.array[0]*vec_2.array[0]+ vec_1.array[1]*vec_2.array[1]+vec_1.array[2]* vec_2.array[2];
	double A= sqrt(pow(vec_1.array[0],2)+pow(vec_1.array[1],2)+pow(vec_1.array[2],2)); /* find the first vector */
	double B= sqrt(pow(vec_1.array[0],2)+pow(vec_1.array[1],2)+pow(vec_1.array[2],2)); /* find the second vector */
	double angle= (double)acos((double)A*B/ab);

    output_vec->array[0] = vec_1.array[0] * vec_2.array[2] - vec_1.array[2] * vec_2.array[1]; /* assigning the calculation to the output vector */
    output_vec->array[1] = vec_1.array[2] * vec_2.array[0] - vec_1.array[0] * vec_2.array[2];
    output_vec->array[2]  = vec_1.array[0] * vec_2.array[1] - vec_1.array[1] * vec_2.array[0];

	return angle;
}


int main(void){
	struct matrix initial_matrix;
	struct matrix inverted_matrix;
	int i,j,a,b;
	double temp1,temp2;
	int count=1;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		printf("Please enter the %d'th element of the matrix: ", count); /* getting the matrix elements */
		count++;
		scanf("%lf",&initial_matrix.array[i][j]);
	}
}
	print_matrix(initial_matrix);
	inverse_matrix(&initial_matrix,&inverted_matrix);
	print_matrix(inverted_matrix);
	struct vector vec_1;
	struct vector vec_2;
	struct vector output_vec;
	count=1;
	printf("second part \n");
	for(i=0;i<3;i++){
		printf("Please enter the first vector's %d'th element: ",count); /* getting the vectors element */
		scanf("%lf",&vec_1.array[i]);
	}
	count=1;
	for(i=0;i<3;i++){
		printf("\n Please enter the second vector's %d'th element: ",count); /* getting the polynomials coeffs */
		scanf("%lf",&vec_2.array[i]);
	}
	find_orthogonal(vec_1,vec_2,&output_vec);


	return 0;
}
