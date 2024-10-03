#ifndef MYASSERT_H
#define MYASSERT_H

#include "stack.h"

#define ASSERT stack,__FILE__,__LINE__ //TODO rename

#define OUTPUT_LEFT_CANARY_STRUCT_NOT_EQUAL_TO_STANDARD                                         \
    if (error & 1)                                                                              \
    {                                                                                           \
        printf("stack->left_canary_protection != CANARY_PROTECTION\n");                         \
    }
#define OUTPUT_STACK_DATA_IS_NULL                                                               \
    if (error & 2)                                                                              \
    {                                                                                           \
        printf("stack->data == NULL\n");                                                        \
    }
#define OUTPUT_NEGATIVE_CAPACITY                                                                \
    if (error & 4)                                                                              \
    {                                                                                           \
        printf("stack->capacity <= 0\n");                                                       \
    }
#define OUTPUT_RIGHT_CANARY_STRUCT_NOT_EQUAL_TO_STANDART                                        \
    if (error & 8)                                                                              \
    {                                                                                           \
        printf("stack->right_canary_protection != CANARY_PROTECTION\n");                        \
    }
#define OUTPUT_NEGATIVE_SIZE                                                                    \
    if (error & 16)                                                                             \
    {                                                                                           \
        printf("stack->size < 0\n");                                                            \
    }
#define OUTPUT_LEFT_CANARY_DATA_NOT_EQUAL_TO_STANDARD                                           \
    if (error & 32)                                                                             \
    {                                                                                           \
        printf("*(stack->data - 1) != CANARY_PROTECTION\n");                                    \
    }
#define OUTPUT_RIGHT_CANARY_DATA_NOT_EQUAL_TO_STANDARD                                          \
    if (error & 64)                                                                             \
    {                                                                                           \
        printf("stack->data[stack->capacity + 1] != CANARY_PROTECTION\n"                        \
               "*(stack->data +%d) = %lf\n", stack->capacity, stack->data[stack->capacity]);    \
    }
#define OUTPUT_EMPTY_ELEMENT_NOT_POISONOUS                                                      \
    for(int i = 1; stack->size + i < stack->capacity; i++)                                      \
    {                                                                                           \
        if (stack->data[stack->size + i] != POISON)                                             \
        {                                                                                       \
            printf("file: %s; line: %d\n"                                                       \
                   "stack->data[%d] != POISON\n"                                                \
                   "stack->data[%d] = %lf\n",                                                   \
                   file, line, stack->size + i, stack->size + i, stack->data[stack->size + i]); \
        }                                                                                       \
    }
#define LEFT_CANARY_STRUCT_NOT_EQUAL_TO_STANDARD                                                \
    if (stack->left_canary_protection != CANARY_PROTECTION)                                     \
    {                                                                                           \
        error += 1;                                                                             \
    }
#define STACK_DATA_IS_NULL                                                                      \
    if (stack->data == NULL)                                                                    \
    {                                                                                           \
        error += 2;                                                                             \
    }
#define NEGATIVE_CAPACITY                                                                       \
    if (stack->capacity <= 0)                                                                   \
    {                                                                                           \
        error += 4;                                                                             \
    }
#define RIGHT_CANARY_STRUCT_NOT_EQUAL_TO_STANDART                                               \
    if (stack->right_canary_protection != CANARY_PROTECTION)                                    \
    {                                                                                           \
        error +=8;                                                                              \
    }
#define NEGATIVE_SIZE                                                                           \
    if (stack->size < 0)                                                                        \
    {                                                                                           \
        error +=16;                                                                             \
    }
#define LEFT_CANARY_DATA_NOT_EQUAL_TO_STANDARD                                                  \
    if (*(stack->data - 1) != CANARY_PROTECTION)                                                \
    {                                                                                           \
        error +=32;                                                                             \
    }
#define RIGHT_CANARY_DATA_NOT_EQUAL_TO_STANDARD                                                 \
    if (*(stack->data + stack->capacity) != CANARY_PROTECTION)                                  \
    {                                                                                           \
        error +=64;                                                                             \
    }

int myassert(Stack_t * stack, const char* file, int line);
int stack_error(Stack_t * stack);

#endif /*MYASSERT_H*/
