/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:29:36 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/05 15:47:57 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h> //MIN and MAX
# include <stdbool.h> //To use bool flag
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

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
	char				*string;
	int					num;
	struct s_input_node	*next;
}	t_input_node;

// handle string input to ll
t_input_node	*str_to_ll(char *s, char delimiter, int *input_num);
void			free_ll(t_input_node **head);
t_input_node	*create_node(void);
char			*ft_strndup(char *s, int len);
bool			append_node(t_input_node **head, t_input_node *new_node);
t_input_node	*new_input_node(char *s, int len);

// handle argv input
t_input_node	*argv_to_ll(char **argv, int argc);

//atoi fuction
bool			atoi_edgecase(const char *str, int *num);

//Stack initialize
void			append_stack_node(t_stack_node **stack, int num);
void			init_stack_a(t_stack_node **a, t_input_node *list);

//Stack utils
t_stack_node	*find_last_node(t_stack_node *node);
int				stack_len(t_stack_node *stack);
void			free_stack(t_stack_node **head);
t_stack_node	*find_min(t_stack_node *a);
t_stack_node	*find_max(t_stack_node *a);

//sort stack 
bool			stack_sorted_ascend(t_stack_node *stack);
bool			stack_sorted_descend(t_stack_node *stack);
t_stack_node	*get_cheapest_node(t_stack_node *stack);
void			current_index(t_stack_node *stack);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);
void			move_b_to_a(t_stack_node **a, t_stack_node **b);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			cheap_to_top(t_stack_node **s, t_stack_node *cheap, char name);

//swap instruction
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

//rotate instruction
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

//reverse rotate instruction
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

//push instruction
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

//sort_three
void			sort_three_a(t_stack_node **a);
void			sort_three_b(t_stack_node **b);

//prepare and move from one stack to another
void			calculate_push_costs(t_stack_node *a, t_stack_node *b);
void			prepare_a_stack_node(t_stack_node *a, t_stack_node *b);
void			prepare_b_stack_node(t_stack_node *b, t_stack_node *a);

#endif