#include "barriers.h"

// general idea: counter notified when each thread arrives, spins for both exit & entry
void central(pthread_t* threads, int n) {
  int counter = 0;
  for (int i=0; i<n; i++) {
    pthread_create(&threads[i], NULL, sim_process, &counter);
  }
  while (&counter < n) { }  // spin
}

// simulate a process that takes a thread some amount of time
void sim_process(void* counter) {
  int t = rand() % 10;
  sleep(1/t);
  // need a way to increment a shared counter. Don't know if this is possible, couldn't find an answer.
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
