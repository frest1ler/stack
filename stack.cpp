#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "stack_push.h"
#include "stack_pop.h"
#include "stack_ctor.h"
#include "stack_destroy.h"

int main()
{
    Stack_t stack = *get_poiter_stack();

    stack_ctor(&stack);

    for(int i = 1; i <= 30; i++)
    {
        stack_push(&stack, i);
        printf("\nstack: capacity: %d; size: %d\n", stack.capacity, stack.size);
        //printf("stack.expected_hash_sum = %lf\nstack.hash_sum = %lf", stack.expected_hash_sum, stack.hash_sum);
    }

    for(int i = 1; i <= 32; i++)
    {
        stack_pop(&stack);
        printf("\nstack: capacity: %d; size: %d\n", stack.capacity, stack.size);
        //printf("stack.expected_hash_sum = %lf\nstack.hash_sum = %lf", stack.expected_hash_sum, stack.hash_sum);
    }

    stack_destroy(&stack);

    return 0;
}

