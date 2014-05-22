//------------------------------------------------------------------------------------------ 
// Allocates space for circular queue 'q' having 'capacity' number of elements 
// Initializes semaphores & mutex needed to implement the producer-consumer paradigm 
// Initializes indexes of the head and tail of the queue 
// TO DO BY STUDENTS: ADD ERROR TESTS TO THE CALLS & RETURN a value INDICATING (UN)SUCESS 
 
void queue_init(CircularQueue **q, unsigned int capacity) // TO DO: change return value 
{ 
	*q = (CircularQueue *) malloc(sizeof(CircularQueue)); 
	sem_init(&((*q)->empty), 0, capacity); 
	sem_init(&((*q)->full), 0, 0); 
	pthread_mutex_init(&((*q)->mutex), NULL); 
	(*q)->v = (QueueElem *) malloc(capacity * sizeof(QueueElem)); 
	(*q)->capacity = capacity; 
	(*q)->first = 0; 
	(*q)->last = 0; 
} 
 
//------------------------------------------------------------------------------------------ 
// Inserts 'value' at the tail of queue 'q' 
 
void queue_put(CircularQueue *q, QueueElem value) 
{ 
 // TO DO BY STUDENTS 
} 
 
//------------------------------------------------------------------------------------------ 
// Removes element at the head of queue 'q' and returns its 'value' 
 
QueueElem queue_get(CircularQueue *q) 
{ 
 // TO DO BY STUDENTS 
} 
 
//------------------------------------------------------------------------------------------ 
// Frees space allocated for the queue elements and auxiliary management data 
// Must be called when the queue is no more needed 
 
void queue_destroy(CircularQueue *q) 
{ 
 // TO DO BY STUDENTS 
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

