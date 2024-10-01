#include <stdio.h>
#include <stdlib.h>
#include "stack_ctor.h"

Stack_t* stack_ctor()
{
    Stack_t* stack = (Stack_t*)calloc(1, sizeof(Stack_t*));

    return stack;
}

void set_initial_stack_values(Stack_t * stack)
{
    stack->capacity = 100;
    stack->size     = 0  ;
    stack->left_canary_protection  = (stack_elem_t)666;
    stack->right_canary_protection = (stack_elem_t)666;

    stack->data = (stack_elem_t*)calloc(stack->capacity + 2, sizeof(stack_elem_t*));
    stack->data[0]                   = CANARY_PROTECTION;
    stack->data[stack->capacity + 1] = CANARY_PROTECTION;
}
