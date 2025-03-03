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

static void move_a_to_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest_node;

    cheapest_node = get_cheapest_node(*a);
	if (!cheapest_node)
        return ;
	if (*a == cheapest_node && *b == cheapest_node->target_node)
	{
		pb(b, a); // If both are already at the top, just push
		return;
	}
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a,b,cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		rev_rotate_both(a,b,cheapest_node);
	cheap_to_top(a,cheapest_node, 'a');
	cheap_to_top(b,cheapest_node->target_node, 'b');
	pb(b,a);
}

static void move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	if (!b || !*b) 
        return;
    if ((*b)->target_node) 
	{
		cheap_to_top(a, (*b)->target_node, 'a');
	}
    cheap_to_top(b, *b, 'b'); 
    pa(a, b);
}

#include <stdio.h>
void print_stack_test(t_stack_node *stack, char stack_name)
{
    printf("Stack %c:\n", stack_name);
    printf("------------------------------------------------------\n");
    printf("|  Nbr  | Index | Push Cost | Target_node | Cheapest |\n");
    printf("------------------------------------------------------\n");

    while (stack)
    {
        printf("| %5d | %5d | %9d | %12d | %8s |\n",
               stack->nbr,
               stack->index,
               stack->push_cost,
               stack->target_node ? stack->target_node->nbr : 0,
               stack->cheapest ? "Yes" : "No");
        stack = stack->next;
    }
    printf("------------------------------------------------------\n");
}

void sort_small(t_stack_node **a, t_stack_node **b)
{
    int len;

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


void sort_stacks(t_stack_node **a, t_stack_node **b)
{
    int len_a;

    len_a = stack_len(*a);
	if (len_a < 6)
	{
		sort_small(a, b);
		return;
	}
	while (stack_len(*b) < 3  && !stack_sorted_ascend(*a))
        pb(b,a);
    if (!stack_sorted_descend(*b))
        sort_three_b(b);
	len_a = len_a - 3;
	while (len_a-- > 3 && !stack_sorted_ascend(*a))
	{
		prepare_a_stack_node(*a,*b);
		move_a_to_b(a,b);
	}
	sort_three_a(a);
	while (*b)
	{
		prepare_b_stack_node(*b, *a);
		move_b_to_a(a, b);
	}
	cheap_to_top(a, find_min(*a), 'a');
}
