/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:45:13 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/07 15:59:57 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap/push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
void	apply_instructions(char *instruct, t_stack *a, t_stack *b);
void	init_b(t_stack **b, t_stack **a);
void	checker(t_stack *a, t_stack *b);

#endif
