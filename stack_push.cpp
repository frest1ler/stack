#include <stdio.h>
#include <assert.h>
#include "myassert.h"
#include "stack_push.h"

int stack_push(Stack_t * stack)
{
    MYASSERT(stack)

    MYASSERT(stack)

    stack->capacity *= 2;

    stack->data = (stack_elem_t*)realloc(stack->data, stack->capacity + 2);

    stack->data[0]                   = CANARY_PROTECTION;
    stack->data[stack->capacity + 1] = CANARY_PROTECTION;

    MYASSERT(stack)

    return 0;
}
