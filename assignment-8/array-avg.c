/*

   CSCI 1111
   This example illustrates using an array to
   process a set of test scores
   make sure the file test_scores.txt is in the same directory as this file

   Your assignment is to finish the following functions:

   printScores

   findMinScore

   findMaxScore

   calculateAverage


*/



#include <stdio.h>
#include <stdlib.h>

#define MAX_TESTS 100


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
   printf("%d scores read...\n", n);
   printScores(test, n);

   average = calcAverage(test,n);
   printf("avg = %.2f\n",  average);

   printf("maximum score = %d\n", findMaxScore(test, n));
   printf("minimum score = %d\n", findMinScore(test, n));   
   system("pause");

   

   return EXIT_SUCCESS; 

}



/*

   This function was written by Kevin Lee

   it works, do not change!!!!

*/

int readTestsFromFile(char *fileName, int test[MAX_TESTS])
{
   int count = 0;
   int value;
   FILE *filePtr;

   filePtr = fopen(fileName, "r");

   if( filePtr == NULL)
   {
      printf("Unable to find the data file\n");
      return 0;
   }


   do{
     fscanf(filePtr, "%d", &value);

     if(value > -1){
            test[count] = value;
            ++count;
     }

   }while(value > -1 && count < MAX_TESTS);

  return count;
}



void printScores(int a[MAX_TESTS], int n)
{
    printf("printScores under construction\n");
}



float calcAverage(int test[MAX_TESTS], int n)

{
  float avg = 0.0;
  

  return avg;
}



int findMaxScore(int test[MAX_TESTS], int n)

{
	
	int max = 999;

   return max;
}



int findMinScore(int test[MAX_TESTS], int n)

{

   int min_score = -999;
 
   
    return min_score;

}



