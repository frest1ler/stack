#ifndef STACK_H
#define STACK_H

typedef double stack_elem_t;

struct Stack_t
{
    stack_elem_t* data;
    int size;
    int capacity;
};

#endif /*STACK_H*/
