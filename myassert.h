#ifndef MYASSERT_H
#define MYASSERT_H

#include "stack.h"

int myassert(Stack_t * stack);
int stack_error(Stack_t * stack);

#define ASSERT __FILE__ __LINE__

#endif /*MYASSERT_H*/
