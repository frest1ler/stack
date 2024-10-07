#include <stdio.h>
#include "dump.h"

int dump(Stack_t * stack)
{
    printf("stack->capacity = %d\nstack->size = %d\n"
           "stack->hash_sum = " STACK_SPECIFIER"\nstack->expected_hash_sum = " STACK_SPECIFIER"\n"
           "stack->left_canary_protection = " CANARY_SPECIFIER" \n"
           "stack->right_canary_protection = " CANARY_SPECIFIER" \n"
           "*(stack->data - 1) = " CANARY_SPECIFIER"\n*(stack->data + stack->capacity) = " CANARY_SPECIFIER"\n\n"
           , stack->capacity, stack->size, stack->hash_sum, stack->expected_hash_sum,
           stack->left_canary_protection, stack->right_canary_protection,
           *(stack->data - 1), *(stack->data + stack->capacity));

    printf("" CANARY_SPECIFIER"(%d) ", *(stack->data - 1), 0);

    for(int j = 0; j < stack->capacity; j++)
    {
        printf("" STACK_SPECIFIER"(%d) ", *(stack->data + j), j + 1);
    }

    printf("" CANARY_SPECIFIER"(%d) ", *(stack->data + stack->capacity), stack->capacity);

    return 0;
}
