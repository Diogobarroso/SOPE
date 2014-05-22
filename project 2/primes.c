#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "circbuffer.h"

#define QUEUE_SIZE 10

int N;
int max;
unsigned int * primes;

struct threadParams {
	CircularQueue *q;
	int n;
};

void *operator(void *p) {
	printf("Aditional thread called.");
	CircularQueue *q = p->q; //queue maintained with last thread
	queue_init(&q, QUEUE_SIZE);

	unsigned int prime = queue_get(p); //guaranteed prime number
	unsigned int tmp; //the number we're going to evaluate in the cycle
	unsigned int i;
	pthread_t t1;

	//ocupa semaforos
	for( i = 0; i < q.capacity; i++) {
		tmp = queue_get(p);
		p->full--;
		if(tmp % prime != 0) {//if it is NOT a multiple
			queue_put(q, tmp);
			q->full++;
	}

	if(tmp < max) { //INCOMPLETE
		pthread_create(t1, NULL, operator, (void) q);
		pthread_join(t1);
	}
}

void *initialize() {
	printf("Initial thread called.");
	if(N > 2) {
		pthread_t t1;
		CircularQueue *q;
		queue_init(&q, QUEUE_SIZE);

		primes[0] = 2;

		unsigned int i;

		for( i = 3; i < max; i + 2) {
			if(q->full < q->capacity)
				queue_put(q, i);
			else {
				i--;
				sem_wait(q->full);
			}
		}

		queue_put(q, 0);

		threadParams params;
		params.q = q;
		params.n = 3;

		pthread_create(t1, NULL, operator, &params);
		pthread_join(
	} else {
	
	}
}

int comparisonFunction(void * a, void * b) {
	return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]) {
	printf("Primes program started.");

	if(argc > 2) {
		printf("Use of primes: primes [max number]");
		exit(EXIT_FAILURE);
	}

	N = argc[1];
	max = (int)sqrt(N); //no need to calculate past this point, every remaining number will be a prime

	int terror; //thread error on creation
	pthread_t thread;
	void * tret; //thread return

	terror = pthread_create(thread, NULL, initialize, NULL);
	pthread_join(thread, tret);

	qsort(primes, max, sizeof(unsigned int), comparisonFunction); //Sort the shared memory buffer

	//print results
	puts("Primes numbers are:");
	unsigned int i;
	for(i = 0; i < max; i++) {
		printf(" %d", primes[i]);
	}

	return 0;
}

	
