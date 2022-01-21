#include "push_swap.h"

void find_smallest(t_data *data, char stack_name)
{
	t_stack_elem *tmp;
	t_stack_elem *end;
	t_stack_elem *stack;

	stack = NULL;
	if(stack_name == 'a')
		stack = data->a;
	else if(stack_name == 'b')
		stack = data->b;
	else
		terminate("wrong stack");

	tmp = stack;
	end = tmp->prev;
	data->smallest = tmp->number;
	while (1)
	{
		if(tmp->number < data->smallest)
			data->smallest = tmp->number;
		if(tmp == end)
		 	break;
		tmp = tmp->next;
	}
}

void find_biggest(t_data *data, char stack_name)
{
	t_stack_elem *tmp;
	t_stack_elem *end;
	t_stack_elem *stack;

	//stack = NULL;
	if(stack_name == 'a')
		stack = data->a;
	else //if(stack_name == 'b')
		stack = data->b;
	// else
	// 	terminate("wrong stack");

	tmp = stack;
	if(stack_name == 'a')
		end = data->a->prev;
	else
		end = data->b->prev;
	data->biggest = tmp->number;
	while (1)
	{
		if(tmp->number > data->biggest)
			data->biggest = tmp->number;
		if(tmp == end)
		{
			//printf("\n%d %d tmp end\n", data->a->number, data->b->number);
			break ;
		}
		//printf("\nbla\n");
		tmp = tmp->next;
	}
}

void find_biggest_smallest(t_data *data, char stack_name)
{
	t_stack_elem *stack;

	if(stack_name == 'a')
		stack = data->a;
	else if(stack_name == 'b')
		stack = data->b;
	else
		terminate("wrong stack");
	find_biggest(data, stack_name);
	find_smallest(data, stack_name);
}