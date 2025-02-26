/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:31:59 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/02/25 09:19:27 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//allocates and intialize a new node
t_input_node	*create_node(void)
{
	t_input_node	*new_node;

	new_node = (t_input_node *)malloc(sizeof(t_input_node));
	if (!new_node)
		return (NULL);
	new_node->string = NULL;
	new_node->num = 0;
	new_node->next = NULL;
	return (new_node);
}

//duplicate substring
char	*ft_strndup(char *s, int len)
{
	char	*des;
	int		i;

	des = malloc(len + 1);
	if (des == 0)
		return (0);
	i = 0;
	while (i < len && s[i])
	{
		des[i] = s[i];
		i++;
	}
	des[i] = '\0';
	return (des);
}

//Appends a node to the list while checking for duplicates.
bool	append_node(t_input_node **head, t_input_node *new_node)
{
	t_input_node	*current;

	if (*head == NULL)
	{
		*head = new_node;
		return (false);
	}
	current = *head;
	while (current)
	{
		if (current->num == new_node->num)
		{
			free(new_node->string);
			free(new_node);
			return (true);
		}
		if (current->next == NULL)
			break ;
		current = current->next;
	}
	current->next = new_node;
	return (false);
}

//Creates a node from a substring by combining node
t_input_node	*new_input_node(char *s, int len)
{
	char			*temp;
	t_input_node	*node;
	int 			num;
	bool			valid;

	temp = ft_strndup(s, len);
	if (!temp)
		return (NULL);
	node = create_node();
	if (!node)
	{
		free(temp);
		return (NULL);
	}
	node->string = temp;
	valid = atoi_edgecase(temp, &num);
	if (!valid)
	{
		free(temp);
		free(node);
		return (NULL);
	}
	node->num = num;
	return (node);
}

//Frees the entire linked list.
void	free_ll(t_input_node **head)
{
	t_input_node	*temp;

	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp->string);
		free(temp);
	}
	*head = NULL;
}
