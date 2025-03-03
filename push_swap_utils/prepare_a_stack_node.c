#include "../include/push_swap.h"

void current_index(t_stack_node *stack)
{
    int i;
    int median;

    i = 0;
    if (!stack)
        return ;
    median = stack_len(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->above_median = true;
        else   
            stack->above_median = false;
        stack = stack->next;
        i++;
    }
}

static void set_target_for_a(t_stack_node *a, t_stack_node *b)
{
    t_stack_node 	*target_node;
	t_stack_node	*current_b;
    long			best_match_number;

	while (a)
	{
		best_match_number = LONG_MIN;
		current_b = b;
		target_node = NULL;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match_number)
			{
				best_match_number = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_number == LONG_MIN) 
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void calculate_push_costs(t_stack_node *a, t_stack_node *b)
{
	int len_a;
	int len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		if (a->above_median)
            a->push_cost = a->index;
        else
            a->push_cost = len_a - a->index;
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

static void set_cheapest(t_stack_node *stack)
{
	long cheapest_value;
	t_stack_node *cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	cheapest_node = stack;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

void prepare_a_stack_node(t_stack_node *a, t_stack_node *b)
{
    current_index(a);
    current_index(b);
	set_target_for_a(a, b);
	calculate_push_costs(a, b);
	set_cheapest(a);
}