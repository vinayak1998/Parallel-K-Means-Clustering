#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <pthread.h>
#include <string.h>

#ifndef CORES
#define CORES 4
#endif

long count;
int t = CORES;
long length;
int *array;

pthread_mutex_t lock;

void printA (int * arr, int sz){
  int i;
  for (i =0; i<sz; i++) {
    printf("%d \n", arr[i]);
  }
}

void count3s_seq()
{
  long i;
  for (i=0; i<length; i++)
    if(array[i] == 3)
      count++;
}

void* count3s_thread(void *tid)
{

  int *id = (int*) tid;
  int length_per_thread = length/t;

  int start = (*id)*length_per_thread;

  int i;

  int private_count = 0;

  for(i =start; i < start+length_per_thread; i++)
  {
    if (array[i] == 3){
			private_count += 1;
    }
  }
  pthread_mutex_lock(&lock);
  count += private_count;
  pthread_mutex_unlock(&lock);
  return NULL;
}

int main (int argc, char *argv[])
{
  int i = 0;
  count = 0 ;

	if (argc < 2) {
		fprintf(stderr, "no args supplied\n");
		exit(1);
	}
	if (argc > 2)
		length = 1024*1024*atoi(argv[2]);
	else
		length = 1024*1024*50;

  pthread_t count3s_thr[t];


  /* Array init */
  srand(1);
  array = (int*) malloc (sizeof(int)*length);
  for (i = 0; i < length; i ++)
    array[i] = rand()%5;

  int *tid = (int *) malloc (sizeof (int) * t);
  pthread_mutex_init(&lock, NULL);

  double start, end;
  start = omp_get_wtime();

  if(strcmp(argv[1],"p") == 0){
    /* parallel impl */
    for (i = 0; i < t; i ++) {// i on heap?
			tid[i] = i;
			pthread_create(&count3s_thr[i], NULL, count3s_thread, &tid[i]);
    }
    for (i = 0; i < t; i ++)
      pthread_join(count3s_thr[i], NULL);
  }

  else if (strcmp(argv[1],"s") == 0){
    /* seq impl */
    count3s_seq();
  }
  else {
    printf("error \n");
    exit(-1);
  }
  end = omp_get_wtime();
  double totalTime = (double)(end - start);

  printf("Number of 3s found: %ld, in time %.2lf \n", count, totalTime);

  //  printA(array, length);
  return 0;
}
