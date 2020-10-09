#include <stdio.h>
#define SIZE 100

int board[SIZE][SIZE];

int max(int a, int b)
{
	if(a>b)
	{
		return a;
	}
	else
		return b;
 //return a > b ? a : b;
}


// Function to return the maximum number of knights that can be placed on the given
// chessboard such that no two knights attack each other
int max_knight(int m, int n)
{
	 int i, j;
 // Check for corner case #1
 // If row or column is 1
 	if (m == 1 || n == 1)
 {
 	if( m > n)
 	{
	 
 		for( i=m; i>=0 ; i--)
 		board[i][0]=1;
 	}
 	else
 	{
		for( i=n; i>=0 ; i--)
 		board[0][i]=1;
 	}
 //simply print total blocks which will be the max of row or column
 return max(m, n);
 }
 
 // Check for corner case #2 
 //If row or column is 2
	 else if (m == 2 || n == 2)
 {
 // then whichever is lesser gets two consecutive
 // filled and two left empty and two filled till end of board
 
 	int c = 0;
 	c = (max(m, n) / 4) * 4;
 //if c= 0 , only two consequtive blocks having knights
 	if (max(m, n) % 4 == 1)
 	{
		 c += 2;
	}
	 else if (max(m, n) % 4 > 1)
 	{
		 c += 4;
 	}
 	
 	if( m > n)
 	for( j=0; j<n; j++)
 	{
	 
 		for(i=0;i<m;i+=2)
 		{
 			board[i++][j]=1;
 			board[i][j]=1;
 			i++;
 		}
 	}
	 else
 	for( i=0; i<m; i++)
 	{
	 	for(j=0;j<n;j+=2)
 		{
 			board[i][j++]=1;
 			board[i][j]=1;
			 j++;
		 }
	}
 return c;
 }
 	// the general case 
	 else
 {
	 for(i = 0; i<m;i++)
	 {
		 j = (i%2 == 1)? 1:0; //if  i is odd initialze j=1 else j=0 ensuring knights palced on alternate
		 for(j; j<n; j+=2)
		 {
			 board[i][j] = 1;
		 }
	 }
 return (((m * n) + 1) / 2); //no. of knights is half of board size 
 }
}


	int main()
{
	 int n = 10, m = 10;
	 printf("Enter the dimensions of the board\n");
	 scanf("%d %d",&m,&n);
	 printf("Maximum number of knights that can be placed on the keyboard:\n%d",max_knight(m, n));
 // Print
 	printf("\nOne solution:\n\n");
 	for(int i = 0; i<m; i++)
 	{
 		printf("");
 		for(int j = 0; j<n; j++)
 		{
 			if(board[i][j]==1)
 			printf("K\t");
 			else
 			printf("-\t");
 		}
 	printf("\n\n");
 }
 return 0;
}
