#include <stdio.h>
#include "communication_with_user.h"
#include "stack_pop.h"
#include "stack_push.h"
#include "myassert.h"

int  add_value();
int  get_user_feedback();
int  ask_about_continuation();
int  add_or_remove_element(Stack_t * stack);
void skip_buffer();

int ui_ask_for_push_or_pop(Stack_t * stack)
{
    printf("Do you want to add or remove an element? ");

    while(ask_about_continuation())
    {
        add_or_remove_element(stack);
    }
    return 0;
}

int add_or_remove_element(Stack_t * stack)
{
    myassert(ASSERT);

    printf("Do you want to put or take elements? ");

    int size = 0;

    if (get_user_feedback())
    {
        stack_elem_t added_value = add_value();

        stack_push(stack, added_value);

        myassert(ASSERT);
    }
    else
    {
        stack_pop(stack);

        myassert(ASSERT);
    }
    return 0;
}

int get_user_feedback()
{
    printf("enter p or t\n");

    int symbol = 0;

    while (symbol != 'p' && symbol != 't')
	{
        symbol = getchar();
	}

    skip_buffer();
    return (symbol == 'p');
}

void skip_buffer()
{
    int symbol = 0;

	do
	{
        symbol = getchar();
	} while (symbol != '\n' && symbol != EOF);
}

int add_value()
{
    stack_elem_t added_value = 0;

    printf("what element do you want to put?\n");

    while((scanf("%d", &added_value)) != 1)
    {
        skip_buffer();
        printf("Input error. Try again\a\n");
    }
    skip_buffer();

    return added_value;
}

int ask_about_continuation()
{
    printf("enter y or n\n");

    int symbol = 0;

    while (symbol != 'y' && symbol != 'n')
	{
        symbol = getchar();
	}

    skip_buffer();
    return (symbol == 'y');
}
