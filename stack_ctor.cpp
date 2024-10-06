#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack_ctor.h"
#include "myassert.h"

Stack_t* get_poiter_stack()
{
    Stack_t* stack = (Stack_t*)calloc(1, sizeof(Stack_t*));

    return stack;
}

void stack_ctor(Stack_t * stack)
{
    assert(stack);

    stack->capacity                = INITIAL_CAPACITY ;
    stack->size                    = INITIAL_SIZE     ;
    stack->left_canary_protection  = CANARY_PROTECTION; //TODO сделать разные значения
    stack->right_canary_protection = CANARY_PROTECTION;

    stack_elem_t* array = (stack_elem_t*)calloc(stack->capacity + NUM_ARRAY_CANARY, sizeof(stack_elem_t*)); //TODO

    *array                         = CANARY_PROTECTION;
    *(array + stack->capacity + 1) = CANARY_PROTECTION;

    stack->data = array + 1;

    for(int i = 0; i < stack->capacity; i++) //TODO Func
    {
        stack->data[i] = POISON;
    }

    myassert(ASSERT); //TODO myassert is macro define not func
}
