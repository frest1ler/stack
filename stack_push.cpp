#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "working_with_data.h"
#include "myassert.h"
#include "stack_push.h"
#include "dump.h"

int stack_push(Stack_t * stack, stack_elem_t added_value)
{
    verify(ASSERT);

    check_capacity(stack);

    stack->data[stack->size] = added_value;
    stack->size++;

    stack->expected_hash_sum += added_value;

    verify(ASSERT);

    dump(stack);

    return 0;
}
