#include "../include/push_swap.h"

t_stack_node *find_last_node(t_stack_node *node)
{
    if (!node)
        return (NULL);
    while(node->next)
        node = node->next;
    return (node); 
}

void append_stack_node(t_stack_node **stack, int num)
{
    t_stack_node *new_node;
    t_stack_node *last_node;

    if (!stack)
        return ;
    new_node = malloc(sizeof(t_stack_node));
    if (!new_node)
        return ;
    new_node->next = NULL;
    new_node->nbr = num;
    new_node->cheapest = 0;
    if (!(*stack))
    {
        *stack = new_node;
        new_node->prev = NULL;
    }
    else
    {
        last_node = find_last_node(*stack);
        last_node->next = new_node;
        new_node->prev = last_node;
    }
}

void init_stack_a(t_stack_node **a, t_input_node *list)
{
    if (!a || !list)
        return ;
    while (list)
    {
        append_stack_node(a, list->num);
        list = list->next;
    }
}