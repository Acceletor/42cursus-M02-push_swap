/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:29:36 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/02/20 15:06:48 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h> //MIN and MAX
# include <stdbool.h> //To use bool flag
# include "../libft/libft.h" 

typedef struct s_stack_node
{
	int					nbr;
	int					index; // number's position in the stack
	int					push_cost; //total command
	bool				above_median; // decide whether to rr- or r-
	bool				cheapest; //the node have the least command
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_input_node
{
	char	*string;
	int		num;
	struct s_input_node *next;
}	t_input_node;

// handle input
t_input_node *str_to_ll(char *s, char delimiter, int *input_num);
void free_ll(t_input_node *head);

#endif