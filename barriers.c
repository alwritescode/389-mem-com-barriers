#include "barriers.h"

// general idea: counter notified when each thread arrives, spins for both exit & entry
void central() {

}


int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Required argument: number of threads");
    exit(-1);
  }
  n = (int)strtol(argv[1], NULL, 10);

}
