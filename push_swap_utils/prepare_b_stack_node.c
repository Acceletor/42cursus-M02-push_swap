#include "../include/push_swap.h"

static void set_target_b(t_stack_node *b, t_stack_node *a)
{
    t_stack_node *current_a;
    t_stack_node *target_node;
    long best_match_number;

    while (b)
    {
        best_match_number = LONG_MAX;
        current_a = a;
        while (current_a)
        {
            if (current_a->nbr > b->nbr && current_a->nbr < best_match_number)
			{
				best_match_number = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
        }
        if (best_match_number == LONG_MAX) 
			b->target_node = find_max(a);
        else
            b->target_node = target_node;
        b = b->next;
    }
}

void prepare_b_stack_node(t_stack_node *b, t_stack_node *a)
{
    current_index(b);
    current_index(a);
    set_target_b(b,a);
}
