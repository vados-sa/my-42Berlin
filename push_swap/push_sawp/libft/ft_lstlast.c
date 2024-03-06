/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:26:49 by vados-sa          #+#    #+#             */
/*   Updated: 2024/02/04 17:50:41 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current_node;

	if (!lst)
		return (NULL);
	current_node = lst;
	while (current_node -> next)
		current_node = current_node -> next;
	return (current_node);
}
/* 
int main(void)
{
	t_list *lst = NULL;

	// Create a list with multiple nodes
	ft_lstadd_front(&lst, ft_lstnew("!"));
	ft_lstadd_front(&lst, ft_lstnew("World"));
	ft_lstadd_front(&lst, ft_lstnew("Hello"));

	// Get the last node
	t_list *last_node = ft_lstlast(lst);

	// Print the content of the last node
	if (last_node)
	{
		printf("Last node content: %s\n", (char *)last_node->content);
	}
	else
	{
		printf("List is empty.\n");
	}
	// Free the nodes to avoid memory leaks
	while (lst)
	{
		t_list *next = lst->next;
		free(lst);
		lst = next;
	}
	return 0;
} */