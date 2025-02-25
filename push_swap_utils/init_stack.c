/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:31:55 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/02/25 08:40:46 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void	append_stack_node(t_stack_node **stack, int num)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->nbr = num;
    new_node->cheapest = 0;
    if (!(*stack))
        *stack = new_node; 
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
