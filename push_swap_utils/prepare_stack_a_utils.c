/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack_a_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:43:15 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/05 15:50:11 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	else if (b > a)
		return (b);
	else
		return (a);
}

static int	compute_push_cost(t_stack_node *node, int len_a, int len_b)
{
	int	cost;

	if (node->above_median != node->target_node->above_median)
	{
		if (node->above_median)
			cost = node->index;
		else
			cost = len_a - node->index;
		if (node->target_node->above_median)
			cost += node->target_node->index;
		else
			cost += len_b - node->target_node->index;
	}
	else
	{
		if (node->above_median)
			cost = max(node->index, node->target_node->index);
		else
		{
			cost = max(len_a - node->index, len_b - node->target_node->index);
		}
	}
	return (cost);
}

void	calculate_push_costs(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = compute_push_cost(a, len_a, len_b);
		a = a->next;
	}
}
