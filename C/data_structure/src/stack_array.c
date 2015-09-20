//========================================================================
// Stack Array
//========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//------------------------------------------------------------------------
// Types: bool
//------------------------------------------------------------------------
typedef enum bool {
  false = 0,
  true = 1
} bool;

//------------------------------------------------------------------------
// Types: stack_t
//------------------------------------------------------------------------
typedef struct stack {
  int top;
  unsigned capacity;
  int *array;
} stack_t;

//------------------------------------------------------------------------
// Function: create_stack
//------------------------------------------------------------------------
stack_t *create_stack(unsigned capacity) {
  stack_t *stack = (stack_t*) malloc(sizeof(stack_t));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (int*) malloc(stack->capacity * sizeof(int));
  return stack;
}

//------------------------------------------------------------------------
// Function: is_full
//------------------------------------------------------------------------
int is_full(stack_t *stack) {
  return stack->top == stack->capacity - 1;
}

//------------------------------------------------------------------------
// Function: is_empty
//------------------------------------------------------------------------
int is_empty(stack_t *stack) {
  return stack->top == -1;
}

//------------------------------------------------------------------------
// Function: push
//------------------------------------------------------------------------
void push(stack_t *stack, int item) {
  if(is_full(stack))
    return;

  stack->array[++stack->top] = item;
  printf("%d pushed to stack\n", item);
}

//------------------------------------------------------------------------
// Function: pop
//------------------------------------------------------------------------
int pop(stack_t *stack) {
  if(is_empty(stack))
    return INT_MIN;

  return stack->array[stack->top--];
}

//------------------------------------------------------------------------
// Function: peek
//------------------------------------------------------------------------
int peek(stack_t *stack) {
  if(is_empty(stack))
    return INT_MIN;

  return stack->array[stack->top];
}

//------------------------------------------------------------------------
// Function: main
//------------------------------------------------------------------------
int main() {

  stack_t *stack = create_stack(100);

  push(stack, 10);
  push(stack, 20);
  push(stack, 30);

  printf("%d poped from stack\n", pop(stack));
  printf("Top item is %d\n", peek(stack));
  
}
