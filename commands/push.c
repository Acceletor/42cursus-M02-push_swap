/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:49:46 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/01 08:52:05 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*temp;

	if (!(*src))
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (*dest)
	{
		(*dest)->prev = temp;
		temp->next = *dest;
	}
	else
		temp->next = NULL;
	*dest = temp;
	(*dest)->prev = NULL;
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	ft_printf("pb\n");
}
