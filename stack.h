#ifndef STACK_H
#define STACK_H

#define GIVEN_PART(x) ((x)-50)/2

typedef double stack_elem_t; //TODO спецификатор ввывода через дефайн

//#define CANARY_SPECIFIER %lf
//#define STACK_SPECIFIER  %lf

struct Stack_t
{
    stack_elem_t  left_canary_protection ; //TODO отключаемы канарейки
    stack_elem_t* data                   ;
    int           size                   ;
    int           capacity               ;
    stack_elem_t  hash_sum               ;
    stack_elem_t  expected_hash_sum      ;
    stack_elem_t  right_canary_protection;
};  //TODO  отключаемые канарейки, dump, отладочную инфу, хэш

const stack_elem_t CANARY_PROTECTION_1  =  987654321;
const stack_elem_t CANARY_PROTECTION_2  = -987654321;
const stack_elem_t CANARY_PROTECTION_3  =  123456789;
const stack_elem_t CANARY_PROTECTION_4  = -123456789;
const stack_elem_t POISON               = -333      ; //TODO NAN
const stack_elem_t INITIAL_HASH_SUM     =  0        ;
const int          INITIAL_CAPACITY     =  10       ; //TODO size_t
const int          INITIAL_SIZE         =  0        ;
const int          NUM_CANARY_ARRAY     =  2        ;
const int          CAPACITY_GROWTH_RATE =  2        ;

#endif /*STACK_H*/
