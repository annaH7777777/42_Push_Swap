/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:36:57 by annharut          #+#    #+#             */
/*   Updated: 2022/01/21 20:27:46 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(long *arr, int len)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 0;
	while (i < len - 1)
	{
		if (arr[i] <= arr[i + 1])
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

void	find_median(t_data *data, char stack_name)
{
	long			*arr;
	size_t			i;
	int				quarter_len;
	t_stack_elem	*tmp;
	t_stack_elem	**stack;

	if (stack_name == 'a')
		stack = &data->a;
	else if (stack_name == 'b')
		stack = &data->b;
	else
		stack = NULL;
	i = 0;
	quarter_len = data->size / 4;
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
	data->quarter = arr[quarter_len];
	data->median = arr[quarter_len * 2];
	data->three_quarters = arr[quarter_len * 3];
	data->half_quarter = arr[quarter_len / 2];
	data->one_and_half_quarter = arr[quarter_len * 3 / 2];
	data->two_and_half_quarter = arr[quarter_len * 5 / 2];
	data->three_and_half_quarter = arr[quarter_len * 7 / 2];
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

static void	push_fourth_quarter(t_data *data)
{
	if (data->b && data->b->number > (data->median / 4) * 7)
		rotate_x(data, 'b');
	push_x(data, 'b');
}

void	push_quarters(t_data *data, int split)
{
	t_stack_elem	*stack_a;
	t_stack_elem	*stack_a_end;
	int				flag;

	stack_a = data->a;
	stack_a_end = data->a->prev;
	flag = 0;
	find_biggest_smallest(data, 'a');
	while (flag != 1)
	{
		if (stack_a == stack_a_end)
			flag = 1;
		if (split == 1 && stack_a->number <= data->quarter)
			push_first_quarter(data);
		else if (split == 2 && stack_a->number > data->quarter && stack_a->number <= data->median)
			push_second_quarter(data);
		else if (split == 3 && stack_a->number > data->median && stack_a->number <= data->three_quarters)
			push_third_quarter(data);
		else if (split == 4 && stack_a->number > data->three_quarters)
			push_fourth_quarter(data);
		else if (split == 4 && stack_a->number == data->smallest)
			break ;
		else
			rotate_x(data, 'a');
		stack_a = data->a;
	}
	reset_moves(data);
}
