/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:06:14 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/01 09:06:15 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while(*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a,b);
	current_index(*a);
	current_index(*b);
}

static void rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while(*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a,b);
	current_index(*a);
	current_index(*b);
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

// static void move_b_to_a(t_stack_node **a, t_stack_node **b)
// {
//     t_stack_node *max_node;

//     while (*b)
//     {
//         max_node = find_max(*b);
//         cheap_to_top(b, max_node, 'b');
//         pa(a, b);
//     }
// }


static void move_a_to_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest_node;

    cheapest_node = get_cheapest_node(*a);
	if (!cheapest_node)
        return ;
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a,b,cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		rev_rotate_both(a,b,cheapest_node);
	cheap_to_top(a,cheapest_node, 'a');
	cheap_to_top(b,cheapest_node->target_node, 'b');
	
	pb(b,a);
}


void sort_stacks(t_stack_node **a, t_stack_node **b)
{
    int len_a;
    len_a = stack_len(*a);
    while (stack_len(*b) < 3  && !stack_sorted_ascend(*a))
    {
        pb(b,a);
    }    
    if (!stack_sorted_descend(*b))
        sort_three_b(b);
	len_a = len_a - 3;
	while (len_a-- > 3 && !stack_sorted_ascend(*a))
	{
		prepare_stack_node(*a,*b);
		move_a_to_b(a,b);
	}
	// sort_three_a(a);
	// while (*b)
	// {
	// 	prepare_stack_node(*a, *b);
	// 	move_b_to_a(a, b);
	// }
	
}
