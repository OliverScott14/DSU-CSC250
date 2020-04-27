#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
//Define Global max size for the array items
#define MAXROWS 200
#define MAXCOLS 200


// prints table of ints
void printTableofInts(int table[MAXROWS][MAXCOLS], int nRow, int nCols)
{
    int i, j;
    for (i = 0;i < nRow; i++) 
    {
        for (j = 0; j < nCols; j++)
        {
            printf("%3d", table[i][j]); 
        } 
        printf("\n");
    }
}

// print the GOL 2d array into the terminal
void printGameofLife(int table[MAXROWS][MAXCOLS], int nRow, int nCols)
{
    int i, j;
    for (i = 0;i < nRow; i++) 
    {
        for (j = 0; j < nCols; j++)
        {
            if ( table[i][j] == 1){ printf("*");} else {printf(" ");}  
            //printf("%5d", table[i][j]); 
        } 
        printf("\n");
    }
}


//CHALLENGE:    NEIGHBORS 
//  fill an 2D array of ints... with random l's O's...  then use graphic an draw a grid 
//  with different color circles depending 1 or 0 in cell of the array..

void countNeighbors(int sourceGrid[MAXROWS][MAXCOLS], int countGrid[MAXROWS][MAXCOLS], int nRows, int nCols) 
{
	for(int i = 0;i < nRows;i++) { //  row loop
		for(int j = 0;j < nCols;j++) { //  col loop
			countGrid[i][j] = 0; // make sure we start counting at 0
			for(int deltaRow = -1;deltaRow <= 1;deltaRow++) { // neighbor row loop
				for(int deltaCol = -1;deltaCol <= 1;deltaCol++) { // neighbor col loop
					//if sourceGrid[i+deltaRow][j+deltaCol] is 1 then add 1 to the count 
				  	if( i+deltaRow >= 0 && j+deltaCol >= 0 && i+deltaRow < nRows && j+deltaCol < nCols){	
						if(!((deltaRow == 0 ) && ( deltaCol == 0))) { 
						    // count nei if its a 1
							countGrid[i][j] = countGrid[i][j] + sourceGrid[i+deltaRow][j+deltaCol];
					
						}
					}
				}
			}
		}
	}		
}


// given a gol grid update values according to rules
void updateGameOfLife(int golGrid[MAXROWS][MAXCOLS], int nRows, int nCols )
{
    int countGrid[MAXROWS][MAXCOLS];
    countNeighbors(golGrid,countGrid,nRows,nCols); 
    // check each cell of golGrid & count and  decide whether to update to 1 or 0 
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0; j < nCols; j++)
		{
            if(golGrid[i][j] == 1)
			{ 
                if ( countGrid[i][j] < 2 || countGrid[i][j] >=4 )
				{
                	golGrid[i][j] = 0;
                }        
            }
            else {   //if cell is empty   
                if(countGrid[i][j] == 3){ //if cell = 3 neighbors
                    golGrid[i][j] = 1;  // new cell created
                }        
            }
        }
    }
}

//MAIN
int main(int argc, char *argv[])
{
    srand(time(NULL)); // see rand num gen once at start
    int useRows = 20, useCols = 20;   //  how many rows and col out of array we actually use
    int rowIndex, colIndex;
  
    // create a 2D array double         
    int golGrid[MAXROWS][MAXCOLS];      
      
		// CREATING A CUSTOM WALKER and BLINKER (uncomment to add back)
		/* 
		  ={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
          	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},{0,0,1,0,1,0,0,0,0,0},    
            {0,0,1,1,0,0,0,1,1,1},{0,0,0,1,0,0,0,0,0,0},{0},{0},{0}{0}}; 
		*/
    
    int golNeighborCounts[MAXROWS][MAXCOLS]; // creating 2d arronud of nei counts
    

// A Random generated game of life grid
  
    // fill it with random numbers 
    for (rowIndex = 0; rowIndex < useRows; rowIndex++) // loop over rows
    {
        for (colIndex = 0; colIndex < useCols; colIndex++) // loop over columns
        {
            golGrid[rowIndex][colIndex] = rand() % 2;  // remainder of divided by 2 is 0 or 1
        }
    }
     
    //print the array to the terminal... neatly with columns and rows.
    printTableofInts(golGrid,useRows,useCols);
    printGameofLife(golGrid,useRows,useCols);
    
    countNeighbors(golGrid, golNeighborCounts, useRows, useCols);
    printTableofInts(golNeighborCounts, useRows, useCols);
    
    countNeighbors(golGrid, golNeighborCounts, useRows, useCols);
    printTableofInts(golNeighborCounts, useRows, useCols);
    
    
    ///////////////////////////////////
    while(1){
    printf("-----------------\n");
    printGameofLife(golGrid,useRows,useCols);
    updateGameOfLife(golGrid,useRows,useCols);
    usleep(250000);
	printf("-----------------\n");
    system("clear");

    }
}
