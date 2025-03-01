/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:49:37 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/01 09:00:21 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack_node	*find_min(t_stack_node *a)
{
	t_stack_node	*min_node;

	if (!a)
		return (NULL);
	min_node = a;
	while (a->next)
	{
		if (min_node->nbr > a->nbr)
			min_node = a;
		a = a->next;
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *a)
{
	t_stack_node	*max_node;

	if (!a)
		return (NULL);
	max_node = a;
	while (a)
	{
		if (max_node->nbr < a->nbr)
			max_node = a;
		a = a->next;
	}
	return (max_node);
}

void	sort_three_a(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	if (stack_sorted_ascend(*a))
		return ;
	biggest_node = find_max(*a);
	if ((*a) == biggest_node)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->next->nbr < (*a)->nbr)
		sa(a);
}

void	sort_three_b(t_stack_node **b)
{
	t_stack_node	*smallest_node;

	if (stack_sorted_descend(*b))
		return ;
	smallest_node = find_min(*b);
	if ((*b) == smallest_node)
		rb(b);
	else if ((*b)->next == smallest_node)
		rrb(b);
	if ((*b)->next->nbr > (*b)->nbr)
		sb(b);
}
