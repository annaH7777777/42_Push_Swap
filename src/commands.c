#include <push_swap.h>

void    swap(t_stack *stack, t_stack_elem *first, t_stack_elem *second)
{
    t_stack_elem	*previous;
	t_stack_elem	*next;

	previous = first->previous;
	printf("\nprevious %d\n", previous->number);
	next = second->next;
	printf("\nnext %d\n", next->number);
	previous->next = second;
	printf("\nprevious->next %d\n", previous->next->number);
	second->previous = previous;
	printf("\nsecond->previous %d\n", second->previous->number);
	first->next = next;
	printf("\nfirst->next %d\n", first->next->number);
	next->previous = first;
	printf("\nnext->previous %d\n", next->previous->number);
	second->next = first;
	printf("\nsecond->next %d\n", second->next->number);
	first->previous = second;
	printf("\nfirst->previous %d\n", first->previous->number);
	stack->head = second;
	printf("\nstack->head %d\n", stack->head->number);
}

void	push(t_stack *stack, t_stack_elem *elem)
{
	t_stack_elem *tail;

	if(!stack || !elem)
		return ;
	if(!stack->head)
	{
		stack->head = elem;
		stack->head->previous = stack->head;
		stack->head->next = stack->head;
	}
	else
	{
		tail = stack->head->previous;
		elem->previous = tail;
		tail->next = elem;
		elem->next = stack->head;
		stack->head->previous = elem;
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
		elem->previous = NULL;
		elem->next = NULL;
	}
	else
	{
		
	}
}


void    sx(t_stack *stack)
{
    if(stack->size < 2)
        return;
    swap(stack, stack->head, stack->head->next);
}

void px(t_stack *to, t_stack *from)
{
    push(to, pop(from));
}
