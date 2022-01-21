#include "push_swap.h"

void    find_moves_to_start(t_data *data, char stack_name, int flag)
{
    t_stack_elem *stack;
    t_stack_elem *tmp;
    int element;

    stack = NULL;
    if(stack_name == 'a')
        stack = data->a;
    else if(stack_name == 'b')
        stack = data->b;
    else
        terminate("wrong stack");
    if(stack)
    {
        tmp = stack;
        if(flag == 1)
            element = data->smallest;
        else
            element = data->biggest;
        while(tmp->number != element)
        {
            if(flag == 1)
                data->small_rotate++;
            else
                data->big_rotate++;
            tmp = tmp->next;
        }
    }
}

void    find_moves_to_end(t_data *data, char stack_name, int flag)
{
    t_stack_elem *stack;
    t_stack_elem *tmp;
    int element;

    stack = NULL;
    if(stack_name == 'a')
        stack = data->a;
    else if(stack_name == 'b')
        stack = data->b;
    else
        terminate("wrong stack");
    if(stack)
    {
        tmp = stack->prev;
        if(flag == 1)
            element = data->smallest;
        else
            element = data->biggest;
        while (tmp->number != element)
        {
            if(flag == 1)
                data->small_r_rotate++;
            else
                data->big_r_rotate++;
            tmp = tmp->prev;
        }
        if(flag == 1)
            data->small_r_rotate++;
        else
            data->big_r_rotate++;
    }
    
}

void     find_moves_smallest(t_data *data, char stack_name)
{
    t_stack_elem *stack;
    int flag;

    stack = NULL;
    if(stack_name == 'a')
        stack = data->a;
    else if(stack_name == 'b')
        stack = data->b;
    else
        terminate("wrong stack");
    flag = 1;
    if(stack)
    {
        find_moves_to_start(data, stack_name, flag);
        find_moves_to_end(data, stack_name, flag);
        if(data->small_rotate <= data->small_r_rotate)
            data->small_r_rotate = -1;
        else
            data->small_rotate = -1;
    }
}

void    find_moves_biggest(t_data *data, char stack_name)
{
    t_stack_elem *stack;
    int flag;

    stack = NULL;
    if(stack_name == 'a')
        stack = data->a;
    else if(stack_name == 'b')
        stack = data->b;
    else
        terminate("wrong stack");
    flag = 2;
    if(stack)
    {
        find_moves_to_start(data, stack_name, flag);
        find_moves_to_end(data, stack_name, flag);
        if(data->big_rotate <= data->big_r_rotate)
            data->big_r_rotate = -1;
        else
            data->big_rotate = -1;
    }
}

void    find_moves(t_data *data, char stack_name)
{
    t_stack_elem *stack;

    if(stack_name == 'a')
        stack = data->a;
    else if(stack_name == 'b')
        stack = data->b;
    else
        terminate("wrong stack");
    find_moves_smallest(data, 'b');
    find_moves_biggest(data, 'b');
    if(data->big_rotate != -1 && (data->big_rotate >= data->small_rotate && data->big_rotate >= data->small_r_rotate))
        data->big_rotate = -1;
    else if(data->big_r_rotate != -1 && (data->big_r_rotate >= data->small_rotate && data->big_r_rotate >= data->small_r_rotate))
        data->big_r_rotate = -1;
    else if(data->small_rotate != -1 && (data->small_rotate >= data->big_rotate && data->small_rotate >= data->big_r_rotate))
        data->small_rotate = -1;
    else if(data->small_r_rotate != -1 && (data->small_r_rotate >= data->big_rotate && data->small_r_rotate >= data->big_r_rotate))
        data->small_r_rotate = -1;
    if(data->small_rotate != -1 || data->small_r_rotate != -1)
        data->small_flag = 1;
    else if(data->big_rotate != -1 || data->big_r_rotate != -1)
        data->big_flag = 1;
}