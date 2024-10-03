#include <stdio.h>
#include <assert.h>
#include "myassert.h"
#include "dump.h"

int  stack_error(Stack_t * stack);
void display_error(Stack_t * stack, int error, const char* file, int line);

int myassert(Stack_t * stack, const char* file, int line)
{
    int error = stack_error(stack);

    if (error == 0)
    {
        return 0;
    }

    display_error(stack, error, file, line);

    return 0;
}

int stack_error(Stack_t * stack) //TODO rename
{
    assert(stack); //TODO отключаемые assert-ы, условная компиляция

    int error = 0;

    LEFT_CANARY_STRUCT_NOT_EQUAL_TO_STANDARD

    STACK_DATA_IS_NULL

    NEGATIVE_CAPACITY

    RIGHT_CANARY_STRUCT_NOT_EQUAL_TO_STANDART

    NEGATIVE_SIZE

    LEFT_CANARY_DATA_NOT_EQUAL_TO_STANDARD

    RIGHT_CANARY_DATA_NOT_EQUAL_TO_STANDARD

    return error;
}

void display_error(Stack_t * stack, int error, const char* file, int line)
{
    assert(error);

    printf("file: %s; line: %d\n", file, line);

    OUTPUT_LEFT_CANARY_STRUCT_NOT_EQUAL_TO_STANDARD

    OUTPUT_STACK_DATA_IS_NULL

    OUTPUT_NEGATIVE_CAPACITY

    OUTPUT_RIGHT_CANARY_STRUCT_NOT_EQUAL_TO_STANDART

    OUTPUT_NEGATIVE_SIZE

    OUTPUT_LEFT_CANARY_DATA_NOT_EQUAL_TO_STANDARD

    OUTPUT_RIGHT_CANARY_DATA_NOT_EQUAL_TO_STANDARD

    OUTPUT_EMPTY_ELEMENT_NOT_POISONOUS

    dump(stack);
}
