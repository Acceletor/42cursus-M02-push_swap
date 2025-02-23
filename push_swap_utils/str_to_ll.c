#include "../include/push_swap.h"

//Detemines the length of the current word and validates that
// all characters (except an optional sign) are digits.
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

// Iterates through the input string to build the linked list
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

// The top‑level function that ties everything together
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