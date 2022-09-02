//Program : 6
//Pratyay Sarkar

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        matrix->elements[i] = (int *)calloc(matrix->rows,sizeof(int));
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

//print the rowwise or columnwise sum of the matrix elements,
//according to the user's choice specified by the 'choice' parameter
void doStuff (Matrix* matrix, const char* choice)
{
    int i,j; //loop variables
    int sum; //sum variable, used both for rowwise and columnwise sum, whichever the case

    //rows and columns variables intialized such that by default
    //the sumLoop calculates individual rowwise sum
    int rows = matrix->rows, columns = matrix->columns;

    //decides whether sumLoop calculates rowwise sum or columnwise sum,
    //by swapping the values of rows and columns if the user choice is "Column"
    decider: if (strcmp(choice,"Column")==0)
    {
        int temp = rows;
        rows = columns;
        columns = temp;
    }

    //does rowwise sum or columnwise sum according to values of certain variables
    sumLoop: for (i = 0; i < rows; i++)
    {
        sum=0; //sum intialized to zero in the beginning of each iteration
        for (j = 0; j < columns; j++)
        {
            if (strcmp(choice,"Column")==0) 
            {
                //if columnwise sum is required, change indexing (i,j) to (j,i)
                sum+= matrix->elements[j][i];
            }
            else
                sum+= matrix->elements[i][j]; //for rowwise sum, indexing -> (i,j)
        }
        printf("\nSum of %s %d = %d", choice,i,sum); //print sum of each row (or column)
    }
}

void main()
{
    Matrix DynamicMatrix; //Declare a matrix
    int m,n; //Number of rows - m, number of columns - n

    //Accept dimensions of DynamicMatrix as user input
    printf("\nEnter the number of rows of matrix 'DynamicMatrix' : ");
    scanf("%d",&m);
    printf("\nEnter the number of columns of matrix 'DynamicMatrix' : ");
    scanf("%d",&n);
    
    //Assign structure elements accordingly
    DynamicMatrix.rows = m;
    DynamicMatrix.columns = n;

    //allocate memory for the matrix
    allocate(&DynamicMatrix);

    printf("\n\nEnter %d matrix (DynamicMatrix) elements row-major wise:\n",DynamicMatrix.rows*DynamicMatrix.columns);
    input(&DynamicMatrix); //accept matrix elements as user input
        
    printf("\nThe Matrix 'DynamicMatrix' :\n");
    display(&DynamicMatrix); //display the matrix

    printf("\nThe sum of individual rows :\n");
    doStuff(&DynamicMatrix,"Row"); //display the sum of individual rows

    printf("\n\nThe sum of individual columns :\n");
    doStuff(&DynamicMatrix,"Column"); //display the sum of individual columns
}