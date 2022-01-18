#include <push_swap.h>

void    swap(t_stack *stack, t_stack_elem *first, t_stack_elem *second)
{
	t_stack_elem	*next;

	next = second->next;
	//printf("\nnext %d\n", next->number);
	first->next = next;
	//printf("\nfirst->next %d\n", first->next->number);
	second->next = first;
	//printf("\nsecond->next %d\n", second->next->number);
	stack->head = second;
	//printf("\nstack->head %d\n", stack->head->number);
}

void	push(t_stack *stack, t_stack_elem *elem)
{
	//t_stack_elem *tail;

	if(!stack || !elem)
		return ;
	if(!stack->head)
	{
		stack->head = elem;
		stack->head->next = stack->head;
	}
	else
	{
		elem->next = stack->head;
		stack->head = elem;
	}
	stack->size++;
}

t_stack_elem	*pop(t_stack *stack)
{
	t_stack_elem *elem;
	
	elem = NULL;
	if(!stack || stack->size < 1)
		return elem;
	if(stack->size == 1)
	{
		elem = stack->head;
		stack->head = NULL;
		elem->next = NULL;
	}
	else
	{
		elem = stack->head;
		stack->head = stack->head->next;
		elem->next = NULL;
	}
	stack->size--;
	return(elem);
}


void    swap_x(t_stack *stack, enum e_instructions instruction)
{
    if(stack->size < 2)
        return;
    swap(stack, stack->head, stack->head->next);
	if(instruction == sa)
		printf("\nsa\n");
	if(instruction == sb)
		printf("\nsb\n");
}

void push_x(t_stack *to, t_stack *from, enum e_instructions instruction)
{
    push(to, pop(from));
	if(instruction == pa)
		printf("\npa\n");
	if(instruction == pb)
		printf("\npb\n");
}

void rotate_x(t_stack **stack, enum e_instructions instruction)
{
	int i;
	t_stack_elem *tmp_head;
	t_stack_elem *tmp;

	if(!stack)
		return ;
	i = -1;
	tmp_head = (*stack)->head;
	tmp = (*stack)->head;
	(*stack)->head = (*stack)->head->next;
	printf("\nrotate\n");
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	printf("\nrotate 2\n");
	tmp->next = tmp_head;
	tmp->next->next = NULL;
	if(instruction == ra)
		printf("\nra\n");
	if(instruction == rb)
		printf("\nrb\n");
}

void reverse_rotate_x(t_stack *stack, enum e_instructions instruction)
{
	int i;
	t_stack_elem *tmp_head;
	t_stack_elem *tmp;

	if(!stack)
		return ;
	i = -1;
	tmp_head = stack->head;
	tmp = stack->head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	//TODO NULL pointer at the end of list
	stack->head = tmp;
	stack->head->next = tmp_head;
	if(instruction == rra)
		printf("\nrra\n");
	if(instruction == rrb)
		printf("\nrrb\n");
}