/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:57:55 by vados-sa          #+#    #+#             */
/*   Updated: 2024/02/13 14:53:27 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

/*Check if I could use <limits.h>*/
/* # ifndef INT_MAX
#  define INT_MAX '2147483647' 
# endif

# ifndef INT_MIN
#  define INT_MIN '-2147483648'
# endif*/
 
typedef struct s_node
{
	int						value;
	struct s_node			*next;
}	t_node;

typedef struct s_stack
{
	t_node					*top;
}	t_stack;

/* swap.c */
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	swap(t_stack *stack);

/* push.c */
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_b, t_stack *stack_a);
void	push_from_to(t_stack *src_stack, t_stack *dest_stack, const char *opr);
void	push(t_stack *stack, t_list *element);
t_list	*pop(t_stack *stack);

/* rotate.c */
void	rotate(t_stack *stack);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

/* reverse_rotate.c */
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif