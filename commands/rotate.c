/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:49:41 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/01 08:56:19 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack_node **head)
{
	t_stack_node	*old_head;
	t_stack_node	*last_node;

	if (!head || !(*head) || !(*head)->next)
		return ;
	old_head = *head;
	*head = old_head->next;
	(*head)->prev = NULL;
	last_node = find_last_node(*head);
	last_node->next = old_head;
	old_head->prev = last_node;
	old_head->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
