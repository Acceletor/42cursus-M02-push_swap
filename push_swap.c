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

void	print_list(int *l, int num)
{
    int i;

    i = 0;
	while (i < num)
	{
		printf("%d ", l[i]);
		i++;
	}
    printf("\n");
}

int *create_int_list(t_input_node *head, int num)
{
    int *des;
    int i;

    i = 0;
    des = malloc(sizeof(int) * num);
    if (!des)
        return (NULL);
    while(i < num)
    {
        des[i] = head->num;
        head = head->next;
        i++;
    }
    return (des);
}

int main(int argc, char **argv)
{
    // t_stack_node *a;
    // t_stack_node *b;
    t_input_node *list;
    int  input_num;
    int  *result;
    // a = NULL;
    // b = NULL;

    input_num = 0;
    if(argc < 2 || (argc == 2 && !argv[1][0]))
    {
        ft_putstr_fd("Error\n", 1);
        return (1);
    }    
    else if (argc == 2)
        list = str_to_ll(argv[1], ' ', &input_num);
    else
    {
        list= argv_to_ll(argv, argc);
        input_num = argc - 1;
    }
    if (!list)
    {
        ft_putstr_fd("Error\n", 1); 
        return (1);
    }
    result = create_int_list(list, input_num);
    free_ll(list);
    if (!result)
        return (1);
    print_list(result, input_num);
    free(result);
    return (0);
}
