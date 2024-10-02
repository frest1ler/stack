#ifndef MYASSERT_H
#define MYASSERT_H

#include "stack.h"

#define ASSERT stack,__FILE__,__LINE__

int myassert(Stack_t * stack, const char* file, int line);
int stack_error(Stack_t * stack);

#endif /*MYASSERT_H*/
