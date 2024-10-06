#include <stdlib.h>
#include "working_with_data.h"
#include "stack_destroy.h"
#include "myassert.h"

void pour_poison_into_empty(stack_elem_t* data, int size, int capacity);

void check_capacity(Stack_t * stack)
{
    int fill_poison = 0;

    if (stack->size >= stack->capacity)
    {
        stack->capacity *= CAPACITY_GROWTH_RATE;

        fill_poison++;
    }
    else if (stack->size < GIVEN_PART(stack->capacity))
    {
        stack->capacity = GIVEN_PART(stack->capacity);
    }
    else
    {
        return;
    }

    stack_elem_t* array = (stack_elem_t*)realloc(stack->data - 1,
                                                 stack->capacity * sizeof(stack_elem_t) +
                                                 NUM_ARRAY_CANARY * sizeof(double));
    stack_destroy(stack->data - 1);

    stack->data = array + 1;

    *(stack->data + stack->capacity) = CANARY_PROTECTION;

    if (fill_poison)
    {
        pour_poison_into_empty(stack->data, stack->size, stack->capacity);
    }

    myassert(ASSERT);
}

void pour_poison_into_empty(stack_elem_t* data, int size, int capacity)
{
    for(int i = 0; size + i < capacity; i++)
    {
        data[size + i] = POISON;
    }
}
