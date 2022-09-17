//Program : 6
//Pratyay Sarkar

#include <stdio.h>
#include <stdlib.h>

//Structure to represent a matrix
struct matrix 
{
    int rows; //number of rows of the matrix
    int columns; //number of columns of the matrix
    int ** elements; //double pointer to represents the elements of the matrix
};

typedef struct matrix Matrix; //giving an alias to struct matrix

//to allocate memory for the matrix
void allocate(Matrix * matrix)
{
    matrix->elements = (int **)calloc(matrix->rows,sizeof(int *));
    for(int i = 0; i < matrix->rows; i++)
        matrix->elements[i] = (int *)calloc(matrix->columns,sizeof(int));
}

//to accept the matrix elements as input from user
void input (Matrix* matrix)
{
    int i,j;
    for (i = 0; i < matrix->rows; i++)
        for (j = 0; j < matrix->columns; j++)
            scanf("%d", &matrix->elements[i][j]);
}

//to display the matrix elements in matrix format
void display (Matrix* matrix)
{
    int i,j;
    for (i = 0; i < matrix->rows; i++)
    {
        for (j = 0; j < matrix->columns; j++)
            printf("%d\t", matrix->elements[i][j]);
        printf("\n");
    }
}

//multiplies two matrices
Matrix matrix_multiply(Matrix* A, Matrix* B)
{
    Matrix result; //resultant matrix
    allocate(&result); //allocate memory for resultant matrix

    //assign values to rows and columns of resultant matrix
    result.rows = A->rows;
    result.columns = B->columns;

    int i,j,k; //loop variables
    for (i = 0; i < A->rows; i++)
        for (j = 0; j < B->columns; j++)
            for (k = 0; k < A->columns; k++)
            {
                int a = (A->elements[i][k]);
                int b = (B->elements[k][j]);
                result.elements[i][j] = result.elements[i][j]+ a*b;
            }
    return result; //return the resultant matrix
}

void main()
{
    //Matrices A and B are input matrices
    Matrix A,B,C; //C is the output matrix after multiplication
    printf("\nEnter the number of rows of matrix A: ");
    scanf("%d",&A.rows);
    printf("\nEnter the number of columns of matrix A: ");
    scanf("%d",&A.columns);
    printf("\nEnter the number of rows of matrix B: ");
    scanf("%d",&B.rows);
    printf("\nEnter the number of columns of matrix B: ");
    scanf("%d",&B.columns);

    if(A.columns != B.rows) //check for multiplication compatibility
    {
        printf("\nIncomaptible orders, matrices not suitable for multiplication.\n");
        exit(1);
    }
    
    else //matrixes compatible for multiplication, proceed
    {   
        allocate(&A); //allocate memory for matrix A
        allocate(&B); //allocate memory for matrix B

        printf("\n\nEnter %d matrix (A) elements row-major wise:\n",A.rows*A.columns);
        input(&A);
        printf("\n\nEnter %d matrix (B) elements row-major wise:\n",B.rows*B.columns);
        input(&B);
        printf("\nThe Matrix A:\n");
        display(&A);
        printf("\nThe Matrix B:\n");
        display(&B);
        printf("\nAfter multiplication, the resultant Matrix C:\n");
        C = matrix_multiply(&A, &B); //call the matrix_multiply() function
        display(&C); //display the resultant matrix
    }
}