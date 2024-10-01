#include <stdio.h>
#include <assert.h>
#include "stack_pop.h"
#include "myassert.h"

int stack_pop (Stack_t * stack)
{
    MYASSERT(stack)

    stack->capacity = (stack->capacity - 50) / 2;

    stack->data = (stack_elem_t*)realloc(stack->data, stack->capacity + 2);

    stack->data[0]                   = CANARY_PROTECTION;
    stack->data[stack->capacity + 1] = CANARY_PROTECTION;

    MYASSERT(stack)

    return 0;
}
