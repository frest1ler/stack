#include <stdio.h>
#include <assert.h>
#include "myassert.h"

int myassert(Stack_t * stack, const char* file, int line)
{
    int error = stack_error(stack);
    if (error & 1)
    {
        printf("file: %s; line: %d\n"
               "stack->left_canary_protection != CANARY_PROTECTION\n", file, line);
    }
    if (error & 10)
    {
        printf("file: %s; line: %d\nstack->data == NULL\n", file, line);
    }
    if (error & 100)
    {
        printf("file: %s; line: %d\nstack->capacity == 0\n", file, line);
    }
    if (error & 1000)
    {
        printf("file: %s; line: %d\n"
               "stack->right_canary_protection != CANARY_PROTECTION\n", file, line);
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
