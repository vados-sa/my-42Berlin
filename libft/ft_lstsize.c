/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:59:10 by vados-sa          #+#    #+#             */
/*   Updated: 2024/02/03 19:15:33 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current;

	i = 0;
	current = lst;
	while (current)
	{
		current = current -> next;
		i++;
	}
	return (i);
}
/* 
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);

int main(void)
{
	t_list *lst = NULL;

	t_list *node1 = ft_lstnew("Hello");
	t_list *node2 = ft_lstnew("World");
	t_list *node3 = ft_lstnew("!");
	ft_lstadd_front(&lst, node3);
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node1);

	printf("%d\n", ft_lstsize(lst));

	// Free the nodes to avoid memory leaks
	while (lst)
	{
		t_list *next = lst->next;
		free(lst);
		lst = next;
	} 
	return (0);
} */
