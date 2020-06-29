/*
		Minesweeper

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static const int MAX_BOARD_HEIGHT = 20;
static const int MAX_BOARD_WIDTH  = 20;

enum {
    BOMB = 'X',
    UNTOUCHED = '.',
    CLEAR = '_',
};


int main() {}

#if 0

enum {
    UNTOUCHED = -1,
    BOMB = -2,
};

/* #define UNTOUCHED -1 */
/* #define BOMB -2 */
#define MAX_GRID 20

int getRand(int first, int last);
void clearGrid(int grid[MAX_GRID][MAX_GRID], int n);

void addBombs(int grid[MAX_GRID][MAX_GRID], 
				int n, int nBombs);
				

void printGrid(const int grid[MAX_GRID][MAX_GRID], int n);

int countSurroundingBombs(int row, int col,
		const int grid[MAX_GRID][MAX_GRID], int n);
		
void testBombCounter(const int grid[MAX_GRID][MAX_GRID], int n);

int main()
{
	int mine_grid[MAX_GRID][MAX_GRID];
	int n = 6;
	
	clearGrid(mine_grid, n);
	
	addBombs(mine_grid, n, 8);
	
	
	printGrid(mine_grid, n);
	
	putchar('\n');
	
	testBombCounter(mine_grid, n);
	
}

void clearGrid(int grid[MAX_GRID][MAX_GRID], int n)
{
	int i, j;
	
	for(i = 0; i < n; ++i){ //run through rows
		for(j = 0; j < n; ++j){//run through columns
			grid[i][j] = UNTOUCHED;
		}
	}
}

void printGrid(const int grid[MAX_GRID][MAX_GRID], int n)
{
int i, j;
	
	for(i = 0; i < n; ++i){ //run through rows
		for(j = 0; j < n; ++j){//run through columns
			printf("%3d", grid[i][j]);
		}//for j
		printf("\n");
	}	
}

void testBombCounter(const int grid[MAX_GRID][MAX_GRID], int n)
{
	int i, j, count;
	
	for(i = 0; i < n; ++i){ //run through rows
		for(j = 0; j < n; ++j){//run through columns
			count = countSurroundingBombs(i,j, grid, n);
			printf("%3d", count);
		}//for j
		printf("\n");
	}	
}

void addBombs(int grid[MAX_GRID][MAX_GRID], 
				int n, int nBombs)
{
	int row, col, i;
	
	for(i = 0; i < nBombs; ++i){
	
		do{
			row = getRand(0, n-1);
			col = getRand(0, n-1);
		//	printf("%d %d\n", row, col);
		}while(grid[row][col] != UNTOUCHED);//skip repeats
		
		grid[row][col] = BOMB;
	}
}

int countSurroundingBombs(int row, int col,
		const int grid[MAX_GRID][MAX_GRID], int n)
{
		int count = 0;
		
		if(grid[row][col + 1] == BOMB)
			++count;
		
		return count;
}

int getRand(int first, int last)
{
   static int firstTime = 1;
   int amountOfNumbers;
   if (firstTime == 1){
      /*first time in this function, seed the random number generator */
       firstTime = 0;
	   srand(time(NULL));
   }
   amountOfNumbers = last - first + 1;
   return(rand() % amountOfNumbers + first);
}
#endif
