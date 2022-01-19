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

void find_median(t_data *data, char stack_name)
{
	long *arr;
	size_t i;
	int quarter_len;
	t_stack_elem *tmp;
	t_stack_elem *stack;

	if(stack_name == 'a')
		stack = data->a;
	else if(stack_name == 'b')
		stack = data->b;
	else
		stack = NULL;
	i = 0;
	quarter_len = data->size / 4;
	arr = malloc((data->size + 1) * sizeof(long));
	if(!arr)
		terminate("malloc error");
	tmp = stack;
	while(i < data->size)
	{
		arr[i++] = tmp->number;
		tmp = tmp->next;
	}
	sort_array(arr, data->size);
	data->quarter = arr[quarter_len];
	data->median = arr[quarter_len * 2];
	data->three_quarters = arr[quarter_len * 3];
	free(arr);
}

void reset_moves(t_data *data)
{
	data->biggest = 0;
	data->big_rotate = 0;
	data->big_r_rotate = 0;
	data->big_flag = 0;
	data->smallest = 0;
	data->small_rotate = 0;
	data->small_r_rotate = 0;
	data->small_flag = 0;
}

void push_median(t_data *data, int split)
{
	t_stack_elem *tmp;
	t_stack_elem *end;
	t_stack_elem *stack_a;
	t_stack_elem *stack_b;
	int flag;

	stack_a = data->a;
	stack_b = data->b;
	tmp = stack_a;
	end = stack_a->prev;
	flag  = 0;
	find_smallest(data, 'a');
	while(1)
	{
		if(tmp == end)
			flag = 1;
		if(split == 1 && tmp->number <= data->median)
			push_x(data, 'b');
		else if(split == 2 && tmp->number > data->median)
			push_x(data, 'b');
		else if(tmp->number == data->smallest)
			break;
		else
			rotate_x(data, 'a');
		if(flag == 1)
			break ;
		tmp = stack_a;
	}
	reset_moves(data);
}