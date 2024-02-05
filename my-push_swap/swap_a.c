#include "push_swap.h"
void    swap_a(t_list **head)
{
    t_list  *tmp_node;

    if (!*head || !(*head)->next)
        return ; //maybe exit?
    tmp_node = (*head)->next;
    (*head)->next = tmp_node->next;
    tmp_node->next = *head; 
}

/*In progress*/