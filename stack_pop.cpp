#include <stdio.h>
#include <assert.h>
#include "stack_pop.h"
#include "myassert.h"
#include "dump.h"

void reduce_size(Stack_t * stack);

stack_elem_t stack_pop (Stack_t * stack)
{
    myassert(ASSERT);

    stack_elem_t return_value = 0;

    if (stack->size == 0)
    {
        return return_value;
    }

    reduce_size(stack);

    return_value = stack->data[stack->size];

    stack->data[stack->size] = POISON;

    stack->size--;

    myassert(ASSERT);

    //dump(stack);

    return return_value;
}

void reduce_size(Stack_t * stack)
{
    if (stack->size < GIVEN_PART(stack->capacity))
    {
        stack->capacity = GIVEN_PART(stack->capacity);

        stack_elem_t* array = (stack_elem_t*)realloc(stack->data - 1,
                                             stack->capacity * sizeof(stack_elem_t) +
                                             NUM_ARRAY_CANARY * sizeof(double));
        stack->data = array + 1;

        *(stack->data + stack->capacity) = CANARY_PROTECTION;
        *array                           = CANARY_PROTECTION;

        myassert(ASSERT);
    }
}
