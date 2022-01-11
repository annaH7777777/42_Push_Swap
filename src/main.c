#include <push_swap.h>

t_stack *parse(int argc, char **argv)
{
	int	i;
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	i = -1;
	while (i < argc)
	{
		add(stack, create_elem(ft_atoi(argv[++i])));
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_index;

	if(argc  < 2)
		terminate("wrong arguments");
	stack_index = parse(argc, argv);
	return(0);
}