#include "../include/push_swap.h"

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


static bool append_node(t_input_node **head, t_input_node *new_node)
{
    t_input_node    *current;

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
            break;
        current = current->next;
    }
    current->next = new_node;
    return (false);
}

static t_input_node *new_input_node(char *s, int len)
{
    char *temp;
    t_input_node *node;

    temp = strndup(s, len);
    if (!temp)
        return (NULL);
    node = create_node();
    if (!node)
    {
        free(temp);
        return (NULL);
    }
    node->string = temp;
    node->num = ft_atoi(temp);
    return (node);
}

static int get_word_length(char *s, char delimiter, bool *error)
{
    int i;

    i = 0;
    if (s[i] == '-' || s[i] == '+')
        i++;
    while (s[i] && s[i] != delimiter)
    {
        if(!ft_isdigit(s[i]))
        {
            *error = true;
            return (0);
        }
        i++;
    }
    *error = false;
    return (i);
}

static bool built_ll(t_input_node **head, char *s, char delimiter, int *input_num)
{
    int len;
    t_input_node    *node;
    bool error;


    while(*s)
    {
        while (*s == delimiter && *s)
            s++;
        if (*s)
        {  
            len = get_word_length(s, delimiter, &error);
            if (error)
                return (true);
            node = new_input_node(s, len);
            if(!node)
                return (true);
            if (append_node(head, node))
                return (true);
            s += len;
            (*input_num)++;   
        }
    }  
    return (false);
}

void free_ll(t_input_node *head) 
{
    t_input_node *temp;

    while (head)
    {
        temp = head;
        head = head->next;
        free(temp->string); 
        free(temp);
    }
}

t_input_node *str_to_ll(char *s, char delimiter, int *input_num)
{
    t_input_node *head;
    bool is_error;

    head = NULL;
    is_error = built_ll( &head, s, delimiter , input_num);
    if (is_error)
    {
        free_ll(head);
        return (NULL);
    }    
    return (head);
}