/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanessasantos <vanessasantos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:57:55 by vados-sa          #+#    #+#             */
/*   Updated: 2024/02/21 14:39:00 by vanessasant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

#ifndef INT_MIN
#define INT_MIN (-INT_MAX - 1)
#endif

/*Define the node structure*/ 
typedef struct s_node
{
	int						value;
	struct s_node			*next;
}	t_node;

/*Define the stack structure*/
typedef struct s_stack
{
	t_node					*top;
}	t_stack;

/*stack_utils.c*/
void	init_stack(t_stack **a, char **av, bool flag_ac_2);
void    add_to_stack(t_stack *a, int nbr);
int		stack_sorted(t_stack *a);
int		stack_len(t_stack *stack);

/*error_manage.c*/
void	error_exit(t_stack **a, char **av, bool flag_ac_2);
void    free_stack(t_stack **a);
void    free_split_av(char **av);
int	    check_syntax(char *av);
int     check_duplicates(t_stack **a, int nbr);

/* swap.c */
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	swap(t_stack *stack);

/* push.c */
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_b, t_stack *stack_a);
void	push_from_to(t_stack *src_stack, t_stack *dest_stack, const char *opr);
void	push(t_stack *stack, t_node *element);
t_node	*pop(t_stack *stack);

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