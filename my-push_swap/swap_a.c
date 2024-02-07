#include "push_swap.h"
void    swap(t_list **head)
{
    t_list  *tmp_node;

    if (!*head || !(*head)->next)
        return ;
    tmp_node = (*head)->next;
    (*head)->next = tmp_node->next;
    tmp_node->next = *head;
    *head = tmp_node;
}

/*In progress*/