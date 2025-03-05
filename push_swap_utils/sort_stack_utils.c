/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:55:51 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/05 15:47:21 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_stack_node	*get_cheapest_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	cheap_to_top(t_stack_node **s, t_stack_node *cheap, char stack_name)
{
	while (*s != cheap)
	{
		if (stack_name == 'a')
		{
			if (cheap->above_median)
				ra(s);
			else
				rra(s);
		}
		else if (stack_name == 'b')
		{
			if (cheap->above_median)
				rb(s);
			else
				rrb(s);
		}
	}
}
