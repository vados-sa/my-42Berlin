/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:57:55 by vados-sa          #+#    #+#             */
/*   Updated: 2024/02/13 11:37:30 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>

typedef struct s_list
{
	int						value;
	struct s_list			*next;
}	t_list;

typedef struct s_stack
{
	t_list					*top;
}	t_stack;

/* Swap operations */
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	swap(t_stack *stack);

/* Push operations */
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_b, t_stack *stack_a);
void	push_from_to(t_stack *src_stack, t_stack *dest_stack, const char *opr);
void	push(t_stack *stack, t_list *element);
t_list	*pop(t_stack *stack);

/* Rotate operations */
void	rotate(t_stack *stack);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

/* Reverse rotate operations */
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif