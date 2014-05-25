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

	int i;
	CircularQueue *q1 = (CircularQueue **) p;
	CircularQueue *q2;
	queue_init(&q2, QUEUE_SIZE);
	QueueElem prime = queue_get(q1); //first number obtained is a guaranteed prime number
	printf("Additional thread called, the prime is %d\n", prime);
	if(prime != 0) {
	primes.values[primes.used] = prime;
	primes.used++;
	QueueElem tmp; //the number we're going to evaluate in the cycle
	QueueElem previous = 0;
	void * tret;
	pthread_t t1;
	/*
	if(prime > max) { //if the prime number is equal or greater than sqrt(N)
		do {
			tmp = queue_get(q1);
			if(tmp != 0 || tmp % prime != 0) {
				primes.values[primes.used] = tmp;
				primes.used++;
			}
		} while(tmp != 0);
	} else {
		pthread_create(&t1, NULL, operator, (void *) q2);
		if(tmp % prime != 0)
			queue_put(q2, tmp);
	}
	*/
	

		//if(prime < max) {
			pthread_create(&t1, NULL, operator, (void *) q2);
			puts("new thread created");

			do {
				tmp = queue_get(q1);
				if(tmp != previous) {
					if(tmp % prime != 0) {
						printf("%d is not a multiple of %d\n", tmp, prime);
						queue_put(q2, tmp);
					} else printf("%d is multiple of %d\n", tmp, prime);
				} else {
					q1->first++;
					previous = tmp;
				}
			} while(tmp != 0);	
		/*} else {
			while(tmp != 0) {
				primes.values[primes.used] = queue_get(q1);
				primes.used++;
			}
		}
	*/
		//if(prime < max) {
			queue_put(q2, 0);
			pthread_join(t1, tret);
		}
		queue_destroy(q2);
	//}
	
}

void *initialize() {
	puts("Initial thread called.");
	if(N > 2) {
		pthread_t t1;
		void * tret;
		CircularQueue *q;
		queue_init(&q, QUEUE_SIZE);

		primes.values[0] = 2;
		primes.used++;

		pthread_create(&t1, NULL, operator, (void *) q);

		QueueElem i;

		for( i = 3; i <= N; i += 2) {
			printf("Putting %d into the first queue\n", i);
			queue_put(q, i);
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
	primes.values = malloc((ceil(1.2 * (double)N/log(N)) + 1) * sizeof(QueueElem));
	primes.size = (ceil(1.2 * (double)N/log(N)) + 1) * sizeof(QueueElem);
	primes.used = 0;

	int terror; //thread error on creation
	pthread_t thread;
	void * tret; //thread return

	terror = pthread_create(&thread, NULL, initialize, NULL);
	pthread_join(thread, tret);

	//qsort(primes.values, primes.used, sizeof(unsigned int), comparisonFunction); //Sort the shared memory buffer

	//print results
	puts("Prime numbers are:");
	unsigned int i;
	for(i = 0; i < primes.used; i++) {
		printf(" %d\n", primes.values[i]);
	}

	return 0;
}

	
