#include <stdio.h>
#include <assert.h>
#include "myassert.h"
#include "stack_push.h"
#include "dump.h"

void increase_size(Stack_t * stack);

int stack_push(Stack_t * stack, stack_elem_t added_value)
{
    myassert(ASSERT);

    if (stack->size >= stack->capacity)
    {
        increase_size(stack);
    }

    stack->data[stack->size] = added_value;
    stack->size++;

    myassert(ASSERT);

    //dump(stack);

    return 0;
}

void increase_size(Stack_t * stack)
{
    stack->capacity *= CAPACITY_GROWTH_RATE;

    stack_elem_t* array = (stack_elem_t*)realloc(stack->data - 1,
                                                 stack->capacity * sizeof(stack_elem_t) +
                                                 NUM_ARRAY_CANARY * sizeof(double));
    stack->data = array + 1;
    for(int i = 0; stack->size + i < stack->capacity; i++) //TODO memset or func
    {
        stack->data[stack->size + i] = POISON;
    }
    *(stack->data + stack->capacity) = CANARY_PROTECTION;

    myassert(ASSERT);
}
