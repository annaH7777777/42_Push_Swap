#include "push_swap.h"

void add(t_data *data, int num)
{
	t_stack_elem	*elem;
	t_stack_elem	**stack;

	stack = &data->a;
	// if(!elem)
	// 	return ;
	if(*stack)
	{
		elem = (t_stack_elem *) malloc (sizeof(t_stack_elem));
		if(!elem)
			terminate("malloc error");
		elem->next = *stack;
		elem->prev = (*stack)->prev;
		(*stack)->prev = elem;
		elem->prev->next = elem;
		elem->number = num;
	}
	else
	{
		*stack = (t_stack_elem *) malloc(sizeof(t_stack_elem));
		if(!(*stack))
			terminate("malloc error");
		(*stack)->next = (*stack);
		(*stack)->prev = (*stack); //CHANGE??????
		(*stack)->number = num;
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
	elem->prev = NULL;

    return (elem);
    
}