/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:37:03 by annharut          #+#    #+#             */
/*   Updated: 2022/01/21 22:15:44 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_moves_to_start(t_data *data, char stack_name, int flag)
{
	t_stack_elem	*stack;
	t_stack_elem	*tmp;
	int				element;

	stack = NULL;
	if (stack_name == 'a')
		stack = data->a;
	else
		stack = data->b;
	if (stack)
	{
		tmp = stack;
		if (flag == 1)
			element = data->smallest;
		else
			element = data->biggest;
		while (tmp->number != element)
		{
			if (flag == 1)
				data->sm_rotate++;
			else
				data->big_rotate++;
			tmp = tmp->next;
		}
	}
}

static void	calculate_rotations(t_data *data, t_stack_elem *tmp,
	int element, int flag)
{
	while (tmp->number != element)
	{
		if (flag == 1)
			data->sm_rrotate++;
		else
			data->big_rrotate++;
		tmp = tmp->prev;
	}
	if (flag == 1)
		data->sm_rrotate++;
	else
		data->big_rrotate++;
}

void	find_moves_to_end(t_data *data, char stack_name, int flag)
{
	t_stack_elem	*stack;
	t_stack_elem	*tmp;
	int				element;

	stack = NULL;
	if (stack_name == 'a')
		stack = data->a;
	else
		stack = data->b;
	if (stack)
	{
		tmp = stack->prev;
		if (flag == 1)
			element = data->smallest;
		else
			element = data->biggest;
		calculate_rotations(data, tmp, element, flag);
	}
}

void	find_moves_smallest(t_data *data, char stack_name)
{
	t_stack_elem	*stack;
	int				flag;

	stack = NULL;
	if (stack_name == 'a')
		stack = data->a;
	else
		stack = data->b;
	flag = 1;
	if (stack)
	{
		find_moves_to_start(data, stack_name, flag);
		find_moves_to_end(data, stack_name, flag);
		if (data->sm_rotate <= data->sm_rrotate)
			data->sm_rrotate = -1;
		else
			data->sm_rotate = -1;
	}
}

void	find_moves_biggest(t_data *data, char stack_name)
{
	t_stack_elem	*stack;
	int				flag;

	stack = NULL;
	if (stack_name == 'a')
		stack = data->a;
	else
		stack = data->b;
	flag = 2;
	if (stack)
	{
		find_moves_to_start(data, stack_name, flag);
		find_moves_to_end(data, stack_name, flag);
		if (data->big_rotate <= data->big_rrotate)
			data->big_rrotate = -1;
		else
			data->big_rotate = -1;
	}
}
