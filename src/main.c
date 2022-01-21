/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:37:15 by annharut          #+#    #+#             */
/*   Updated: 2022/01/21 21:07:55 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	check_num_chars(char *number)
{
	int	i;

	i = 0;
	if (!ft_isdigit(number[i]) && number[i] != '-' && number[i] != '+')
		return (-1);
	i++;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	atoi_error(char *str)
{
	int		i;
	int		j;
	int		sign_min;
	long	sum;

	i = 0;
	j = 0;
	sign_min = 1;
	sum = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign_min = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + str[i] - '0';
		i++;
	}
	sum *= sign_min;
	return (sum <= (long)2147483647 && sum >= (long)(-2147483648));
}

void	parse(int argc, char **argv, t_data	*data)
{
	int		i;
	char	**numbers;

	data->size = 0;
	data->a = NULL;
	data->b = NULL;
	i = -1;
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		while (numbers[++i])
		{
			if (check_num_chars(numbers[i]) == -1)
				terminate("not digit error");
			if (!atoi_error(numbers[i]))
				terminate("int limit error");
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
			if (check_num_chars(argv[i]) == -1)
				terminate("not digit error");
			if (!atoi_error(argv[i]))
				terminate("int limit error");
			add(data, ft_atoi(argv[i]));
		}
	}
}

void	sort_2_size_stack(t_data *data)
{
	if (data->a->number > data->a->next->number)
		swap_x(data, 'a');
}

void	sort_3_size_stack(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->a->number;
	b = data->a->next->number;
	c = data->a->next->next->number;
	if (a > b && b < c && a < c)
		swap_x(data, 'a');
	else if (a > b && b > c)
	{
		swap_x(data, 'a');
		reverse_rotate_x(data, 'a');
	}
	else if (a > b && b < c && a > c)
		rotate_x(data, 'a');
	else if (a < b && b > c && a < c)
	{
		swap_x(data, 'a');
		rotate_x(data, 'a');
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_x(data, 'a');
}

void	sort_4_size_stack(t_data *data)
{
	t_stack_elem	*stack_a;

	stack_a = data->a;
	find_biggest_smallest(data, 'a');
	while (stack_a->number != data->smallest)
	{
		rotate_x(data, 'a');
		stack_a = stack_a->next;
	}
	push_x(data, 'b');
	sort_3_size_stack(data);
	push_x(data, 'a');
}

void	sort_5_size_stack(t_data *data)
{
	t_stack_elem	*stack_a;
	t_stack_elem	*stack_a_end;
	int				flag;

	stack_a = data->a;
	stack_a_end = data->a->prev;
	find_median(data, 'a');
	flag = 0;
	while (flag != -1)
	{
		if (data->a == stack_a_end)
			flag = -1;
		if (data->a->number < data->median)
			push_x(data, 'b');
		else
			rotate_x(data, 'a');
	}
	sort_3_size_stack(data);
	push_x(data, 'a');
	push_x(data, 'a');
	if (data->a->number > data->a->next->number)
		swap_x(data, 'a');
}

void	sort_small_stack(t_data	*data)
{
	if (data->size == 2)
		sort_2_size_stack(data);
	else if (data->size == 3)
		sort_3_size_stack(data);
	else if (data->size == 4)
		sort_4_size_stack(data);
	else if (data->size == 5)
		sort_5_size_stack(data);
}

static void	rotate_and_push_to_a(t_data *data)
{
	if (data->sm_rotate >= 0)
		while (data->sm_rotate--)
			rotate_x(data, 'b');
	else if (data->sm_rrotate >= 0)
		while (data->sm_rrotate--)
			reverse_rotate_x(data, 'b');
	else if (data->big_rotate >= 0)
		while (data->big_rotate--)
			rotate_x(data, 'b');
	else if (data->big_rrotate >= 0)
		while (data->big_rrotate--)
			reverse_rotate_x(data, 'b');
	push_x(data, 'a');
	if (data->small_flag)
		rotate_x(data, 'a');
	if (data->big_flag || !data->b)
		data->after_rotate++;
	reset_moves(data);
}

static void	push_big_small(t_data *data, t_stack_elem *stack, t_stack_elem *stack_end)
{
	while (1)
	{
		while (stack->number != data->smallest && stack->number != data->biggest)
			stack = stack->next;
		if (stack->number == data->smallest || stack->number == data->biggest)
		{
			rotate_and_push_to_a(data);
			break ;
		}
		else
			stack = stack->next;
		if (stack == stack_end)
			break ;
		stack = data->b;
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
	int	split;

	split = 1;
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

void	check_dublicates(t_data *data)
{
	t_stack_elem		*elem;
	t_stack_elem		*elem_2;

	elem = data->a;
	while (elem != data->a->prev)
	{
		elem_2 = elem->next;
		while (elem_2 != data->a)
		{
			if (elem->number == elem_2->number)
				terminate("dublicate numbers");
			elem_2 = elem_2->next;
		}
		elem = elem->next;
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
