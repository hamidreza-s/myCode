//========================================================================
// Queue Array
//========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//------------------------------------------------------------------------
// Types: queue_t
//------------------------------------------------------------------------
typedef struct queue {
  int front, rear, size;
  unsigned capacity;
  int *array;
} queue_t;

//------------------------------------------------------------------------
// Function: create_queue
//------------------------------------------------------------------------
queue_t *create_queue(unsigned capacity) {
  queue_t *queue = (queue_t*) malloc(sizeof(queue_t));
  queue->capacity = capacity;
  queue->front = 0;
  queue->size = 0;
  queue->rear = capacity - 1;
  queue->array = (int*) malloc(queue->capacity * sizeof(int));
  return queue;
}

//------------------------------------------------------------------------
// Function: is_full
//------------------------------------------------------------------------
int is_full(queue_t *queue) {
  return (queue->size == queue->capacity);
}

//------------------------------------------------------------------------
// Function: is_empty
//------------------------------------------------------------------------
int is_empty(queue_t *queue) {
  return (queue->size == 0);
}

//------------------------------------------------------------------------
// Function: enqueue
//------------------------------------------------------------------------
void enqueue(queue_t *queue, int item) {
  if(is_full(queue))
    return;

  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = item;
  queue->size = queue->size + 1;
  printf("%d enqueued to queue\n", item);
}

//------------------------------------------------------------------------
// Function: dequeue
//------------------------------------------------------------------------
int dequeue(queue_t *queue) {
  if(is_empty(queue))
    return INT_MIN;

  int item = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size = queue->size - 1;
  return item;
}

//------------------------------------------------------------------------
// Function: front
//------------------------------------------------------------------------
int front(queue_t *queue) {
  if(is_empty(queue))
    return INT_MIN;

  return queue->array[queue->front];
}

//------------------------------------------------------------------------
// Function: rear
//------------------------------------------------------------------------
int rear(queue_t *queue) {
  if(is_empty(queue))
    return INT_MIN;

  return queue->array[queue->rear];
}

//------------------------------------------------------------------------
// Function: main
//------------------------------------------------------------------------
int main() {

  queue_t *queue = create_queue(1000);
  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);

  printf("%d dequeued from queue\n", dequeue(queue));

  printf("Front item is %d\n", front(queue));
  printf("Rear item is %d\n", rear(queue));

  return 0;
  
}
