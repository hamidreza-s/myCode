//========================================================================
// Queue Linked List
//========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//------------------------------------------------------------------------
// Types: queue_node_t
//------------------------------------------------------------------------
typedef struct queue_node {
  int key;
  struct queue_node *next;
} queue_node_t;

//------------------------------------------------------------------------
// Types: queue_t
//------------------------------------------------------------------------
typedef struct queue {
  struct queue_node *front;
  struct queue_node *rear;
} queue_t;

//------------------------------------------------------------------------
// Function: create_queue_node
//------------------------------------------------------------------------
queue_node_t *create_queue_node(int key) {
  queue_node_t *node = (queue_node_t*) malloc(sizeof(queue_node_t));
  node->key = key;
  node->next = NULL;
  return node;
}

//------------------------------------------------------------------------
// Types: create_queue
//------------------------------------------------------------------------
queue_t *create_queue() {
  queue_t *queue = (queue_t*) malloc(sizeof(queue_t));
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

//------------------------------------------------------------------------
// Types: enqueue
//------------------------------------------------------------------------
void enqueue(queue_t *queue, int key) {
  queue_node_t *node = create_queue_node(key);

  if(queue->rear == NULL) {
    queue->front = node;
    queue->rear = node;
    return;
  }

  queue->rear->next = node;
  queue->rear = node;
}

//------------------------------------------------------------------------
// Types: dequeue
//------------------------------------------------------------------------
queue_node_t *dequeue(queue_t *queue) {
  if(queue->front == NULL)
    return NULL;

  queue_node_t *node = queue->front;
  queue->front = queue->front->next;

  if(queue->front == NULL)
    queue->rear = NULL;

  return node;
}

//------------------------------------------------------------------------
// Types: main
//------------------------------------------------------------------------
int main() {

  queue_t *queue = create_queue();

  enqueue(queue, 10);
  enqueue(queue, 20);

  dequeue(queue);
  dequeue(queue);

  enqueue(queue, 30);
  enqueue(queue, 40);
  enqueue(queue, 50);

  queue_node_t *node = dequeue(queue);

  if(node != NULL)
    printf("Dequeued item is %d", node->key);

  return 0;
  
}
