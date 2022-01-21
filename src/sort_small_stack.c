/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 22:04:47 by annharut          #+#    #+#             */
/*   Updated: 2022/01/21 22:05:26 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
