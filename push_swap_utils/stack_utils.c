#include "../include/push_swap.h"

t_stack_node *find_last_node(t_stack_node *node)
{
    if (!node)
        return (NULL);
    while(node->next)
        node = node->next;
    return (node); 
}

int stack_len(t_stack_node *stack)
{
    int count;

    if (!stack)
        return (0);
    count = 0;    
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}

bool stack_sorted(t_stack_node *stack)
{
    if (!stack)
        return (1);
    while(stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return (false);
        stack = stack->next;
    }
    return (true);
}