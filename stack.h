#ifndef STACK_H
#define STACK_H

typedef double stack_elem_t;

struct Stack_t
{
    stack_elem_t  left_canary_protection ;
    stack_elem_t* data                   ;
    int           size                   ;
    int           capacity               ;
    stack_elem_t  right_canary_protection;
};

const stack_elem_t CANARY_PROTECTION =  666;
const stack_elem_t POISON            = -333;
#endif /*STACK_H*/
