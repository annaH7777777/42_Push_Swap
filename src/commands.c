/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:36:44 by annharut          #+#    #+#             */
/*   Updated: 2022/01/21 22:17:36 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_x(t_data *data, char stack_name)
{
	t_stack_elem	**stack;

	if (data->size < 2)
		return ;
	if (stack_name == 'a')
	{
		stack = &data->a;
		printf("sa\n");
	}
	else if (stack_name == 'b')
	{
		stack = &data->b;
		printf("sb\n");
	}
	else
		stack = NULL;
	swap(*stack, (*stack)->next);
}

void	push_x(t_data *data, char stack_name)
{
	t_stack_elem	**to;
	t_stack_elem	**from;
	char			pop_stack_name;
	int				num;

	if (stack_name == 'a')
	{
		to = &data->a;
		from = &data->b;
		pop_stack_name = 'b';
		num = data->b->number;
		printf("pa\n");
	}
	if (stack_name == 'b')
	{
		to = &data->b;
		from = &data->a;
		printf("pb\n");
		pop_stack_name = 'a';
		num = data->a->number;
	}
	pop(data, pop_stack_name);
	push(data, stack_name, num);
}

void	rotate_x(t_data *data, char stack_name)
{
	t_stack_elem	*tmp_head;
	t_stack_elem	*end;
	t_stack_elem	*tmp;
	t_stack_elem	**stack;

	if (stack_name == 'a')
	{
		stack = &data->a;
		end = data->a->prev;
		printf("ra\n");
	}
	else if (stack_name == 'b')
	{
		stack = &data->b;
		end = data->b->prev;
		printf("rb\n");
	}
	else
		stack = NULL;
	if (!*stack)
		return ;
	tmp_head = *stack;
	tmp = *stack;
	(*stack) = (*stack)->next;
}

void	reverse_rotate_x(t_data *data, char stack_name)
{
	t_stack_elem	*tmp_head;
	t_stack_elem	*tmp;
	t_stack_elem	**stack;

	if (stack_name == 'a')
	{
		stack = &data->a;
		printf("rra\n");
	}
	else if (stack_name == 'b')
	{
		stack = &data->b;
		printf("rrb\n");
	}
	else
		stack = NULL;
	if (!*stack)
		return ;
	tmp_head = *stack;
	tmp = *stack;
	(*stack) = (*stack)->prev;
}
