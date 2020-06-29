/* This program uses the higher order function foldl in order to find the
 * required values. Foldl is just a catamorphism.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_TESTS 100

typedef void *(*accumulator)(void *, int*);

/* Fold over the array, accumulating values */
void *foldl(accumulator, void *, int *, int);

void printScores(int a[MAX_TESTS], int n); //the list of function prototypes
int readTestsFromFile(char *fileName, int t[MAX_TESTS]);
float calcAverage(int test[MAX_TESTS], int n);
int findMaxScore(int test[MAX_TESTS], int n);
int findMinScore(int test[MAX_TESTS], int n);


int main()
{
   int test[MAX_TESTS];
   int  n = 0;
   float average;

   n = readTestsFromFile("test_scores.txt", test);
   if (n > 0) {
       printf("%d scores read...\n", n);
       printScores(test, n);

       average = calcAverage(test,n);
       printf("avg = %.2f\n",  average);

       printf("maximum score = %d\n", findMaxScore(test, n));
       printf("minimum score = %d\n", findMinScore(test, n));
   }
#if defined(WIN32)
   system("pause");
#else
   printf("Enter any key to continue... \n");
   getchar();
#endif
    return EXIT_SUCCESS;
}

int readTestsFromFile(char *fileName, int test[MAX_TESTS]) {
    int count = 0;
    FILE *filePtr = fopen(fileName, "r");

    if(filePtr == NULL) {
        printf("Unable to find the data file\n");
        return 0;
    }
    do {
        fscanf(filePtr, "%d", test + count);
        ++count;
    } while(test[count - 1] != -1 && count < MAX_TESTS);

  return (count == MAX_TESTS) ? count : count - 1;
}

/* Accumulating functions */

void *max(void *y, int *x) {
    return (*x > *(int*)y) ? x : y;
}

void *min(void *y, int *x) {
    return (*x < *(int*)y) ? x : y;
}

void *sum(void *y, int *x) {
    *(int*)y += *x;
    return y;
}

void *print(void *y, int *x) {
    printf("%d ", *x);
    return NULL;
}

void *foldl(accumulator f, void *base, int *arr, int arr_size) {
    if (arr_size == 0)
        return base;
    return foldl(f, f(base, arr), arr + 1, arr_size - 1);
}

void printScores(int a[MAX_TESTS], int n) {
    foldl(print, NULL, a, n);
    putchar('\n');
}

float calcAverage(int test[MAX_TESTS], int n) {
    int initial = 0;
    return (float)(*(int*)foldl(sum, &initial, test, n)) / ((float)n);
}

int findMaxScore(int test[MAX_TESTS], int n) {
    int initial = *test;
	return *(int*)foldl(max, &initial, test, n);
}

int findMinScore(int test[MAX_TESTS], int n) {
    int initial = *test;
	return *(int*)foldl(min, &initial, test, n);
}
