/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:37:15 by annharut          #+#    #+#             */
/*   Updated: 2022/01/21 22:43:55 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	parse(int argc, char **argv, t_data	*data)
{
	int		i;
	char	**numbers;

	i = -1;
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		while (numbers[++i])
		{
			check_errors(numbers[i]);
			add(data, ft_atoi(numbers[i]));
			free(numbers[i]);
		}
		free(numbers);
	}
	else
	{
		i = 0;
		while (++i < argc)
		{
			check_errors(argv[i]);
			add(data, ft_atoi(argv[i]));
		}
	}
}

void	sort_middle_stack(t_data	*data)
{
	int	split;

	split = 1;
	find_median(data, 'a');
	while (data->a)
	{
		push_median(data, split);
		while (data->b)
		{
			find_biggest_smallest(data, 'b');
			find_moves(data, 'b');
			if (data->b && (data->sm_rotate >= 0 || data->sm_rrotate >= 0
					|| data->big_rotate >= 0 || data->big_rrotate >= 0))
				push_big_small(data, data->b, data->b->prev);
		}
		while (--data->after_rotate && data->after_rotate != -1)
			rotate_x(data, 'a');
		split++;
		if (split == 3)
			break ;
	}
}

void	sort_big_stack(t_data *data)
{
	int				split;
	int				flag;
	t_stack_elem	*stack_a_end;

	split = 1;
	flag = 0;
	stack_a_end = data->a->prev;
	find_median(data, 'a');
	while (data->a)
	{
		push_quarters(data, split);
		while (data->b)
		{
			find_biggest_smallest(data, 'b');
			find_moves(data, 'b');
			if (data->b && (data->sm_rotate >= 0 || data->sm_rrotate >= 0
					|| data->big_rotate >= 0 || data->big_rrotate >= 0))
				push_big_small(data, data->b, data->b->prev);
		}
		while (--data->after_rotate && data->after_rotate != -1)
			rotate_x(data, 'a');
		split++;
		if (split == 5)
			break ;
	}
}

int	check_is_sorted(t_data *data)
{
	t_stack_elem	*stack;

	stack = data->a;
	while (stack)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
		if (stack->next == data->a)
			break ;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		terminate("wrong arguments");
	data = malloc(sizeof(t_data));
	if (!data)
		terminate("malloc error");
	reset_moves(data);
	data->size = 0;
	data->a = NULL;
	data->b = NULL;
	parse(argc, argv, data);
	check_dublicates(data);
	if (check_is_sorted(data))
		return (0);
	if (data->size <= 5)
		sort_small_stack(data);
	else if (data->size <= 100)
		sort_middle_stack(data);
	else
		sort_big_stack(data);
	return (0);
}
