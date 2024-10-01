#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "stack_push.h"
#include "stack_pop.h"
#include "stack_ctor.h"

void display_arg(int argc, const char *argv[]);

int main(int argc, const char *argv[])
{
    display_arg(argc, argv);

    Stack_t stack = *stack_ctor();

    set_initial_stack_values(&stack);

    stack_push(&stack);

    printf("stack: capacity: %d; size: %d\n", stack.capacity, stack.size);

    stack_pop(&stack);

    printf("stack: capacity: %d; size: %d\n", stack.capacity, stack.size);

    return 0;
}

void display_arg(int argc, const char *argv[])
{
    printf("argc = %d\nargv[%d] :", argc, argc);

    for(int i = 0; i < argc; i++)
    {
        printf(" %s", argv[i]);
    }
    printf("\n");
}

