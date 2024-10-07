#ifndef STACK_H
#define STACK_H

#define GIVEN_PART(x) ((x)-50)/2

typedef double stack_elem_t;

#define CANARY_SPECIFIER "%lf"
#define STACK_SPECIFIER  "%lf"

struct Stack_t
{
    double        left_canary_protection ; //TODO отключаемы канарейки
    stack_elem_t* data                   ;
    int           size                   ;
    int           capacity               ;
    unsigned long hash_sum               ;
    unsigned long etalon_hash_sum        ;
    double        right_canary_protection;
};  //TODO  отключаемые канарейки, dump, отладочную инфу, хэш

const double        CANARY_PROTECTION_1  =  987654321;
const double        CANARY_PROTECTION_2  = -987654321;
const double        CANARY_PROTECTION_3  =  123456789;
const double        CANARY_PROTECTION_4  = -123456789;
const stack_elem_t  POISON               = -333      ; //TODO NAN
const unsigned long INITIAL_HASH_SUM     =  5381     ;
const int           INITIAL_CAPACITY     =  10       ; //TODO size_t
const int           INITIAL_SIZE         =  0        ;
const int           NUM_CANARY_ARRAY     =  2        ;
const int           CAPACITY_GROWTH_RATE =  2        ;

#endif /*STACK_H*/
