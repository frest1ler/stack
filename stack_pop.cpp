#include <stdio.h>
#include <assert.h>
#include "working_with_data.h"
#include "stack_pop.h"
#include "myassert.h"
#include "dump.h"

stack_elem_t stack_pop (Stack_t * stack)
{
    myassert(ASSERT);

    stack_elem_t return_value = 0;

    if (stack->size == 0) {
        return return_value;
    }

    check_capacity(stack);

    return_value = stack->data[stack->size];

    stack->data[stack->size] = POISON;

    stack->size--; //TODO dtor


    myassert(ASSERT);

    //dump(stack);

    return return_value;
}
