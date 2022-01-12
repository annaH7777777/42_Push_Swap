#include <push_swap.h>

t_stack *parse(int argc, char **argv)
{
	int	i;
	t_stack	*stack;
	char **numbers;

	stack = malloc(sizeof(t_stack));
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

int	main(int argc, char **argv)
{
	t_stack	*stack_index;

	if(argc  < 2)
		terminate("wrong arguments");
	stack_index = parse(argc, argv);
	size_t i = 0;
	t_stack_elem *current = stack_index->head;
	while (i < stack_index->size)
	{
		printf("\ndigit %d\n",current->number);
		current = current->next;
		i++;
	}
	swap(stack_index, stack_index->head, stack_index->head->next);
	
	return(0);
}