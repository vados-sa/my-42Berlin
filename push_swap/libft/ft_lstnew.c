/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:42:31 by vados-sa          #+#    #+#             */
/*   Updated: 2024/02/03 17:16:46 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node -> content = content;
	new_node -> next = NULL;
	return (new_node);
}
/* int    main(void)
{
   int	data_int = 42;
   char	*data_str = "Linked lists";

   t_list *node_int = ft_lstnew(&data_int);
   if (!node_int)
   {
	printf("Error allocating memory for node_int\n");
	return (1);
   }
   printf("Integer node content: %d\n", *(int*)node_int->content);
   t_list *node_str = ft_lstnew(data_str);
   if (node_str == NULL)
   {
	printf("Error allocating memory for node_str\n");
	return (1);
   }
   printf("String node content: %s\n", (char*)node_str->content);
   free(node_int);
   free(node_str);
} */