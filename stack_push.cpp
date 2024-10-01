#include <stdio.h>
#include <assert.h>
#include "myassert.h"
#include "stack_push.h"

int stack_push(Stack_t * stack)
{
    assert(stack);

    myassert(stack);

    stack->capacity *= 2;

    stack->data = (stack_elem_t*)realloc(stack->data, stack->capacity + 2);

    stack->data[0]                   = CANARY_PROTECTION;
    stack->data[stack->capacity + 1] = CANARY_PROTECTION;

    myassert(stack);

    return 0;
}
