#include <stdlib.h>
#include "stack.h"

int stack_push(Stack_t * stack);
int stack_pop (Stack_t * stack);

int main()
{
    Stack_t stack = {0, 0, 100};

    stack_push(&stack);

    printf();

    stack_pop(&stack);

    return 0;
}

int stack_push(Stack_t * stack)
{
    stack->capacity *= 2;

    stack->data = (stack_elem_t*)calloc(stack->capacity, sizeof(stack_elem_t*));

    return 0;
}

int stack_pop (Stack_t * stack)
{
    stack->data = (stack_elem_t*)realloc(stack->data, 150);

    return 0;
}
