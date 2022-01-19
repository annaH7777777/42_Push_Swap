// Allowed functions
// write read malloc free exit libft
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"

typedef struct			s_stack_elem
{
	int					number;
	//size_t				index;
	//bool				keep_in_stack;
	struct s_stack_elem	*prev;
	struct s_stack_elem *next;
}						t_stack_elem;

typedef struct			s_data
{
	t_stack_elem		*a;
	t_stack_elem		*b;

	size_t				size;
	//size_t				pairs;
	//t_stack_elem		*markup_head;
	long				quarter;
	long				median;
	long				three_quarters;

	long				biggest;
	int					big_rotate;
	int					big_r_rotate;
	int					big_flag;

	long				smallest;
	int					small_rotate;
	int					small_r_rotate;
	int					small_flag;

	int					after_rotate;
}						t_data;

typedef struct s_chunk
{
	int start;
	int end;
	struct s_chunk *next;
}	t_chunk;


enum e_instructions
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};	


void	add(t_data *data, t_stack_elem *elem);
t_stack_elem	*create_elem(int number);
void	terminate(char *str);
void    swap(t_stack_elem *first, t_stack_elem *second);
void	rotate_x(t_data *data, char stack_name);
void	reverse_rotate_x(t_data *data, char stack_name);
void    swap_x(t_data *data, char stack_name);
void	push_x(t_data *data, char stack_name);
void	find_smallest(t_data *data, char stack_name);
void	push_median(t_data *data, int split);
void	find_median(t_data *data, char stack_name);
void	find_smallest(t_data *data, char stack_name);
void	reset_moves(t_data *data);
void	find_biggest_smallest(t_data *data, char stack_name);
void    find_moves(t_data *data, char stack_name);
#endif