/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:43:32 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/05 15:43:33 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (*b != cheap->target_node && *a != cheap)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rev_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (*b != cheap->target_node && *a != cheap)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest_node(*a);
	if (!cheapest_node)
		return ;
	if (*a == cheapest_node && *b == cheapest_node->target_node)
	{
		pb(b, a);
		return ;
	}
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_both(a, b, cheapest_node);
	cheap_to_top(a, cheapest_node, 'a');
	cheap_to_top(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	if (!b || !*b)
		return ;
	cheap_to_top(a, (*b)->target_node, 'a');
	pa(a, b);
}
