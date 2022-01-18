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
	}
	else
	{
	tmp = stack->head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = elem;
	elem->next = NULL;
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