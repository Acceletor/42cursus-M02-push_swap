/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:49:41 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/02/20 14:49:42 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void rotate(t_stack_node **head)
{
    t_stack_node *last_node;

    if(!(*head) || !(*head)->next)
        return ;
    last_node = find_last_node(*head);
    last_node->next = *head;
    *head = (*head)->next;
    last_node->next->prev = last_node;
    (*head)->prev = NULL;
    last_node->next->next = NULL;
}

void ra(t_stack_node **a)
{
    rotate(a);
    printf("ra\n");
}

void rb(t_stack_node **b)
{
    rotate(b);
    printf("rb\n");
}

void rr(t_stack_node **a, t_stack_node **b)
{
    rotate(a);
    rotate(b);
    printf("rr\n");
}