#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>

#include "circbuffer.h"

#define QUEUE_SIZE 10

int N;
int max;

struct dynArray{
	QueueElem * values;
	unsigned int size;
	unsigned int used;
} primes;

void *operator(void *p) {
	puts("Additional thread called.");
	CircularQueue *q1 = (CircularQueue *) p;
	CircularQueue *q2;
	queue_init(&q2, QUEUE_SIZE);
	QueueElem prime = queue_get(q1); //first number obtained is a guaranteed prime number
	primes.values[primes.used] = prime;
	primes.used++;
	QueueElem tmp; //the number we're going to evaluate in the cycle
	QueueElem previous;
	unsigned int i;
	void * tret;
	pthread_t t1;
	
	if(prime != 0) {
		if(prime < max)
			pthread_create(&t1, NULL, operator, &q2);

		do {
			tmp = queue_get(q1);
			printf("tmp = %d\n", tmp);
			if(tmp != previous) {
				printf("capacity = %d", q1->capacity);
				if(tmp % prime != 0)
					queue_put(q2, tmp);
			} else {
				q1->first++;
				previous = tmp;
			}
		} while(tmp != 0);	
	
		if(prime < max)
			pthread_join(t1, tret);
		queue_destroy(q2);
	}
}

void *initialize() {
	puts("Initial thread called.");
	if(N > 2) {
		pthread_t t1;
		void * tret;
		CircularQueue *q;
		queue_init(&q, QUEUE_SIZE);

		primes.values[primes.used] = 2;
		primes.used++;

		pthread_create(&t1, NULL, operator, (void *) q);

		QueueElem i;

		for( i = 3; i < N; i++) {
			printf("I've put %d in the queue\n", i);
			queue_put(q, i);
			i++;
		}

		queue_put(q, 0);

		pthread_join(t1, tret);
	} else {
	
	}
}

int comparisonFunction(void * a, void * b) {
	return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]) {
	puts("Primes program started.");

	if(argc > 2) {
		puts("Use of primes: primes [max number]");
		exit(EXIT_FAILURE);
	}

	N = atoi(argv[1]);
	max = (int)sqrt(N); //no need to calculate past this point, every remaining number will be a prime

	//array preparation
	primes.values = malloc((int)(1.2 * (N / log(N))) * sizeof(unsigned int));
	primes.size = (int)(1.2 * (N / log(N))) * sizeof(unsigned int);
	primes.used = 0;

	int terror; //thread error on creation
	pthread_t thread;
	void * tret; //thread return

	terror = pthread_create(&thread, NULL, initialize, NULL);
	pthread_join(thread, tret);

	qsort(primes.values, primes.used, sizeof(unsigned int), comparisonFunction); //Sort the shared memory buffer

	//print results
	puts("Prime numbers are:");
	unsigned int i;
	for(i = 0; i < max; i++) {
		printf(" %d", primes.values[i]);
	}

	printf("Primes program completed successfully.");

	return 0;
}

	
