#include <stdio.h>
#include <assert.h>
#include "stack_pop.h"
#include "myassert.h"

stack_elem_t stack_pop (Stack_t * stack)
{
    myassert(ASSERT);

    if (stack->size < (stack->capacity - 50) / 2)
    {
        stack->capacity = (stack->capacity - 50) / 2;

        stack->data = (stack_elem_t*)realloc(stack->data, stack->capacity + 2);
    }
    stack_elem_t removed_value = stack->data[stack->size + 1];

    stack->data[stack->size + 1] = 0;

    stack->size--;

    myassert(ASSERT);

    printf("stack: capacity: %d; size: %d\n", stack->capacity, stack->size);

    return removed_value;
}
