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

// void sort_stacks(t_stack_node **a, t_stack_node **b)
// {

// }