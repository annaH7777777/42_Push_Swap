#include "push_swap.h"

void add(t_stack *stack, t_stack_elem *elem)
{
	t_stack_elem	*tmp;

	if(!stack || !elem)
		return ;
	if(!stack->head)
	{
		stack->head = elem;
		stack->head->next = NULL;
		stack->head->prev = NULL;
	}
	else
	{
		tmp = stack->head;
		tmp->prev = elem;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		elem->prev = tmp;
		tmp->next = elem;
		tmp->next->next = NULL;
		// {
		// 	stack->head = elem;
		// 	stack->head->next = tmp;
		// }
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
    //elem->index = -1;
    elem->next = NULL;
    //elem->keep_in_stack = false;

    return (elem);
    
}