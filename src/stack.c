/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:37:20 by annharut          #+#    #+#             */
/*   Updated: 2022/01/21 21:15:59 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add(t_data *data, int num)
{
	t_stack_elem	*elem;
	t_stack_elem	**stack;

	stack = &data->a;
	if (*stack)
	{
		elem = (t_stack_elem *) malloc (sizeof(t_stack_elem));
		if (!elem)
			terminate("malloc error");
		elem->next = *stack;
		elem->prev = (*stack)->prev;
		(*stack)->prev = elem;
		elem->prev->next = elem;
		elem->number = num;
	}
	else
	{
		*stack = (t_stack_elem *) malloc(sizeof(t_stack_elem));
		if (!(*stack))
			terminate("malloc error");
		(*stack)->next = (*stack);
		(*stack)->prev = (*stack);
		(*stack)->number = num;
	}
	data->size++;
}
