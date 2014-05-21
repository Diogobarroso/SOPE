#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max;

char SHM_NAME[] = "/shm1";
unsigned int primes[100];

void *operator(void *p) {
	CircularQueue q;
	queue_init(q, 10);

	unsigned int prime = queue_get(p); //guaranteed prime number
	unsigned int tmp; //the number we're going to evaluate in the cycle
	unsigned int i;
	pthread_t t1;

	//OCUPA MUTEXES
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

	pthread_t t1;
	//put 2 in the shared memory
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
}

int main(int argc, char *argv[]) {
	max = sqrt(argv[argc - 1]); //no need to calculate past this point, every remaining number will be a prime

	int shmid;
	int terror; //thread error on creation
	pthread_t thread;
	void **tret; //thread return

	if(shmid = shm_open(SHM_NAME, O_RDWR, 0600 < 0) {
		perror("Error in shm_open()");
	}

	/*...*/

	terror = pthread_create(thread, NULL, initialize, NULL);
	pthread_join(thread, tret);

	qsort(); //Sort the shared memory buffer	
};

	