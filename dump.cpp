#include <stdio.h>
#include "dump.h"
#include "myassert.h"

int dump(Stack_t * stack)
{
    myassert(ASSERT);

    for(int j = 0; j < stack->capacity + 2; j++)
    {
        printf("%0.lf ", stack->data[j]);
    }

    printf("\nstack: capacity: %d; size: %d\n", stack->capacity, stack->size);

    myassert(ASSERT);

    return 0;
}
