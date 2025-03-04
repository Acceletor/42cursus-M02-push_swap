/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:49:54 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/04 09:05:40 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"


void	print_stack(t_stack_node *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		ft_printf("%d ", stack->nbr);
		stack = stack->next;
	}
	ft_printf ("\n");
}

t_input_node	*parse_input(int argc, char **argv, int *input_num)
{
	t_input_node	*list;

	list = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (NULL);
	if (argc == 2)
		list = str_to_ll(argv[1], ' ', input_num);
	else
	{
		list = argv_to_ll(argv, argc);
		*input_num = argc - 1;
	}
	return (list);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node *b;
	t_input_node	*list;
	int				input_num;
	a = NULL;
    b = NULL;

	input_num = 0;
	list = parse_input(argc, argv, &input_num);
	if (!list)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	init_stack_a(&a, list);
	free_ll(&list);
	if (!stack_sorted_ascend(a))
		sort_stacks(&a, &b);
    // print_stack(a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
