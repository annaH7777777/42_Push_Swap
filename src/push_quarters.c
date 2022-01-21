/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_quarters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 22:11:27 by annharut          #+#    #+#             */
/*   Updated: 2022/01/21 22:44:08 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	push_first_quarter(t_data *data)
{
	if (data->b && data->b->number > data->quarter / 2)
		rotate_x(data, 'b');
	push_x(data, 'b');
}

static void	push_second_quarter(t_data *data)
{
	if (data->b && data->b->number > (data->median / 4) * 3)
		rotate_x(data, 'b');
	push_x(data, 'b');
}

static void	push_third_quarter(t_data *data)
{
	if (data->b && data->b->number > (data->median / 4) * 5)
		rotate_x(data, 'b');
	push_x(data, 'b');
}

void	push_fourth_quarter(t_data *data)
{
	if (data->b && data->b->number > (data->median / 4) * 7)
		rotate_x(data, 'b');
	push_x(data, 'b');
}

void	push_quarters(t_data *data, int split)
{
	t_stack_elem	*a;
	t_stack_elem	*stack_a_end;
	int				flag;

	a = data->a;
	stack_a_end = data->a->prev;
	flag = 0;
	find_biggest_smallest(data, 'a');
	while (flag != 1)
	{
		if (a == stack_a_end)
			flag = 1;
		if (split == 1 && data->a->number <= data->quarter)
			push_first_quarter(data);
		else if (split == 2 && data->a->number > data->quarter
			&& data->a->number <= data->median)
			push_second_quarter(data);
		else if (split == 3 && data->a->number > data->median
			&& data->a->number <= data->three_quarters)
			push_third_quarter(data);
		else if (split == 4 && a->number > data->three_quarters)
			push_fourth_quarter(data);
		else if (split == 4 && a->number == data->smallest)
			break ;
		else
			rotate_x(data, 'a');
		a = data->a;
	}
	reset_moves(data);
}
