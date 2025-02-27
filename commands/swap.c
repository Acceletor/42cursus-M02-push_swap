/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:49:34 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/02/20 14:49:35 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void swap(t_stack_node **head)
{
    t_stack_node *first;
    t_stack_node *second;

    if (!head || !*head || !(*head)->next)
        return ;
    first = *head;
    second = first->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->next = first;
    second->prev = NULL;
    first->prev = second;
    *head = second;
}

void sa(t_stack_node **a)
{
    swap(a);
    printf("sa\n");
}

void sb(t_stack_node **b)
{
    swap(b);
    printf("sb\n");
}

void ss(t_stack_node **a, t_stack_node **b)
{
    swap(a); 
    swap(b);
    printf("ss\n");
}
