/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:37:24 by annharut          #+#    #+#             */
/*   Updated: 2022/01/21 22:10:43 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	terminate(char *str)
{
	printf("%s", str);
	exit(1);
}

void	sort_array(long *arr, int len)
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
