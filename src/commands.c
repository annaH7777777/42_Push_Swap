#include <push_swap.h>

void    swap(t_stack_elem *first, t_stack_elem *second)
{
	t_stack_elem	*next;

	next = second->next;
	//printf("\nnext %d\n", next->number);
	first->next = next;
	//printf("\nfirst->next %d\n", first->next->number);
	second->next = first;
	//printf("\nsecond->next %d\n", second->next->number);
	first = second;
	//printf("\nstack->head %d\n", stack->head->number);
}

void	push(t_data *data, char stack_name, int number)
{
	t_stack_elem		**top;
	t_stack_elem		*tmp;

	top = (stack_name == 'a') ? &data->a : &data->b;
	if (*top)
	{
		if (!(tmp = (t_stack_elem *)malloc(sizeof(t_stack_elem))))
			terminate("malloc error");
		tmp->next = *top;
		tmp->prev = (*top)->prev;
		(*top)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->number = number;
		*top = (*top)->prev;
	}
	else
	{
		if (!(*top = (t_stack_elem *)malloc(sizeof(t_stack_elem))))
			terminate("malloc error");
		(*top)->next = *top;
		(*top)->prev = *top;
		(*top)->number = number;
	}
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
			// (*top)->prev = tmp->prev;
			*top = (*top)->next;
			// printf("\ntop = %d\n", (*top)->number);
			free(tmp);
		}
	}
}


void    swap_x(t_data *data, char stack_name)
{
    t_stack_elem **stack;

	if(data->size < 2)
        return;
	if(stack_name == 'a')
	{
		stack = &data->a;
		printf("sa\n");
	}
	else if(stack_name == 'b')
	{
		stack = &data->b;
		printf("sb\n");
	}
	else
		stack = NULL;
    swap(*stack, (*stack)->next);
		
}

void push_x(t_data *data, char stack_name)
{
    t_stack_elem **to;
    t_stack_elem **from;
	char pop_stack_name;
	int num;
	
	if(stack_name == 'a')
	{
		to = &data->a;
		from = &data->b;
		pop_stack_name = 'b';
		num = data->b->number;
		printf("pa\n");
	}
	if(stack_name == 'b')
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

void rotate_x(t_data *data, char stack_name)
{
	int i;
	t_stack_elem *tmp_head;
	t_stack_elem *end;
	t_stack_elem *tmp;
	t_stack_elem **stack;

	if(stack_name == 'a')
	{
		stack = &data->a;
		end = data->a->prev;
		printf("ra\n");
	}
	else if(stack_name == 'b')
	{
		stack = &data->b;
		end = data->b->prev;
		printf("rb\n");
	}
	else
		stack = NULL;
	if(!*stack)
		return ;
	i = -1;
	// printf("\n stack = %d \n", stack == NULL);
	tmp_head = *stack;
	tmp = *stack;
	//tmp = (*stack)->head;
	//*stack = (*stack)->next;
	//printf("\nrotate\n");
	// while (1)
	// {
	// 	tmp = tmp->next;
	// 	if(tmp == end)
	// 		break;
	// }
	// //printf("\nrotate 2\n");
	// tmp->next = tmp_head;
	// tmp->next->next = NULL;
	(*stack) = (*stack)->next;
}

void reverse_rotate_x(t_data *data, char stack_name)
{
	int i;
	t_stack_elem *tmp_head;
	t_stack_elem *tmp;
	t_stack_elem **stack;

	if(stack_name == 'a')
	{
		stack = &data->a;
		printf("rra\n");
	}
	else if(stack_name == 'b')
	{
		stack = &data->b;
		printf("rrb\n");
	}
	else
		stack = NULL;

	if(!*stack)
		return ;
	i = -1;
	tmp_head = *stack;
	tmp = *stack;
	// while (tmp->next != NULL)
	// {
	// 	tmp = tmp->next;
	// }
	// //TODO NULL pointer at the end of list
	// *stack = tmp;
	// (*stack)->next = tmp_head;
	// //(*stack)->prev = 
	// (*stack)->prev->next = NULL;
	(*stack) = (*stack)->prev;
}