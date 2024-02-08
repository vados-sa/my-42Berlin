/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:15:48 by vados-sa          #+#    #+#             */
/*   Updated: 2024/02/08 14:01:09 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		new -> next = NULL;
	else
		new -> next = *lst;
	*lst = new;
}
/* 
t_list		*ft_lstnew(void *content);
int main(void)
{
    t_list *lst = NULL;

	t_list *node1 = ft_lstnew("Hello");
    t_list *node2 = ft_lstnew("World");
    t_list *node3 = ft_lstnew("!");

    ft_lstadd_front(&lst, node3);
    ft_lstadd_front(&lst, node2);
    ft_lstadd_front(&lst, node1);

    // Traverse the list and print the content of each node
    t_list *current = lst;
    while (current)
    {
        printf("%s ", (char *)current->content);
        current = current->next;
    }
    printf("\n");

    // Free the nodes to avoid memory leaks
	while (current)
	{
	    t_list *next = current->next;  // Store the next node before freeing
	    free(current->content);  // Free the content of the current node
	    free(current);          // Free the current node itself
	    current = next;         // Move to the next node
	}
	lst = NULL;  // Set lst to NULL to indicate an empty list

    return 0;
} */