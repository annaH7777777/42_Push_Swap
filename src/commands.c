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

void	push(t_data *data, char stack_name, t_stack_elem *elem)
{
	t_stack_elem *stack;

	if(stack_name == 'a')
		stack = data->a;
	else if(stack_name == 'b')
		stack = data->b;
	else
		stack = NULL;
	if(!stack || !elem)
		return ;
	if(!elem)
	{
		stack = elem;
		stack->next = stack;
	}
	else
	{
		elem->next = stack;
		stack = elem;
	}
	data->size++;
}

t_stack_elem	*pop(t_data *data, char stack_name)
{
	t_stack_elem *elem;
	t_stack_elem *stack;
	
	elem = NULL;
	if(stack_name == 'a')
		stack = data->a;
	else if(stack_name == 'b')
		stack = data->b;
	else
		stack = NULL;
	if(!stack || data->size < 1)
		return elem;
	if(data->size == 1)
	{
		elem = stack;
		stack = NULL;
		elem->next = NULL;
	}
	else
	{
		elem = stack;
		stack = stack->next;
		elem->next = NULL;
	}
	data->size--;
	return(elem);
}


void    swap_x(t_data *data, char stack_name)
{
    t_stack_elem *stack;

	if(data->size < 2)
        return;
	if(stack_name == 'a')
	{
		stack = data->a;
		printf("\nsa\n");
	}
	else if(stack_name == 'b')
	{
		stack = data->b;
		printf("\nsb\n");
	}
	else
		stack = NULL;
    swap(stack, stack->next);
		
}

void push_x(t_data *data, char stack_name)
{
    t_stack_elem *to;
    t_stack_elem *from;
	char pop_stack_name;
	
	if(stack_name == 'a')
	{
		to = data->a;
		from = data->b;
		pop_stack_name = 'b';
		printf("\npa\n");
	}
	if(stack_name == 'b')
	{
		to = data->b;
		from = data->a;
		printf("\npb\n");
		pop_stack_name = 'a';
	}
	push(data, stack_name, pop(data, pop_stack_name));
}

void rotate_x(t_data *data, char stack_name)
{
	int i;
	t_stack_elem *tmp_head;
	//t_stack_elem *tmp;
	t_stack_elem *stack;

	if(stack_name == 'a')
	{
		stack = data->a;
		printf("\nra\n");
	}
	else if(stack_name == 'b')
	{
		stack = data->b;
		printf("\nrb\n");
	}
	else
		stack = NULL;
	if(!stack)
		return ;
	i = -1;
	tmp_head = stack;
	//tmp = (*stack)->head;
	stack = stack->next;
	printf("\nrotate\n");
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	printf("\nrotate 2\n");
	stack->next = tmp_head;
	stack->next->next = NULL;
}

void reverse_rotate_x(t_data *data, char stack_name)
{
	int i;
	t_stack_elem *tmp_head;
	t_stack_elem *tmp;
	t_stack_elem *stack;

	if(stack_name == 'a')
	{
		stack = data->a;
		printf("\nra\n");
	}
	else if(stack_name == 'b')
	{
		stack = data->b;
		printf("\nrb\n");
	}
	else
		stack = NULL;

	if(!stack)
		return ;
	i = -1;
	tmp_head = stack;
	tmp = stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	//TODO NULL pointer at the end of list
	stack = tmp;
	stack->next = tmp_head;
}