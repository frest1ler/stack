#include <stdio.h>
#include <assert.h>
#include "stack_pop.h"
#include "myassert.h"
#include "dump.h"

stack_elem_t stack_pop (Stack_t * stack)
{

    myassert(ASSERT);

    stack_elem_t removed_value = 0;

    if (stack->size > 0)
    {
        if (stack->size < (stack->capacity - 50) / 2)
        {
            stack->capacity = (stack->capacity - 50) / 2;

            stack->data = (stack_elem_t*)realloc(stack->data, (stack->capacity + 2) * sizeof(stack_elem_t));

            stack->data[stack->capacity + 1] = CANARY_PROTECTION;
        }
        removed_value = stack->data[stack->size];

        stack->data[stack->size] = POISON;

        stack->size--;

        myassert(ASSERT);

        //dump(stack);
    }
    return removed_value;
}
