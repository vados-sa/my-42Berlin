/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:42:31 by vados-sa          #+#    #+#             */
/*   Updated: 2023/12/04 11:27:09 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
    t_list  *new_elem;
    
    new_elem = malloc(sizeof(t_list));
    if (!new_elem)
        return (NULL);
    new_elem -> content = content;
    new_elem -> next = NULL;
    return (new_elem);
}
/* int    main(void)
{
    char    *str;

    t_list    *elem;
    str = (char *)malloc(6*sizeof(char));
    if (!str)
        return (1);
    str = "Hello";
    elem = ft_lstnew((void *)str);
    printf("%s\n", (char *)elem->content);
    free(elem->content);
    free(elem);
    return (0);
} */