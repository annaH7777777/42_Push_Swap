#include "push_swap.h"

void add(t_stack *stack, t_stack_elem *elem)
{
	t_stack_elem	*tail;

	if(!stack || !elem)
		return ;
	if(!stack->head)
	{
		stack->head = elem;
		stack->head->next = stack->head;
		stack->head->previous = stack->head;
	}
	else
		{
			tail = stack->head->previous;
			elem->previous = tail;
			tail->next = elem;
			elem->next = stack->head;
			stack->head->previous = elem;
		}
		stack->size++;
}

t_stack_elem *create_elem(int number)
{
    t_stack_elem *elem;

    elem = malloc(sizeof(t_stack_elem));
    if(elem == NULL)
        terminate("malloc error");
    elem->number = number;
    elem->index = -1;
    elem->next = NULL;
    elem->previous = NULL;
    elem->keep_in_stack = false;

    return (elem);
    
}