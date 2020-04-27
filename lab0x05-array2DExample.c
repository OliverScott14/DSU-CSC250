#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define Global static size for the array
#define ROWCOUNT 10 
#define COLCOUNT 6


//prints a 2D table of random numbers seeded into 10 rows and 6 columns in the terminal
void printTableofDoubles(double table[ROWCOUNT][COLCOUNT], int nRow, int nCols)
{
    int i, j;
    for (i = 0;i < nRow; i++) //loop for row
    {
        for (j = 0; j < nCols; j++) // loop for column
        {   //print the row/col index as a lf ( up to 100 digits and 2 decima
            printf("%10.2lf", table[i][j]); 
        }
        printf("\n"); // newline
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL)); // see rand num gen once at start

    int rowIndex, colIndex; //i nitializing variables 
    double myTable[ROWCOUNT][COLCOUNT]; //initial an 2d array with the global row/column sizes 
    
    // fill it with random numbers 
    for (rowIndex = 0; rowIndex < ROWCOUNT; rowIndex++) // loop over rows
    {
        for (colIndex = 0; colIndex < COLCOUNT; colIndex++) // loop over columns
        {
            myTable[rowIndex][colIndex] = (double) rand() / RAND_MAX * 100.0; // limits to #'s <=100
        }
    }
  	//print the array to the terminal... neatly with columns and rows.
    printTableofDoubles(myTable,ROWCOUNT,COLCOUNT);
}
