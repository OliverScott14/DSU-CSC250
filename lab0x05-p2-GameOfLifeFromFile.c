#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>



// defining the max size of 2d array

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

// prints the GOL board
void printGameofLife(int table[MAXROWS][MAXCOLS], int nRow, int nCols)
{
    int i, j;
    for (i = 0;i < nRow; i++) 
    {
        for (j = 0; j < nCols; j++)
        {
            if ( table[i][j] == 1){
                printf("*");
            } else {
                printf(" ");
            }  
            //printf("%5d", table[i][j]); 
        } 
        printf("\n");
    }
}

// takes 2 2d int arrays and conuts the neighbors of each 'house'/'cell' 
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
        for(int j = 0; j < nCols; j++){
            if(golGrid[i][j] == 1){ 
                if ( countGrid[i][j] < 2 || countGrid[i][j] >=4 ){
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
int main(int argc, char *argv[])
{
    
    int useRows, useCols;   //  how many rows and col out of array we actually use
    int rowIndex, colIndex;
    
    // create a 2D array double         
    int golGrid[MAXROWS][MAXCOLS];      
    
// First:   Read the file and set the game of life 2D array values to 1 or 0 accordingly.    
   
    //file pointer
    FILE * golFile;
    // retrieves the data from the file
    golFile = fopen(argv[1], "r");
    if (golFile ==NULL){
        printf("*****File not found!!!\n");
        exit(1); // this lib funtion forces program to exit from any point
    }           // needs an integer which will be the error status of our program
    // scanning the files first line which should contain the 2 integers & sets the useRows & useCols (size)
    fscanf(golFile, "%d %d", &useRows, &useCols);
    
    // Each line after that will have exactly width characters:  
    // spaces or asterisk (or whatever symbol for live cells, maybe O or O.
    char cell;   // char variable to temp store the population data in order from the file
	
	for( int i = 0; i < useRows; i++)
    {
		for( int j = 0; j < useCols; j++)
		{
			fscanf(golFile, "%c", &cell); 
 			if(cell == '*') {golGrid[i][j] = 1;} // if %char is an '*' , store as 1
			else { golGrid[i][j] = 0;} // else store as 0 
		}
	}		 
			

    
// Second : plays the game of life and shows how the initial population in the file evolves.

    
    ///////////////////////////////////
    // Prints each round of the GOL with a pause and clear screen inbetween 
    while(1){
    printf("-----------------------------\n");
    printGameofLife(golGrid,useRows,useCols);
    //usleep(1000000);
    //printf("-----------------------------\n");
    updateGameOfLife(golGrid,useRows,useCols);
    printf("-----------------------------\n");
	usleep(1200000);
    system("clear");

    }
    
}












