/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:49:54 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/02/25 09:17:57 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

#include <stdio.h>

void	print_stack(t_stack_node *stack)
{
	while (stack)
	{
		printf("%d ", stack->nbr);
		stack = stack->next;
	}
	printf ("\n");
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
	if (argc < 2 || (argc == 2 && !argv[1][0]))
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	else if (argc == 2)
		list = str_to_ll(argv[1], ' ', &input_num);
	else
	{
		list = argv_to_ll(argv, argc);
		input_num = argc - 1;
	}
	if (!list)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	init_stack_a(&a, list);
	free_ll(list);
	if (!stack_sorted(a))
	{
        if (stack_len(a) == 2)
            sa(&a);
        // else if (stack_len(a) == 3)
        //     sort_three(&a);
    }
    pb(&b, &a);
    pb(&b, &a);
    print_stack(b);
	printf("Count:%d\n", stack_len(a));
	free_stack(&a);
	return (0);
}
