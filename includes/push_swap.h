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
	//struct s_stack_elem	*previous;
	struct s_stack_elem *next;
}						t_stack_elem;

typedef struct			s_stack
{
	t_stack_elem		*head;
	size_t				size;
	size_t				pairs;
	t_stack_elem		*markup_head;
}						t_stack;

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


void	add(t_stack *stack, t_stack_elem *elem);
t_stack_elem	*create_elem(int number);
void	terminate(char *str);
void    swap(t_stack *stack, t_stack_elem *first, t_stack_elem *second);
void	rotate_x(t_stack **stack, enum e_instructions intruction);
void	reverse_rotate_x(t_stack *stack, enum e_instructions intruction);
void    swap_x(t_stack *stack, enum e_instructions intruction);
void	push_x(t_stack *to, t_stack *from, enum e_instructions intruction);

#endif