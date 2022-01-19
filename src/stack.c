#include "push_swap.h"

void add(t_data *data, t_stack_elem *elem)
{
	t_stack_elem	*tmp;
	t_stack_elem	*stack;

	stack = data->a;
	if(!stack || !elem)
		return ;
	if(!stack)
	{
		stack = elem;
		stack->next = NULL;
		stack->prev = NULL;
	}
	else
	{
		tmp = stack;
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
	data->size++;
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