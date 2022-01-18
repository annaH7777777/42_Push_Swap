#include <push_swap.h>

t_stack *parse(int argc, char **argv)
{
	int	i;
	t_stack	*stack;
	char **numbers;

	stack = malloc(sizeof(t_stack));
	stack->size = 0;
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
			add(stack, create_elem(ft_atoi(numbers[i])));
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
			add(stack, create_elem(ft_atoi(argv[i])));
		}
	}
	return (stack);
}

void handle_3_size_stack(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->head->number;
	b = stack_a->head->next->number;
	c = stack_a->head->next->next->number;

	if(a > b && b < c && a < c)
		swap_x(stack_a, sa);
	else if(a > b && b > c)
	{
		swap_x(stack_a, sa);
		reverse_rotate_x(stack_a, rra);
	}
	else if(a > b && b < c && a > c)
		rotate_x(&stack_a, ra);
	else if(a < b && b  > c && a < c)
	{
		swap_x(stack_a, sa);
		rotate_x(&stack_a, ra);
	}
	else if(a < b && b > c && a > c)
		reverse_rotate_x(stack_a, rra);
}

void handle_5_size_stack(t_stack	*stack_a, t_stack	*stack_b)
{
	push_x(stack_b, stack_a, pb);
	push_x(stack_b, stack_a, pb);
	handle_3_size_stack(stack_a);
	//TODO return elements back from stack b in correct places
}

bool sort(t_stack	*stack)
{
	t_stack_elem *tmp;

	tmp = stack->head;
	while (tmp->next != NULL)	
	{
		if(tmp < tmp->next)
		tmp = tmp->next;
	}
	return true;
}

void handle_middle_size_stack(t_stack	*stack_a, t_stack	*stack_b, int chunk_count, int list_count)
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
	tmp = stack_a->head;
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
}

void sort_middle_size_stack(t_stack	*stack_a, t_stack	*stack_b, int chunk_count, int list_count)
{
	int split;
	t_stack_elem *tmp;
	t_stack_elem *tmp2;

	split = 1;
	find_median(stack_a);
	tmp = stack_a->head;
	tmp2 = stack_b->head;
	while (tmp)
	{
		push_median(stack_a, stack_b, split);
		while (tmp2)
		{
			find_biggest_smallest(stack_b);
			find_moves(stack_b);
		}
		

	}
	
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if(argc  < 2)
		terminate("wrong arguments");
	stack_a = parse(argc, argv);
	size_t i = 0;
	t_stack_elem *current = stack_a->head;
	while (i < stack_a->size)
	{
		printf("\ndigit %d\n",current->number);
		current = current->next;
		i++;
	}
	//swap(stack_index, stack_index->head, stack_index->head->next);
	// reverse_rotate_x(&stack_index);
	
	stack_b = malloc(sizeof(t_stack));
	if(!stack_b)
		terminate("malloc error");
	stack_b->head = malloc(sizeof(t_stack_elem));
	if(!stack_b->head)
		terminate("malloc error");
	if(stack_a->size == 3)
		handle_3_size_stack(stack_a);
	else if(stack_a->size == 5)
		handle_5_size_stack(stack_a, stack_b);
	else if(stack_a->size == 100)
		sort_middle_size_stack(stack_a, stack_b, 5, 100);

	printf("\nafter sorting\n");
	i = 0;
	current = stack_a->head;
	while (i < stack_a->size)
	{
		printf("\ndigit %d\n",current->number);
		current = current->next;
		i++;
	}
	
	return(0);
}