#include <stdio.h>
#include <assert.h>
#include "myassert.h"
#include "stack_push.h"

int stack_push(Stack_t * stack, stack_elem_t added_value)
{
    myassert(ASSERT);

    if (stack->size >= stack->capacity)
    {
        stack->capacity *= 2;

        stack->data = (stack_elem_t*)realloc(stack->data, (stack->capacity + 2) * sizeof(stack_elem_t));

        myassert(ASSERT);
    }
    stack->data[stack->size + 1] = added_value;

    stack->size++;

    myassert(ASSERT);

    printf("stack: capacity: %d; size: %d\n", stack->capacity, stack->size);

    return 0;
}
