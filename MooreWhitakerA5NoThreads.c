// Allyson Moore
// Keaton Whitaker
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000


int A[ARRAY_SIZE];
int B[ARRAY_SIZE];

// declaring the timing variables
clock_t start, end;
double cpu_time_used;


// function for checksum
int checksum(int arr[])
{
  int sum = 0;
  for(int i = 0; i < ARRAY_SIZE; i++)
  {
    sum += arr[i];
  }
  return sum;
}

// function for addition
int * addition()
{
  static int add[ARRAY_SIZE];
  for(int i = 0; i < ARRAY_SIZE; i++)
	{
		add[i] = A[i] + B[i];
	}
  return add;
}

// function for subtraction
int * subtraction()
{
  static int sub[ARRAY_SIZE];
  for(int i = 0; i < ARRAY_SIZE; i++)
  {
    sub[i] = A[i] - B[i];
  }
  return sub;
}

// function for multiplication
int * multiplication()
{
  static int multi[ARRAY_SIZE];
  for(int i = 0; i < ARRAY_SIZE; i++)
  {
    multi[i] = A[i] * B[i];
  }
  return multi;
}

// function for division
int *division()
{
  static int divi[ARRAY_SIZE];
  for(int i = 0; i < ARRAY_SIZE; i++)
  {
    divi[i] = A[i]/B[i];
  }
  return divi;
}



int main(void) {
  //fills arrays A and B with proper integers
  for(int i = 0; i < ARRAY_SIZE; i++)
  {
    A[i] = 2;
    B[i] = 1;
  }

  int *add;
  int *sub;
  int *multi;
  int *divi;
  int sumA, sumS, sumM, sumD;

	// marking the start time
	start = clock();

	// this is where all the cool functions happen
  add = addition();
  sub = subtraction();
	multi = multiplication();
	divi = division();

	// marking the end time
  end = clock();
	// time in seconds
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	// checksums 
  sumA = checksum(add);
  sumS = checksum(sub);
  sumM = checksum(multi);
  sumD = checksum(divi);

	// reporting the check sums
  printf("addition: %d\n", sumA);
  printf("subtraction: %d\n", sumS);
  printf("multiplication: %d\n", sumM);
  printf("division: %d\n", sumD);
  printf("Time: %f\n", cpu_time_used);
  
  
  
  return 0;
}
