/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:06:14 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/05 15:46:32 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_small(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = stack_len(*a);
	if (len == 2)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a);
	}
	else if (len == 3)
		sort_three_a(a);
	else if (len == 4 || len == 5)
	{
		while (stack_len(*a) > 3)
		{
			current_index(*a);
			cheap_to_top(a, find_min(*a), 'a');
			pb(b, a);
		}
		sort_three_a(a);
		while (*b)
			pa(a, b);
		cheap_to_top(a, find_min(*a), 'a');
	}
}

static void	sort_large_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	while (stack_len(*b) < 3 && !stack_sorted_ascend(*a))
		pb(b, a);
	if (!stack_sorted_descend(*b))
	{
		sort_three_b(b);
	}
	len_a = stack_len(*a);
	while (len_a-- > 3 && !stack_sorted_ascend(*a))
	{
		prepare_a_stack_node(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three_a(a);
	while (*b)
	{
		prepare_b_stack_node(*b, *a);
		move_b_to_a(a, b);
	}
	cheap_to_top(a, find_min(*a), 'a');
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a < 6)
	{
		sort_small(a, b);
		return ;
	}
	sort_large_stacks(a, b);
}
