//========================================================================
// Binary Heap
//========================================================================

#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------
// Globals: *
//------------------------------------------------------------------------

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define MIN_HEAP_SIZE (10)
#define MIN_DATA (-32767)

//------------------------------------------------------------------------
// Type: element_t
//------------------------------------------------------------------------
typedef int element_t;

//------------------------------------------------------------------------
// Type: heap_t
//------------------------------------------------------------------------
typedef struct heap {
  int capacity;
  int size;
  element_t *elements;
} heap_t;

//------------------------------------------------------------------------
// Interfaces: *
//------------------------------------------------------------------------
heap_t *initialize(int max_elements);
void destroy(heap_t *heap);
void make_empty(heap_t *heap);
void insert(element_t element, heap_t *heap);
element_t find_min(heap_t *heap);
int is_empty(heap_t *heap);
int is_full(heap_t *heap);
void print_heap(heap_t *heap);

//------------------------------------------------------------------------
// Function: initialize
//------------------------------------------------------------------------
heap_t *initialize(int max_elements) {

  if(max_elements < MIN_HEAP_SIZE) {
    printf("Priority queue size is too small!");
    exit(EXIT_FAILURE);
  }

  heap_t *h = (heap_t*) malloc(sizeof(heap_t));

  if(h == NULL) {
    printf("Out of space!");
    exit(EXIT_FAILURE);
  }

  h->elements = malloc((max_elements + 1) * sizeof(element_t));

  if(h->elements == NULL) {
    printf("Out of space!");
    exit(EXIT_FAILURE);
  }
 
  h->capacity = max_elements;
  h->size = 0;
  h->elements[0] = MIN_DATA;
 
  return h;
}

//------------------------------------------------------------------------
// Function: make_empty
//------------------------------------------------------------------------
void make_empty(heap_t *h) {
  h->size = 0;
}

//------------------------------------------------------------------------
// Functio: insert
//------------------------------------------------------------------------
void insert(element_t x, heap_t *h) {
  int i;

  if(is_full(h)) {
    printf("Heap is full!");
    exit(EXIT_FAILURE);
  }

  for(i = ++h->size; h->elements[i/2] > x; i /= 2)
    h->elements[i] = h->elements[i/2];

  h->elements[i] = x;
  printf("%d was inserted\n", x);
}

//------------------------------------------------------------------------
// Function: find_min
//------------------------------------------------------------------------
element_t find_min(heap_t *h) {
  if(!is_empty(h))
    return h->elements[1];

  printf("Heap is empty!");
  return h->elements[0];
}

//------------------------------------------------------------------------
// Function: is_empty
//------------------------------------------------------------------------
int is_empty(heap_t *h) {
  return h->size == 0;
}

//------------------------------------------------------------------------
// Function: is_full
//------------------------------------------------------------------------
int is_full(heap_t *h) {
  return h->size == h->capacity;
}

//------------------------------------------------------------------------
// Function: destroy
//------------------------------------------------------------------------
void destroy(heap_t *h) {
  free(h->elements);
  free(h);
}

//------------------------------------------------------------------------
// Function: print_heap
//------------------------------------------------------------------------
void print_heap(heap_t *h) {
  element_t min = find_min(h);
  printf("Min element is %d\n", min);
}

//------------------------------------------------------------------------
// Function: main
//------------------------------------------------------------------------
int main() {

  int max_size = 1000;
  heap_t *h = initialize(max_size);

  insert(50, h);
  insert(20, h);
  insert(40, h);
  insert(60, h);

  print_heap(h);

  insert(10, h);
  insert(80, h);
  insert(90, h);

  print_heap(h);
  
  printf("Done\n");
  return 0;
}
