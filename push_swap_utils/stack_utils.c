/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:32:04 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/02/25 08:46:33 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack_node *find_last_node(t_stack_node *node)
{
    if (!node)
        return (NULL);
    while(node->next)
        node = node->next;
    return (node); 
}

int stack_len(t_stack_node *stack)
{
    int count;

    if (!stack)
        return (0);
    count = 0;    
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}

bool stack_sorted(t_stack_node *stack)
{
    if (!stack)
        return (1);
    while(stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return (false);
        stack = stack->next;
    }
    return (true);
}

// void free_stack
void free_stack(t_stack_node *head) 
{
    t_stack_node *temp;

    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}