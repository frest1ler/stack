#include <stdio.h>
#include <assert.h>
#include "myassert.h"
#include "stack_push.h"
#include "dump.h"

int stack_push(Stack_t * stack, stack_elem_t added_value)
{
    myassert(ASSERT);

    if (stack->size >= stack->capacity)
    {
        stack->capacity *= 2;

        stack->data = (stack_elem_t*)realloc(stack->data, (stack->capacity + 2) * sizeof(stack_elem_t));

        for(int i = 1; stack->size + i < stack->capacity + 1; i++)
        {
            stack->data[stack->size + i] = POISON;
        }
        stack->data[stack->capacity + 1] = CANARY_PROTECTION;

        myassert(ASSERT);
    }
    stack->data[stack->size + 1] = added_value;

    stack->size++;

    myassert(ASSERT);

    //dump(stack);

    return 0;
}
