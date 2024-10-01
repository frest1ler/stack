#include <stdio.h>
#include <assert.h>
#include "myassert.h"

int myassert(Stack_t * stack)
{
    int error = stack_error(stack);
    if (error & 1)
    {
        printf("stack->left_canary_protection != CANARY_PROTECTION\n");
    }
    if (error & 10)
    {
        printf("stack->data == NULL\n");
    }
    if (error & 100)
    {
        printf("stack->capacity == 0\n");
    }
    if (error & 1000)
    {
        printf("stack->right_canary_protection != CANARY_PROTECTION\n");
    }
    return 0;
}

int stack_error(Stack_t * stack)
{
    assert(stack);

    int error = 0;

    if (stack->left_canary_protection != CANARY_PROTECTION)
    {
        error += 1;
    }
    if (stack->data == NULL)
    {
        error += 2;
    }
    if (stack->capacity == 0)
    {
        error += 4;
    }
    if (stack->right_canary_protection != CANARY_PROTECTION)
    {
        error +=8;
    }
    return error;
}
