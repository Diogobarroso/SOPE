#include <semaphore.h>

//------------------------------------------------------------------------------------------ 
// Type of the circular queue elements 
 
typedef unsigned long QueueElem; 
 
//------------------------------------------------------------------------------------------ 
// Struct for representing a "circular queue" 
// Space for the queue elements will be allocated dinamically by queue_init() 
 
typedef struct { 
	QueueElem *v; // pointer to the queue buffer
	unsigned int capacity; // queue capacity 
	unsigned int first; // head of the queue 
	unsigned int last; // tail of the queue 
	sem_t empty; // semaphores and mutex for implementing the 
	sem_t full; // producer-consumer paradigm
} CircularQueue;

void queue_init(CircularQueue **q, unsigned int capacity);
void queue_put(CircularQueue *q, QueueElem value);
QueueElem queue_get(CircularQueue *q);
void queue_destroy(CircularQueue *q);
