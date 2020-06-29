/*
		Minesweeper
		
		Finish the game
		
		Finish counting the untouched cells
		use that function to finish the game.
		In other words tell when they win or lose.

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UNTOUCHED -1
#define BOMB -2
#define MAX_GRID 20

//#define DEBUG

int getRand(int first, int last);
void clearGrid(int grid[MAX_GRID][MAX_GRID], int n);

void addBombs(int grid[MAX_GRID][MAX_GRID], 
				int n, int nBombs);
				

void printGrid(const int grid[MAX_GRID][MAX_GRID], int n);

int countSurroundingBombs(int row, int col,
		const int grid[MAX_GRID][MAX_GRID], int n);
		
void testBombCounter(const int grid[MAX_GRID][MAX_GRID], int n);
void tryMove(int row, int col,  int grid[MAX_GRID][MAX_GRID], int n); 

int countUntouched(const int grid[MAX_GRID][MAX_GRID], int n);

int main()
{
	int mine_grid[MAX_GRID][MAX_GRID];
	int n = 4;
	int row, col;
	int blewUp = 0;
	
	
	clearGrid(mine_grid, n);
	addBombs(mine_grid, n, 8);
	printGrid(mine_grid, n);
	putchar('\n');
	
	do{
		printf("enter row and col\n");
		scanf("%d%d", &row, &col);
		if (mine_grid[row][col] == BOMB){
			printf("Bang!\n");
			blewUp = 1;
		}else{
			tryMove(row, col, mine_grid, n);
		}
		putchar('\n');
		printGrid(mine_grid, n);
		putchar('\n');
	}while(!blewUp );
	
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
		//	if (grid[i][j]==BOMB || grid[i][j] == UNTOUCHED){
		//		printf(" * ");
		//	}else{
				printf("%3d", grid[i][j]);
		//	}
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
		int count = 0, r, c;
		int i, j;
		
		for (i = -1; i <= 1; ++i){
			for (j = -1; j <= 1; ++j){
				r = row + i; c = col + j; 
				if (i == 0 && j == 0)
					continue;
				if(r>= 0 && r < n && c >= 0 && c < n
		   			&& grid[r][c] == BOMB)
						++count;
			}
		}
		
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

void tryMove(int row, int col,  int grid[MAX_GRID][MAX_GRID], int n)
{
	int count;
#ifdef DEBUG
	printf("Entering tryMove(%d, %d ....)\n", row, col);
#endif	
		
	if (grid[row][col] != UNTOUCHED){	
#ifdef DEBUG
        printf("%d %d already touched\n", row, col);
	    printf("leaving tryMove(%d, %d ....)\n", row, col);
#endif			
		return; //already been visited
	}
	
	count = countSurroundingBombs(row, col, grid, n);
	grid[row][col] = count;
	
	if (count == 0){
		int i, j, r, c;
		for (i = -1; i <= 1; ++i){
			for (j = -1; j <= 1; ++j){
				r = row + i; c = col + j; 
				if (i == 0 && j == 0)
					continue;
				if(r>= 0 && r < n && c >= 0 && c < n){
					
					tryMove(r, c, grid, n);
#ifdef DEBUG
					printf("%d %d\n", r, c);
					printGrid(grid, n);
					system("pause");
#endif					
					
				}		
			}
		}
	}
#ifdef DEBUG
	printf("Leaving tryMove(%d, %d ....)\n", row, col);
#endif	
}

int countUntouched(const int grid[MAX_GRID][MAX_GRID], int n)
{
	
	return 10;
}
