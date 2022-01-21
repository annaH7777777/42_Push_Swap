/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:11:26 by annharut          #+#    #+#             */
/*   Updated: 2022/01/21 21:16:49 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_stack_elem
{
	int					number;
	struct s_stack_elem	*prev;
	struct s_stack_elem	*next;
}				t_stack_elem;

typedef struct s_data
{
	t_stack_elem		*a;
	t_stack_elem		*b;

	size_t				size;
	long				quarter;
	long				median;
	long				three_quarters;
	long				half_quarter;
	long				one_and_half_quarter;
	long				two_and_half_quarter;
	long				three_and_half_quarter;

	long				biggest;
	int					big_rotate;
	int					big_rrotate;
	int					big_flag;

	long				smallest;
	int					sm_rotate;
	int					sm_rrotate;
	int					small_flag;

	int					after_rotate;
}						t_data;

void	add(t_data *data, int number);
void	terminate(char *str);
void	swap(t_stack_elem *first, t_stack_elem *second);
void	rotate_x(t_data *data, char stack_name);
void	reverse_rotate_x(t_data *data, char stack_name);
void	swap_x(t_data *data, char stack_name);
void	push_x(t_data *data, char stack_name);
void	find_smallest(t_data *data, char stack_name);
void	push_median(t_data *data, int split);
void	find_median(t_data *data, char stack_name);
void	find_smallest(t_data *data, char stack_name);
void	reset_moves(t_data *data);
void	find_biggest_smallest(t_data *data, char stack_name);
void	find_moves(t_data *data, char stack_name);
void	pop(t_data *data, char stack_name);
void	push(t_data *data, char stack_name, int number);
void	push_quarters(t_data *data, int split);
#endif