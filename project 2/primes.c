#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "circbuffer.h"

#define QUEUE_SIZE 10

int N;
int max;
struct dynArray{
	unsigned int * values;
	unsigned int size;
	unsigned int used;
} primes;

struct threadParams {
	CircularQueue *q;
	int n;
};

void *operator(void *p) {
	printf("Aditional thread called.");
	CircularQueue *q1 = p->q; //queue maintained with last thread
	CircularQueue *q2;
	queue_init(&q2, QUEUE_SIZE);

	unsigned int prime = queue_get(p); //first number obtained is a guaranteed prime number
	

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

	threadParams params;
	params->q = q2;
	params->n = (p->n) + 1;

	if(tmp < max) { //INCOMPLETE
		pthread_create(t1, NULL, operator, &params);
		pthread_join(t1);
	}
}

void *initialize() {
	printf("Initial thread called.");
	if(N > 2) {
		pthread_t t1;
		void * tret;
		CircularQueue *q;
		queue_init(&q, QUEUE_SIZE);

		primes.values[0] = 2;
		primes.used++;

		unsigned int i;

		for( i = 3; i < max; i + 2) {
			/*
			if(q->full < q->capacity)
				queue_put(q, i);
			else {
				i--;
				sem_wait(q->full);
			}*/
			queue_put(&q, i);
		}

		queue_put(q, 0);

		threadParams params;
		params.q = q;
		params.n = 3;

		pthread_create(t1, NULL, operator, &params);
		pthread_join(t1, tret);
	} else {
	
	}
}

int comparisonFunction(void * a, void * b) {
	return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]) {
	printf("Primes program started.");

	if(argc > 2 || atoi(argv[1])) {
		printf("Use of primes: primes [max number]");
		exit(EXIT_FAILURE);
	}

	N = argv[1];
	max = (int)sqrt(N); //no need to calculate past this point, every remaining number will be a prime

	//array preparation
	primes.values = malloc((int)(1.2 * (N / ln(N))) * sizeof(unsigned int));
	primes.size = (int)(1.2 * (N / ln(N))) * sizeof(unsigned int);
	primes.used = 0;

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
		printf(" %d", primes.values[i]);
	}

	printf("Primes program completed successfully.");

	return 0;
}

	