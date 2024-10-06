#include <stdio.h>
#include "dump.h"

int dump(Stack_t * stack)
{
    printf("stack->capacity = %d\nstack->size = %d\n"
           "stack->hash_sum = %lf\nstack->expected_hash_sum = %lf\n"
           "stack->left_canary_protection = %lf\n"
           "stack->right_canary_protection = %lf\n"
           "*(stack->data - 1) = %lf\n*(stack->data + stack->capacity) = %lf\n\n"
           , stack->capacity, stack->size, stack->hash_sum, stack->expected_hash_sum,
           stack->left_canary_protection, stack->right_canary_protection,
           *(stack->data - 1), *(stack->data + stack->capacity));

    for(int j = -1; j <= stack->capacity; j++)
    {
        printf("%0.lf(%d) ", *(stack->data + j), j + 2);
    }

    return 0;
}
