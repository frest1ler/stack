#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "stack_push.h"
#include "stack_pop.h"
#include "stack_ctor.h"
#include "communication_with_user.h"

int main()
{

    Stack_t stack = *stack_ctor();

    set_initial_stack_values(&stack);

    ui_ask_for_push_or_pop(&stack);

    //stack_push(&stack);

    printf("stack: capacity: %d; size: %d\n", stack.capacity, stack.size);

    //stack_pop(&stack);

    //printf("stack: capacity: %d; size: %d\n", stack.capacity, stack.size);

    return 0;
}
