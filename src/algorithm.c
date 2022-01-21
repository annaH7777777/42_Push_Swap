/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 22:09:09 by annharut          #+#    #+#             */
/*   Updated: 2022/01/21 22:22:05 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

void	push_big_small(t_data *data, t_stack_elem *stack,
	t_stack_elem *stack_end)
{
	while (1)
	{
		while (stack->number != data->smallest
			&& stack->number != data->biggest)
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
