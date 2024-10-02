#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "stack_push.h"
#include "stack_pop.h"
#include "stack_ctor.h"

int main()
{

    Stack_t stack = *stack_ctor();

    set_initial_stack_values(&stack);

    for(int i = 1; i <= 30; i++)
    {
        stack_push(&stack, 1);
    }

    for(int i = 1; i <= 25; i++)
    {
        stack_pop(&stack);
    }

    return 0;
}
