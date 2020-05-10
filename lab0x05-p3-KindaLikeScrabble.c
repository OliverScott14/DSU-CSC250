#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWCOUNT 50  
#define COLCOUNT 50	

char scrabbleTable[ROWCOUNT][COLCOUNT]; 
// Kind of like scrabble, starts with a scrabble board, ask user for row/col and direction and the word to use. 
// then updates the board with that information 


/*  @ program repeatedly asks the user to enter row#,col#, (d) for down or (a) for across, then the user types a word.
    @ Your program then re-displays the grid with the word added
    @ Your program will refuse to add a word if it crosses another word(s) and the letters at the cross point do not match.
*/
    
/*char* enterScabbleWord()//double scabbleGrid[ROWCOUNT][COLCOUNT], int nRow, int nCols)
//{
    char newWord[4]; // 2d array to store the new word and the corrdinates and direction
    
    //init variables
    int row, col, dir;
    char direction;
    char word;
    
    // coordinates
    printf("Enter row# & col# : ");
    scanf("%d %d",&row, &col);
    
    // direction
    printf("Enter d for down and a for across : ");
    scanf(" %c", &direction);
    // converting direction to integers
    
    
    // new word
    printf("Enter word : ");
    scanf(" %c", &word);
    
    
    if(&direction == "d"){dir = 0;}
    if(&direction == "a"){dir = 1;}
    
    newWord[0] = row;
    newWord[1] = col;
    newWord[2] = dir;
    newWord[3] = word;
    
    
    return newWord;
    //else { printf("Invalid entries. Please start over"); exit(1);} // exits if invalid direction    
    /*
	for (rowIndex = 0; rowIndex < useRows; rowIndex++) // loop over rows
    {
        for (colIndex = 0; colIndex < useCols; colIndex++) // loop over columns
        {
            golGrid[rowIndex][colIndex] = rand() % 2;  // remainder of divided by 2 is 0 or 1
        }
    }
    
}
*/





void createScrabbleBoard(char scrabbleTable[ROWCOUNT][COLCOUNT], int nRow, int nCols)
{
    for (int i = 0;i <= nRow; i++) //loop for row
    {   
        for (int j = 0; j <= nCols; j++) // loop for column
        {scrabbleTable[i][j] = '-';} // storing "blank('-') "characters to fill new board
    } 
}



//prints initial scabble board 
void printScrabbleBoard(char scrabbleTable[ROWCOUNT][COLCOUNT], int nRow, int nCols)
{   
// -------- PRINTING -------------

    int i,j;
    // loop to print the top column #s
    for (i = 0;i <= nCols; i++) {printf("%4d", i);} // prints column numbers across the top
    
    printf("\n"); // enter next line after 21 columns #s are printed on row 0
    
    for (i = 0;i <= nRow; i++) // row (outter loop)
    {
        printf("%4d", i+1); // prints the row # each iteration , before entering the nested loop for the column data
        
        // nested loop to print the current rows column data
        for (j = 0; j < nCols; j++) {printf("%4c", scrabbleTable[i][j]);} // printing the scrabble array data for that row 
        
        printf("\n"); //new line before outter loop (rows) iterates
    }
}



void updateScrabble(char scrabbleTable[ROWCOUNT][COLCOUNT], int nRows, int nCols )
{
   
   
     //init variables
    int i, j;
    int row, col;
    int dir;
    char newword[20];

    // coordinates
    printf("Enter row# & col# : ");
    scanf("%d %d",&row, &col);
    
    
    // direction
    printf("Enter 1 for down and 2 for across : ");
    scanf("%d", &dir);
  
   
    // new word
    printf("Enter word : ");
    scanf(" %c", newword);
    // printf("%c", newword);
    
    // char* word = "%c", newword; // sets new word into a char array 
    
    int length = strlen(newword);
        //printf("%d\n", wlength);
        //printf("row: %d , col: %d\n", row, col); 
    
    // loop through new word array , and check if new word will fit / be accepted on the current board 
    int freeDown = 0;
    int freeAcross = 0;
    int freeSpaceDown = 0;
    int freeSpaceAcross= 0;
    
    
    //printf("\n Current Tile: _%c_\n", scrabbleTable[5][5]);
    
    for( i = row; i < length; i++)
    {
        if(scrabbleTable[i][col] == '-')
        {
            freeSpaceDown = freeSpaceDown+1; 
            //printf("\n\nfree: %d , length: %d\n\n", freeSpaceDown, length);  
        }
        //printf("\n\nfree: %d , length: %d\n\n", freeSpaceDown, length);
    }
    //printf("\n\nfree: %d , length: %d\n\n", freeSpaceDown, length);
    if(freeSpaceDown == length){freeDown = 1;}
    
    for( i = col; i < length; i++)
    {
        if(scrabbleTable[row][i] == '-')
        {
            freeSpaceAcross++;   
        }
    }
    if(freeSpaceAcross == length){freeAcross = 1;}
    
    
    
    if (dir == 1)
    {
        if( freeDown == 1 )
        {
            for( i = row; i < length; i++)
            { 
                scrabbleTable[i][col] =  newword[i];
            }
        }
        else  //Testing board for tiles going DOWN
        {   
             //reseting counters
            freeSpaceDown = 0;
            freeDown = 0;
            
            if(scrabbleTable[i][col] != '-')
            {
                
                char c = scrabbleTable[i][col];
                char n = newword[i];
                if(n == c){freeSpaceDown++;}                                    
            }
            // if no tile conflict, enter new word into array
            if( freeSpaceDown = length)
            {
                for( i = row; i < length; i++)
                { 
                scrabbleTable[i][col] =  newword[i];
                }
            } 
        }
    }
        
  /*  if (direction == 2)
        {
            for( i = col; i < length; i++)
            {
                if(scrabbleTable[i][col] != '-')
                {
                    char c = scrabbleTable[i][col];
                    char n = newword[i];
                }
            }
        
        }  
    } 
    */ 
    
    
    // loop to print the top column #s
    for (i = 0;i <= nCols; i++) {printf("%4d", i);} // prints column numbers across the top
    
    printf("\n"); // enter next line after 21 columns #s are printed on row 0
    
    for (i = 0;i <= nRows; i++) // row (outter loop)
    {
        printf("%4d", i+1); // prints the row # each iteration , before entering the nested loop for the column data
        
        // nested loop to print the current rows column data
        for (j = 0; j < nCols; j++) {printf("%4c", scrabbleTable[i][j]);} // printing the scrabble array data for that row 
        
        printf("\n"); //new line before outter loop (rows) iterates
    }
  
}


int main(int argc, char *argv[])
{
		
     //  how many rows and col out of array we actually use
    int nRow = 21, nCol = 21;
  
    // create a 2D array double         
    char scrabbleTable[ROWCOUNT][COLCOUNT]; 
    

	//initical board creation
    createScrabbleBoard(scrabbleTable, nRow, nCol);
    
   
	printScrabbleBoard(scrabbleTable, nRow, nCol);
	updateScrabble(scrabbleTable, nRow, nCol);
	
  
}




