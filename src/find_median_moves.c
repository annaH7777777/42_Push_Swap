/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:36:57 by annharut          #+#    #+#             */
/*   Updated: 2022/01/21 22:37:14 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_median(t_data *data, char stack_name)
{
	long			*arr;
	size_t			i;
	t_stack_elem	*tmp;
	t_stack_elem	**stack;

	if (stack_name == 'a')
		stack = &data->a;
	else
		stack = &data->b;
	i = 0;
	arr = malloc((data->size + 1) * sizeof(long));
	if (!arr)
		terminate("malloc error");
	tmp = *stack;
	while (i < data->size)
	{
		arr[i++] = tmp->number;
		tmp = tmp->next;
	}
	sort_array(arr, data->size);
	data->quarter = arr[data->size / 4];
	data->median = arr[data->size / 4 * 2];
	data->three_quarters = arr[data->size / 4 * 3];
	free(arr);
}

void	reset_moves(t_data *data)
{
	data->biggest = 0;
	data->big_rotate = 0;
	data->big_rrotate = 0;
	data->big_flag = 0;
	data->smallest = 0;
	data->sm_rotate = 0;
	data->sm_rrotate = 0;
	data->small_flag = 0;
}

void	push_median(t_data *data, int split)
{
	t_stack_elem	*stack_a;
	t_stack_elem	*stack_a_end;
	int				flag;

	stack_a = data->a;
	stack_a_end = stack_a->prev;
	flag = 0;
	find_smallest(data, 'a');
	while (1)
	{
		if (stack_a == stack_a_end)
			flag = 1;
		if (split == 1 && stack_a->number <= data->median)
			push_x(data, 'b');
		else if (split == 2 && stack_a->number > data->median)
			push_x(data, 'b');
		else if (stack_a->number == data->smallest)
			break ;
		else
			rotate_x(data, 'a');
		if (flag == 1)
			break ;
		stack_a = data->a;
	}
	reset_moves(data);
}

void	find_moves(t_data *data, char stack_name)
{
	t_stack_elem	*stack;

	if (stack_name == 'a')
		stack = data->a;
	else
		stack = data->b;
	find_moves_smallest(data, 'b');
	find_moves_biggest(data, 'b');
	if (data->big_rotate != -1 && (data->big_rotate >= data->sm_rotate
			&& data->big_rotate >= data->sm_rrotate))
		data->big_rotate = -1;
	else if (data->big_rrotate != -1 && (data->big_rrotate >= data->sm_rotate
			&& data->big_rrotate >= data->sm_rrotate))
		data->big_rrotate = -1;
	else if (data->sm_rotate != -1 && (data->sm_rotate >= data->big_rotate
			&& data->sm_rotate >= data->big_rrotate))
		data->sm_rotate = -1;
	else if (data->sm_rrotate != -1 && (data->sm_rrotate >= data->big_rotate
			&& data->sm_rrotate >= data->big_rrotate))
		data->sm_rrotate = -1;
	if (data->sm_rotate != -1 || data->sm_rrotate != -1)
		data->small_flag = 1;
	else if (data->big_rotate != -1 || data->big_rrotate != -1)
		data->big_flag = 1;
}
