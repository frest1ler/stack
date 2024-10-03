#include <stdio.h>
#include "dump.h"
#include "myassert.h"

int dump(Stack_t * stack)
{
    for(int j = -1; j <= stack->capacity; j++)
    {
        printf("%0.lf(%d) ", *(stack->data + j), j + 2);
    }

    printf("\nstack: capacity: %d; size: %d\n", stack->capacity, stack->size);

    return 0;
}
