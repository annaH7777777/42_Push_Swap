/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 22:03:16 by annharut          #+#    #+#             */
/*   Updated: 2022/01/21 22:21:32 by annharut         ###   ########.fr       */
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

void	check_errors(char *number)
{
	if (check_num_chars(number) == -1)
		terminate("not digit error");
	if (!atoi_error(number))
		terminate("int limit error");
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
