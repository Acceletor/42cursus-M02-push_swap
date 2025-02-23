/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:49:54 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/02/20 14:49:55 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

#include <stdio.h>

void	print_list(t_input_node *head)
{
	while (head)
	{
		printf("String: %s, Num: %d\n", head->string, head->num);
		head = head->next;
	}
}

int main(int argc, char **argv)
{
    // t_stack_node *a;
    // t_stack_node *b;
    t_input_node *list;
    size_t  input_num;
    // a = NULL;
    // b = NULL;

    input_num = 0;
    if(argc < 2 || (argc == 2 && !argv[1][0]))
    {
        ft_putstr_fd("Error\n", 1);
        return (1);
    }    
    else if (argc == 2)
    {
        list = str_to_ll(argv[1], ' ', &input_num);
        if (list)
        {
            printf("Valid input: \n");
            print_list(list);
            free_ll(list);
            printf("%zu\n", input_num);
        }
        else
            ft_putstr_fd("Error\n", 1);  
    }
        
    return (0);
}
