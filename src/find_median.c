#include "push_swap.h"

static void sort_array(long *arr, int len)
{
	int tmp;
	int i;

	tmp = 0;
	i = 0;
	while (i < len - 1)
	{
		if(arr[i] <= arr[i + 1])
			i++;
		else
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = 0;
		}
	}
	
}


void find_median(t_stack *stack)
{
	long *arr;
	int i;
	int quarter_len;
	t_stack_elem *tmp;

	i = 0;
	quarter_len = stack->size / 4;
	arr = malloc((stack->size + 1) * sizeof(long));
	if(!arr)
		terminate("malloc error");
	tmp = stack->head;
	while(i < stack->size)
	{
		arr[i++] = tmp->number;
		tmp = tmp->next;
	}
	sort_array(arr, stack->size);
	stack->quarter = arr[quarter_len];
	stack->median = arr[quarter_len * 2];
	stack->three_quarters = arr[quarter_len * 3];
	free(arr);
}

void reset_moves(t_stack *stack)
{
	stack->biggest = 0;
	stack->big_rotate = 0;
	stack->big_r_rotate = 0;
	stack->big_flag = 0;
	stack->smallest = 0;
	stack->small_rotate = 0;
	stack->small_r_rotate = 0;
	stack->small_flag = 0;
}

void push_median(t_stack *stack_a, t_stack *stack_b, int split)
{
	t_stack_elem *tmp;
	t_stack_elem *end;
	int flag;

	tmp = stack_a->head;
	end = stack_a->head->prev;
	flag  = 0;
	find_smallest(stack_a);
	while(1)
	{
		if(tmp == end)
			flag = 1;
		if(split == 1 && tmp->number <= stack_a->median)
			push_x(stack_a, stack_b);
		else if(split == 2 && tmp->number > stack_a->median)
			push_x(stack_a, stack_b);
		else if(tmp->number == stack_a->smallest)
			break;
		else
			rotate_x(stack_a);
		if(flag == 1);
			break ;
		tmp = stack_a->head;
	}
	reset_moves();
}