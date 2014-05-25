#include "circbuffer.h"

void queue_put(CircularQueue *q, QueueElem value) { sem_wait(&(q->empty));
 (q->v)[q->last] = value; q->last = (q->last + 1) % q->capacity; sem_post(&(q->full)); }
QueueElem queue_get(CircularQueue *q) { QueueElem value; sem_wait(&(q->full));
 value = (q->v)[q->first]; q->first = (q->first + 1) % q->capacity; sem_post(&(q->empty)); return value; }

/*
//------------------------------------------------------------------------------------------ 
// Allocates space for circular queue 'q' having 'capacity' number of elements 
// Initializes semaphores & mutex needed to implement the producer-consumer paradigm 
// Initializes indexes of the head and tail of the queue 
// TO DO BY STUDENTS: ADD ERROR TESTS TO THE CALLS & RETURN a value INDICATING (UN)SUCESS 
 

#include "circbuffer.h"

*/
void queue_init(CircularQueue **q, unsigned int capacity) // TO DO: change return value 
{ 
	*q = (CircularQueue *) malloc(sizeof(CircularQueue)); 
	sem_init(&((*q)->empty), 0, capacity); 
	sem_init(&((*q)->full), 0, 0); 
	(*q)->v = (QueueElem *) malloc(capacity * sizeof(QueueElem)); 
	(*q)->capacity = capacity; 
	(*q)->first = 0; 
	(*q)->last = 0; 
} 
 /*
//------------------------------------------------------------------------------------------ 
// Inserts 'value' at the tail of queue 'q' 

void queue_put(CircularQueue *q, QueueElem value) 
{ 

	sem_wait(&(q->empty));
	q->v[q->last] = value;
	int tmp;
	sem_getvalue(&(q->empty),&tmp);	
	if(tmp != 0)	
		q->last++;

	q->last %= q->capacity;

	sem_post(&(q->full));
} 
 
//------------------------------------------------------------------------------------------ 
// Removes element at the head of queue 'q' and returns its 'value' 
 
QueueElem queue_get(CircularQueue *q) 
{
	QueueElem elem;
	sem_wait(&(q->full));
	elem = q->v[q->first];
	if(q->first != q->last)
		q->first++;
	q->first %= q->capacity;
	sem_post(&(q->empty));
	return elem;
} 
 
//------------------------------------------------------------------------------------------ 
// Frees space allocated for the queue elements and auxiliary management data 
// Must be called when the queue is no more needed 
 */
void queue_destroy(CircularQueue *q) 
{ 
	free(q->v);
	sem_destroy(&(q->empty));
	sem_destroy(&(q->full));
} 
//========================================================================================== 
// EXAMPLE: Creation of a circular queue using queue_init()
/*
#define QUEUE_SIZE 10 // TO DO: test your program using different queue sizes 
... 
CircularQueue *q; 
queue_init(&q,QUEUE_SIZE); 
... 
*/

