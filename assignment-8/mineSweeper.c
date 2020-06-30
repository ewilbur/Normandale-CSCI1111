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
#include <stdbool.h>

#define DEBUG

#define MAX_GRID 5
#define MAX_NEIGHBORS 8

typedef int tile_t;
typedef int index_t;

static const int MAX_GRID_HEIGHT = MAX_GRID;
static const int MAX_GRID_LENGTH = MAX_GRID;


/* For a given grid, if the value is negative, we do not render it */
enum {
    BOMB = MAX_NEIGHBORS + 1,
    EMPTY = MAX_NEIGHBORS + 2,
};

typedef struct MinesweeperBoard {
    tile_t **grid;
    index_t MAX_X;
    index_t MAX_Y;
} Board;

void hideTile(tile_t *);
void showTile(tile_t *);
char getTileChar(tile_t);
bool inBounds(Board *, index_t, index_t);
tile_t *getBoardTile(Board *, index_t, index_t);
void setBoardTile(Board *, index_t, index_t, tile_t);
void printBoard(Board *);
Board *mkboard(index_t x, index_t y);
void clearBoard(Board *b);
size_t numNeighbors(Board *b, index_t x, index_t y);
size_t numBombNeighbors(Board *b, index_t x, index_t y);

tile_t *getRandomTile(Board *b, index_t *x, index_t *y);

void placeBombs(Board *b, int numBombs);

void hideTile(tile_t *tile) {
    *tile = -abs(*tile);
}

void showTile(tile_t *tile) {
    *tile = abs(*tile);
}

char getTileChar(tile_t tile) {
    if (tile < 0) return '.';
    if (tile < BOMB) return tile + '0';
    switch (tile) {
        case BOMB: return '*';
        case EMPTY: return '_';
        default: return '?';
    }
}

bool inBounds(Board *b, index_t x, index_t y) {
    return (x >= 0) && (y >= 0) && (x < b->MAX_X) && (y < b->MAX_Y);
}

tile_t *getBoardTile(Board *b, index_t x, index_t y) {
    if (!inBounds(b, x, y)) return NULL;
    return b->grid[y] + x;
}

void setBoardTile(Board *b, index_t x, index_t y, tile_t tile) {
    if (!inBounds(b, x, y)) return;
    b->grid[y][x] = tile;
}

void printBoard(Board *b) {
    for (int y = 0; y < b->MAX_Y; ++y) {
        for (int x = 0; x < b->MAX_X; ++x) {
            printf(" %c ", getTileChar(*getBoardTile(b, x, y)));
        }
        putchar('\n');
    }
}

Board *mkboard(index_t x, index_t y) {
    Board *b = (Board *)malloc(sizeof(Board));
    b->MAX_X = x;
    b->MAX_Y = y;
    b->grid  = (tile_t **)calloc(b->MAX_Y, sizeof(tile_t*));
    for (int i = 0; i < b->MAX_Y; ++i)
        b->grid[i] = (tile_t*)calloc(b->MAX_X, sizeof(tile_t));
    clearBoard(b);
    return b;
}

void clearBoard(Board *b) {
    for (int y = 0; y < b->MAX_Y; ++y) {
        for (int x = 0; x < b->MAX_X; ++x) {
            setBoardTile(b, x, y, -EMPTY);
        }
    }
}

size_t numNeighbors(Board *b, index_t x, index_t y) {
    size_t count = 0;
    for (int j = -1; j < 2; ++j) {
        for (int i = -1; i < 2; ++i) {
            if (i == 0 && j == 0) continue;
            if (inBounds(b, x + i, y + j)) count++;
        }
    }
    return count;
}

size_t numBombNeighbors(Board *b, index_t x, index_t y) {
    size_t count = 0;
    for (int j = -1; j < 2; ++j) {
        for (int i = -1; i < 2; ++i) {
            tile_t *board_tile;
            if (i == 0 && j == 0) continue;
            board_tile = getBoardTile(b, x + i, y + j);
            if (board_tile == NULL) continue;
            if (abs(*board_tile) == abs(BOMB)) count++;
        }
    }
    return count;
}

tile_t *getRandomTile(Board *b, index_t *x, index_t *y) {
    static bool rand_seeded = false;
    if (!rand_seeded) {
#ifdef DEBUG
        srand(0);
#else
        srand(time(0));
#endif
        rand_seeded = true;
    }
    *x = rand() % b->MAX_X;
    *y = rand() % b->MAX_Y;
    return getBoardTile(b, *x, *y);
}

void placeBombs(Board *b, int numBombs) {
    while (numBombs + 1!= 0) {
        int attempts = 0;
        do {
            int x;
            int y;
            tile_t *tile = getRandomTile(b, &x, &y);
            if (numBombNeighbors(b, x, y) == numNeighbors(b, x, y)) 
                attempts++;
            else if (abs(*tile) == abs(BOMB))
                attempts++;
            else {
#ifdef DEBUG
                *tile = BOMB;
#else
                *tile = -BOMB;
#endif
                numBombs--;
                break;
            }
        } while (attempts < 51);
    }
}

void main_loop(Board *b) {
    while (true) {
        int user_x;
        int user_y;
        do {
            printf("Enter a row (0 - b->%d): ", b->MAX_X);
            scanf("%d", &user_x);
            printf("Enter a column (0 - %d): ", b->MAX_Y);
            scanf("%d", &user_y);
        } while (!inBounds(b, user_x, user_y));
    }
}

int main() {
    Board *b = mkboard(5, 5);
    placeBombs(b, 4);
    printBoard(b);
    printf("Number of neighbors: %lu\n", numBombNeighbors(b, 1,1));
}
