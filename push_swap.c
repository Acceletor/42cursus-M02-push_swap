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
	free_ll(&list);
	if (!stack_sorted_ascend(a))
	{
        if (stack_len(a) == 2)
            sa(&a);
        else if (stack_len(a) == 3)
            sort_three_a(&a);
		else
			sort_stacks(&a,&b);
    }
	ft_printf("A: ");
    print_stack(a);
	ft_printf("B: ");
    print_stack(b);
	ft_printf("Count:%d\n", stack_len(a));
	free_stack(&a);
	free_stack(&b);
	return (0);
}
