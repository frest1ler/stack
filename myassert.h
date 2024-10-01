#ifndef MYASSERT_H
#define MYASSERT_H

#include "stack.h"

#define MYASSERT(stack) myassert(stack);

int myassert(Stack_t * stack);
int stack_error(Stack_t * stack);

#endif /*MYASSERT_H*/
