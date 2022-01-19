#include <push_swap.h>

t_stack_elem *parse(int argc, char **argv, t_data	*data)
{
	int	i;
	t_stack_elem	*stack;
	char **numbers;

	stack = malloc(sizeof(t_stack_elem));
	data->size = 0;
	if(stack == NULL)
		terminate("malloc error");
	i = 0;
	if(argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		while (numbers[i++])
		{
			if(!ft_isdigit(numbers[i][0]))
				terminate("not digit error");
			add(data, create_elem(ft_atoi(numbers[i])));
			free(numbers[i]);
		}
		free(numbers);
	}
	else
	{
		while (++i < argc)
		{
			if(!ft_isdigit(argv[i][0]))
				terminate("not digit error");
			//printf("\nsave digit %d\n", ft_atoi(argv[i]));
			add(data, create_elem(ft_atoi(argv[i])));
		}
	}
	return (stack);
}

void handle_3_size_stack(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->a->number;
	b = data->a->next->number;
	c = data->a->next->next->number;

	if(a > b && b < c && a < c)
		swap_x(data, 'a');
	else if(a > b && b > c)
	{
		swap_x(data, 'a');
		reverse_rotate_x(data, 'a');
	}
	else if(a > b && b < c && a > c)
		rotate_x(data, 'a');
	else if(a < b && b  > c && a < c)
	{
		swap_x(data, 'a');
		rotate_x(data, 'a');
	}
	else if(a < b && b > c && a > c)
		reverse_rotate_x(data, 'a');
}

void handle_5_size_stack(t_data	*data)
{
	push_x(data, 'b');
	push_x(data, 'b');
	handle_3_size_stack(data);
	//TODO return elements back from stack b in correct places
}

/*void handle_middle_size_stack(t_data *data, int chunk_count, int list_count)
{
	int i;
	t_chunk *chunk;
	t_stack_elem *tmp;
	int hold_first;
	int hold_last;
	int hold_first_pos;
	int hold_last_pos;
	int list_middle_pos;
	int hold_first_oper_count;
	enum e_instructions hold_first_oper_type;
	int hold_last_oper_count;
	enum e_instructions hold_last_oper_type;

	list_middle_pos = list_count / 2;
	i = 0;
	chunk = (t_chunk *) malloc(sizeof(t_chunk));
	printf("\nchunk1\n");
	chunk_count = 0;
	//while(++i < chunk_count)
	//{
		chunk->start = i * 20;
		chunk->end = i * 20 + 19;
		//chunk = chunk->next;
		//chunk = malloc(sizeof(t_chunk));
	//}
	printf("\nchunk2\n");
	hold_first_pos = 0;
	hold_last_pos = 0;
	tmp = data->a;
	i = 0;
	while (tmp->next)
	{
		if(tmp->number > chunk->start && tmp->number < chunk->end)
		{
			hold_first = tmp->number;
			hold_first_pos = i;
			break;
		}
		i++;
		tmp = tmp->next;
	}
	printf("\nchunk3\n");
	while (tmp->next)
	{
		if(tmp->number > chunk->start && tmp->number < chunk->end)
		{
			hold_last = tmp->number;
			hold_last_pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	printf("\nchunk4\n");

	if(hold_first_pos < list_middle_pos)
	{
		hold_first_oper_count = hold_first_pos;
		hold_first_oper_type = ra;
	}
	else
	{
		hold_first_oper_count = list_count - hold_first_pos;
		hold_first_oper_type = rra;
	}

	if(hold_last_pos < list_middle_pos)
	{
		hold_last_oper_count = hold_last_pos;
		hold_last_oper_type = ra;
	}
	else
	{
		hold_last_oper_count = list_count - hold_last_pos;
		hold_last_oper_type = rra;
	}
	i = -1;
	if(hold_first_oper_count < hold_last_oper_count)
	{
		while (++i < hold_first_oper_count)
		{
			printf("\nhold first\n");
			if(hold_first_oper_type == ra)
				rotate_x(&stack_a, hold_first_oper_type);
			else if(hold_first_oper_type == rra)
				reverse_rotate_x(stack_b, hold_first_oper_type);
			printf("\nhold first 2\n");
		}
	}
	else
	{
		while (++i < hold_last_oper_count)
		{
			printf("\nhold last\n");
			if(hold_last_oper_type == ra)
				rotate_x(&stack_a, hold_last_oper_type);
			else if(hold_last_oper_type == rra)
				reverse_rotate_x(stack_b, hold_last_oper_type);
		}
	}
	if(sort(stack_b))
		push_x(stack_a, stack_b, pb);
}*/

static void rotate_and_push_to_a(t_data *data)
{
	if(data->small_rotate >= 0)
		while(data->small_rotate--)
			rotate_x(data, 'b');
	else if(data->small_r_rotate >= 0)
		while(data->small_r_rotate--)
			reverse_rotate_x(data, 'b');
	if(data->big_rotate >= 0)
		while(data->big_rotate--)
			rotate_x(data, 'b');
	else if(data->big_r_rotate >= 0)
		while(data->big_r_rotate--)
			reverse_rotate_x(data, 'b');
	push_x(data, 'a');
	if(data->small_flag)
		rotate_x(data, 'a');
	if(data->big_flag || !data->b)
		data->after_rotate++;
	reset_moves(data);

}

static void push_big_small(t_data *data, t_stack_elem *stack, t_stack_elem *stack_end)
{
	while(1)
	{
		while(stack->number != data->smallest && stack->number != data->biggest)
			stack = stack->next;
		if(stack->number == data->smallest || stack->number == data->biggest)
		{
			rotate_and_push_to_a(data);
			break ;
		}
		else
			stack = stack->next;
		if(stack == stack_end)
			break ;
		stack = data->b;
	}
}

void sort_middle_size_stack(t_data	*data) //insertion_solve_half
{
	int split;
	t_stack_elem *tmp;
	t_stack_elem *tmp2;

	split = 1;
	find_median(data, 'a');
	tmp = data->a;
	tmp2 = data->b;
	while (tmp)
	{
		push_median(data, split);
		while (tmp2)
		{
			find_biggest_smallest(data, 'b');
			find_moves(data, 'b');
			if(data->b && (data->small_rotate >= 0 || data->small_r_rotate >= 0
				|| data->big_rotate >= 0 || data->big_r_rotate >= 0))
			push_big_small(data, data->b, data->b->prev);
		}
		while(--data->after_rotate)
			rotate_x(data, 'a');
		split++;
		if(split == 3)
			break;
	}
	
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if(argc  < 2)
		terminate("wrong arguments");
	data = malloc(sizeof(t_data));
	if(!data)
		terminate("malloc error");
	data->a = parse(argc, argv, data);
	size_t i = 0;
	t_stack_elem *current = data->a;
	while (i < data->size)
	{
		printf("\ndigit %d\n",current->number);
		current = current->next;
		i++;
	}
	//swap(stack_index, stack_index->head, stack_index->head->next);
	// reverse_rotate_x(&stack_index);
	
	data->b = malloc(sizeof(t_stack_elem));
	if(!data->b)
		terminate("malloc error");
	if(data->size == 3)
		handle_3_size_stack(data);
	else if(data->size == 5)
		handle_5_size_stack(data);
	else if(data->size == 100)
		sort_middle_size_stack(data);

	printf("\nafter sorting\n");
	i = 0;
	current = data->a;
	while (i < data->size)
	{
		printf("\ndigit %d\n",current->number);
		current = current->next;
		i++;
	}
	
	return(0);
}