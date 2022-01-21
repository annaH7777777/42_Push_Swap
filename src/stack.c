/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:37:20 by annharut          #+#    #+#             */
/*   Updated: 2022/01/21 22:17:23 by annharut         ###   ########.fr       */
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

void	swap(t_stack_elem *first, t_stack_elem *second)
{
	t_stack_elem	*next;

	next = second->next;
	first->next = next;
	second->next = first;
	first = second;
}

static void	create_stack(t_stack_elem **top, int number)
{
	*top = (t_stack_elem *)malloc(sizeof(t_stack_elem));
	if (!(*top))
		terminate("malloc error");
	(*top)->next = *top;
	(*top)->prev = *top;
	(*top)->number = number;
}

void	push(t_data *data, char stack_name, int number)
{
	t_stack_elem		**top;
	t_stack_elem		*tmp;

	if (stack_name == 'a')
		top = &data->a;
	else
		top = &data->b;
	if (*top)
	{
		tmp = (t_stack_elem *)malloc(sizeof(t_stack_elem));
		if (!tmp)
			terminate("malloc error");
		tmp->next = *top;
		tmp->prev = (*top)->prev;
		(*top)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->number = number;
		*top = (*top)->prev;
	}
	else
		create_stack(top, number);
}

void	pop(t_data *data, char stack_name)
{
	t_stack_elem		**top;
	t_stack_elem		*tmp;

	if (stack_name == 'a')
		top = &data->a;
	else
		top = &data->b;
	if (*top)
	{
		if ((*top)->next == *top)
		{
			free(*top);
			*top = NULL;
		}
		else
		{
			tmp = *top;
			(*top)->prev->next = (*top)->next;
			(*top)->next->prev = (*top)->prev;
			*top = (*top)->next;
			free(tmp);
		}
	}
}
