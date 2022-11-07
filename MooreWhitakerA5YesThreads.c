// Allyson Moore
// Keaton Whitaker
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define ARRAY_SIZE 1000000
#define NUM_OF_THREADS 4

int A[ARRAY_SIZE];
int B[ARRAY_SIZE];
int add[ARRAY_SIZE];
int sub[ARRAY_SIZE];
int multi[ARRAY_SIZE];
int divi[ARRAY_SIZE];

// declaring the timing variables
clock_t start, end;
double cpu_time_used;

// creation of threads
pthread_t threads[NUM_OF_THREADS];


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
void *addition()
{
  
  for(int i = 0; i < ARRAY_SIZE; i++)
	{
		add[i] = A[i] + B[i];
	}
  
}

// function for subtraction
void *subtraction()
{
  
  for(int i = 0; i < ARRAY_SIZE; i++)
  {
    sub[i] = A[i] - B[i];
  }
  
}

// function for multiplication
void *multiplication()
{
  
  for(int i = 0; i < ARRAY_SIZE; i++)
  {
    multi[i] = A[i] * B[i];
  }
  
}

// function for division
void *division()
{
  
  for(int i = 0; i < ARRAY_SIZE; i++)
  {
    divi[i] = A[i]/B[i];
  }
  
}



int main(void) {

	pthread_t threads[NUM_OF_THREADS];
	
  //fills arrays A and B with proper integers
  for(int i = 0; i < ARRAY_SIZE; i++)
  {
    A[i] = 2;
    B[i] = 1;
  }

  
  int sumA, sumS, sumM, sumD;

	// marking the start time
	start = clock();

	// thread creation
  pthread_create(&threads[0], NULL, addition, NULL);
  pthread_create(&threads[1], NULL, subtraction, NULL);
  pthread_create(&threads[2], NULL, multiplication, NULL);
  pthread_create(&threads[3], NULL, division, NULL);

	// marking the end time
  end = clock();
  for(int i = 0; i < NUM_OF_THREADS; i++)
  {
    pthread_join(threads[i], NULL);
  }
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
