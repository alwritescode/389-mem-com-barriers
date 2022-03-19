#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void central(pthread_t* threads, int n);
void sim_process(void *counter);
