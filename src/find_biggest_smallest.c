#include "push_swap.h"

void find_smallest(t_stack *stack)
{
	t_stack_elem *tmp;
	t_stack_elem *end;

	tmp = stack->head;
	end = tmp->prev;
	stack->smallest = stack->biggest;
	while (1)
	{
		if(tmp->number < stack->smallest)
			stack->smallest = tmp->number;
		if(tmp == end)
			break;
		tmp = tmp->next;
	}
}