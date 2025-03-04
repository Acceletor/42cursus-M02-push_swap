#include "../include/push_swap.h"


bool	stack_sorted_ascend(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

bool	stack_sorted_descend(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr < stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node *get_cheapest_node(t_stack_node *stack)
{
    if(!stack)
        return (NULL);
    while (stack)
    {
        if (stack->cheapest)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}

void cheap_to_top(t_stack_node **stack, t_stack_node *cheapest_node, char stack_name)
{
	while (*stack != cheapest_node)
	{
		if (stack_name == 'a')
		{
			if (cheapest_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (cheapest_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}