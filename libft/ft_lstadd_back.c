/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:47:44 by vados-sa          #+#    #+#             */
/*   Updated: 2024/02/03 19:14:20 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last -> next = new;
}
/* int main(void)
{
    t_list *lst = NULL;

	t_list *node1 = ft_lstnew("Hello");
    t_list *node2 = ft_lstnew("World");
    t_list *node3 = ft_lstnew("!");

    ft_lstadd_back(&lst, node1);
    ft_lstadd_back(&lst, node2);
    ft_lstadd_back(&lst, node3);

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