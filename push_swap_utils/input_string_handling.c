#include "../include/push_swap.h"

// int word_count (char* s, char delimiter)
// {

// };

static t_input_node *create_node(void)
{
    t_input_node *new_node;

    new_node = (t_input_node *)malloc(sizeof(t_input_node));
    if (!new_node)
        return (NULL);
    new_node->string = NULL;
    new_node->num = 0;
    new_node->next = NULL;
    return (new_node);
}

static char	*strndup(char *s, int len)
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

static void append_node(t_input_node **head, t_input_node *new_node)
{
    t_input_node    *current;

    if (*head == NULL)
        *head = new_node;
    else
    {
        current = *head;
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
}

static void built_list(t_input_node **head, char* s, char delimiter)
{
    int i;
    char *temp;
    t_input_node    *new_node;

    while(*s)
    {
        while (*s == delimiter && *s) // skip delemiter
            s++;
        if (*s)
        {
            i = 0;
            while (s[i] != delimiter && s[i]) // find word length
                i++;
            temp = strndup(s, i); //Extract the word
            new_node = create_node();
            if (!new_node)
                return ;
            new_node->string = temp;
            new_node->num = ft_atoi(temp);
            append_node(head, new_node);
            s += i;   
        }
    }   
}


t_input_node *str_to_list(char *s, char delimiter)
{
    t_input_node *head;

    head = NULL;
    built_list( &head, s, delimiter);
    return (head);
}