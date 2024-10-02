#include <stdio.h>
#include <assert.h>
#include "myassert.h"

int myassert(Stack_t * stack, const char* file, int line)
{
    int error = stack_error(stack);
    if (error & 1)
    {
        printf("file: %s; line: %d\n"
               "stack->left_canary_protection != CANARY_PROTECTION\n", file, line); //TODO прекратить хуйню
    }
    if (error & 2)
    {
        printf("file: %s; line: %d\nstack->data == NULL\n", file, line);
    }
    if (error & 4)
    {
        printf("file: %s; line: %d\nstack->capacity == 0\n", file, line);
    }
    if (error & 8)
    {
        printf("file: %s; line: %d\n"
               "stack->right_canary_protection != CANARY_PROTECTION\n", file, line);
    }
    if (error & 16)
    {
        printf("file: %s; line: %d\n"
               "stack->size < 0\n", file, line);
    }
    if (error & 32)
    {
        printf("file: %s; line: %d\n"
               "stack->capacity <= 0\n", file, line);
    }
    if (error & 64)
    {
        printf("file: %s; line: %d\n"
               "stack->left_canary_protection != CANARY_PROTECTION\n", file, line);
    }
    if (error & 128)
    {
        printf("file: %s; line: %d\n"
               "stack->right_canary_protection != CANARY_PROTECTION\n", file, line);
    }
    if (error & 256)
    {
        printf("file: %s; line: %d\n"
               "stack->data[0] != CANARY_PROTECTION\n", file, line);
    }
    if (error & 512)
    {
        printf("file: %s; line: %d\n"
               "stack->data[stack->capacity + 1] != CANARY_PROTECTION\n", file, line);
    }
    for(int i = 1; stack->size + i < stack->capacity + 1; i++)
    {
        if (stack->data[stack->size + i] != POISON)
        {
            printf("file: %s; line: %d\n"
                   "stack->data[%d] != POISON\n"
                   "stack->data[%d] = %lf\n", file, line, stack->size + i, stack->data[stack->size + i]);
        }
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
    if (stack->size < 0)
    {
        error +=16;
    }
    if (stack->capacity <= 0)
    {
        error +=32;
    }
    if (stack->left_canary_protection != CANARY_PROTECTION)
    {
        error +=64;
    }
    if (stack->right_canary_protection != CANARY_PROTECTION)
    {
        error +=128;
    }
    if (stack->data[0] != CANARY_PROTECTION)
    {
        error +=256;
    }
    if (stack->data[stack->capacity + 1] != CANARY_PROTECTION)
    {
        error +=512;
    }
    return error;
}
