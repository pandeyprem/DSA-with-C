// You are given a matrix A of size m and n as input and you are required to print the reverse spiral order of the matrix 


// Program Constriants: 



// Implement a function void spiralMatrixRev(int m, int n, int ** array) for printing the reverse spiral order of the matrix A.


// Reverse spiral order: It is a spiral traversal that begins at top-left and proceeds counter-clockwise to the first bottom-right-up-left.


// The Reverse spiral order traversal for a given matrix of m-rows and n-columns is shown below: 



// |a00 |	down |	left |	left |	a0m |
// | down 	| down 	| down 	| left 	| up 
// | down 	| down 	| aij 	| up 	| up 
// | down 	| right 	| right 	| up 	| up 
// | an0	| right	| right	| right	| anm


// Explanation 

// Let A[2][3] be the input matrix 

// 1 2 3 
 
// 4 5 6 
 


// From the definition of the Reverse spiral order, traversal begins at top-left i.e A[0][0] and proceeds counter-clockwise to the first bottom-right-up-left. 


// So, the traversal order is A[0][0] -> A[1][0] -> A[1][1] -> A[1][2] -> A[0][2] -> A[0][1]


// Input Format 

// First line contains the size of the matrix i.e m rows and n columns seperated by a space bar 

// Input matrix will be provided from the second line of input  


// example: 

// 2 3 

// 1 2 3 
 
// 4 5 6 
 


// Output Format 

// You must output the reverse spiral order of the matrix 


// example: 

// 1 4 5 6 3 2


// Variable Constraints:

// The number of rows and columns of the matrix are less than 10 

// Use the concepts of 2D arrays and double pointers (**) in defining spiralMatrixRev() function 




#include <stdlib.h>
#include <stdio.h>

void spiralMatrixRev(int m, int n, int ** array)
{
	int i, rowindexstart = 0, columnindexstart = 0;
	
	// rowindexstart - starting row index
	// m - ending row index
	// columnindexstart - starting column index
	// n - ending column index 
	// i - used to iterate
	
	// initialize the count to zero
	int count = 0;
	
	// totalnem number of elements in matrix
	int totalnem = m * n;
	
	// start the loop 
	// here we check the max row and max column 
	while (rowindexstart < m && columnindexstart < n)
	{
		// when count reaches the total number of elements in the matrix, break from the loop
		if (count == totalnem)
		break;
	
		// Print the first column from the remaining columns
		for (i = rowindexstart; i < m; ++i)
		{
		printf("%d ",array[i][columnindexstart]);
		count++;
		}
		columnindexstart++;
	
		if (count == totalnem)
		break;
	
		// Print the last row from the remaining rows
		for (i = columnindexstart; i < n; ++i)
		{
		printf("%d ",array[m - 1][i]);
		count++;
		}
		m--;
	
		if (count == totalnem)
		break;
	
		// Print the last column from the remaining columns
		if (rowindexstart < m)
		{
		for (i = m - 1; i >= rowindexstart; --i)
		{
			printf("%d ",array[i][n - 1]);
			count++;
		}
		n--;
		}
	
		if (count == totalnem)
		break;
	
		// Print the first row from the remaining rows
		if (columnindexstart < n)
		{
		for (i = n - 1; i >= columnindexstart; --i)
		{
			printf("%d ",array[rowindexstart][i]);
			count++;
		}
		rowindexstart++;
		}
	}
}

int main()
{
    int i,j,m,n;
    scanf("%d %d",&m,&n);
    
    // Dynamic memory allocation 
	// Usage of double pointer for storing matrix  
    int **a=(int **)malloc(m*sizeof(int));
    // for each row assign n values 
    for(i=0;i<n;i++)
        a[i]=(int *)malloc(n*sizeof(int));

	// reading the input here
    for (i = 0; i < m; i++)
    {
    for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    
    // printing the matrix here
    /*
    for (i = 0; i < m; i++)
    {
    for (j = 0; j < n; j++)
        {
        printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    */
    //
    // call the function spriral matrix
    spiralMatrixRev(m,n,a);
    
    return 0;
}