#include "barriers.h"

// I apologize for my complete lack of knowledge of C. I'm learning threading while writing this,
// with my only 2 brain cells that survived midterms week.

// general idea: counter notified when each thread arrives, spins for both exit & entry
void central(pthread_t* threads, int n) {
  int* counter = 0;
  for (int i=0; i<n; i++) {
    pthread_create(&threads[i], NULL, sim_process, counter);
  }
  while (&counter < n) { }  // spin
}

// general idea: on round i, starting at 0, tell person i to the left that you’ve entered at barrier

// simulate a process that takes a thread some amount of time
void sim_process(void* counter) {
  int t = rand() % 10;
  sleep(1/t);
  *((int*)result)++;  // this is probably really bad, just a placeholder until I figure out the right way
  printf("%d\n", &counter);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Required argument: number of threads");
    exit(-1);
  }
  int n = (int)strtol(argv[1], NULL, 10);
  //
  pthread_t* threads = (pthread_t*)malloc(sizeof(pthread_t)*n);
  printf("Testing %f threads with centralized barrier...", n);
  central(threads);

  free(threads);
}
