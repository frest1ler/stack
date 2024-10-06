#include <stdlib.h>
#include "stack_destroy.h"

void stack_destroy(stack_elem_t* data)
{
    if (data != 0)
    {
        free(data);
    }

}
