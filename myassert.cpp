#include <stdio.h>
#include <assert.h>
#include "myassert.h"
#include "stack_destroy.h"
#include "dump.h"

int  stack_error(Stack_t * stack);
void display_error(Stack_t * stack, int error, const char* file, int line);

int verify(Stack_t * stack, const char* file, int line)
{
    int error = stack_error(stack);

    if (error == 0)
    {
        return 0;
    }

    display_error(stack, error, file, line);

    stack_destroy(stack);

    return 0;
}

int stack_error(Stack_t * stack) //TODO rename
{
    assert(stack); //TODO отключаемые assert-ы, условная компиляция

    int error = 0;

    #define CHECK_ERROR_(error_value, error_if)      \
    do                                               \
    {                                                \
        if (error_if)                                \
        {                                            \
            error += error_value;                    \
        }                                            \
    } while(0)

    CHECK_ERROR_(INCORRECT_VALUE_LEFT_CANARY_STRUCT, stack->left_canary_protection != CANARY_PROTECTION_1);
    CHECK_ERROR_(NULL_POINTER_DATA, stack->data == NULL);
    CHECK_ERROR_(NEGATIVE_CAPACITY, stack->capacity <= 0);
    CHECK_ERROR_(INCORRECT_VALUE_RIGHT_CANARY_STRUCT, stack->right_canary_protection != CANARY_PROTECTION_2);
    CHECK_ERROR_(NEGATIVE_SIZE, stack->size < 0);
    CHECK_ERROR_(INCORRECT_VALUE_LEFT_CANARY_ARRAY, *(stack->data - 1) != CANARY_PROTECTION_3);
    CHECK_ERROR_(INCORRECT_VALUE_RIGHT_CANARY_ARRAY, *(stack->data + stack->capacity) != CANARY_PROTECTION_4);

    stack->hash_sum = 0;

    for(int i = 1; i <= stack->size; i++)
    {
        stack->hash_sum += stack->data[i - 1];
    }

    CHECK_ERROR_(HASH_AMOUNT_MISMATCH, stack->hash_sum != stack->expected_hash_sum);

    #undef CHECK_ERROR_

    return error;
}

void display_error(Stack_t * stack, int error, const char* file, int line)
{
    assert(error);

    printf("file: %s; line: %d\n", file, line);

    #define OUTPUT_ERROR_(error_value, output_error) \
    do                                               \
    {                                                \
        if (error & error_value)                     \
        {                                            \
            printf(output_error);                    \
        }                                            \
    } while(0)

    OUTPUT_ERROR_(INCORRECT_VALUE_LEFT_CANARY_STRUCT, "stack->left_canary_protection != CANARY_PROTECTION_1\n");
    OUTPUT_ERROR_(NULL_POINTER_DATA, "stack->data == NULL\n");
    OUTPUT_ERROR_(NEGATIVE_CAPACITY, "stack->capacity <= 0\n");
    OUTPUT_ERROR_(INCORRECT_VALUE_RIGHT_CANARY_STRUCT, "stack->right_canary_protection != CANARY_PROTECTION_2\n");
    OUTPUT_ERROR_(NEGATIVE_SIZE, "stack->size < 0\n");
    OUTPUT_ERROR_(INCORRECT_VALUE_LEFT_CANARY_ARRAY, "*(stack->data - 1) != CANARY_PROTECTION_3\n");
    OUTPUT_ERROR_(INCORRECT_VALUE_RIGHT_CANARY_ARRAY, "stack->data[stack->capacity + 1] != CANARY_PROTECTION_4\n*");
    OUTPUT_ERROR_(HASH_AMOUNT_MISMATCH, "stack->hash_sum != stack->expected_hash_sum\n");

    for(int i = 1; stack->size + i < stack->capacity; i++)
    {
        if (stack->data[stack->size + i] != POISON)
        {
            printf("file: %s; line: %d\n"
                   "stack->data[%d] != POISON\n"
                   "stack->data[%d] = %lf\n",
                   file, line, stack->size + i, stack->size + i, stack->data[stack->size + i]);
        }
    }

    dump(stack);

    #undef OUTPUT_ERROR_
}
