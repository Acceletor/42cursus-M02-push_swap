/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:49:43 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/02/20 14:49:44 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void rev_rotate(t_stack_node **head)
{
    t_stack_node *last_node;

    if (!(*head) || !(*head)->next)
        return ;
    last_node = find_last_node(*head);

    if(last_node->prev)
        last_node->prev->next = NULL;

    last_node->next = *head;
    (*head)->prev = last_node;
    last_node->prev = NULL;

    *head = last_node;
}

void rra(t_stack_node **a)
{
    rev_rotate(a);
    printf("rra\n");
}

void rrb(t_stack_node **b)
{
    rev_rotate(b);
    printf("rrb\n");
}

void rrr(t_stack_node **a, t_stack_node **b)
{
    rev_rotate(a);
    rev_rotate(b);
    printf("rrr\n");
}