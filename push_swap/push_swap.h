
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

/*Node structure*/ 
typedef struct s_node
{
	int						value;
	int						index;
	int						push_price;
	bool					above_median;
	bool					cheapest;
	struct s_node			*target_node;
	struct s_node			*next;
}	t_node;

/*Stack structure*/
typedef struct s_stack
{
	t_node					*top;
}	t_stack;

/* swap.c */
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

/* push.c */
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_b, t_stack *stack_a);

/* rotate.c */
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

/* reverse_rotate.c */
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/*stack_utils.c*/
void	init_stack(t_stack **a, char **av, bool flag_ac_2);
void	add_to_stack(t_stack *a, int nbr);
int		stack_sorted(t_stack *a);
int		stack_len(t_stack *stack);

/*error_manage.c*/
void	error_exit(t_stack **a, char **av, bool flag_ac_2);
void	free_stack(t_stack **a);
void	free_split_av(char **av);
int		check_syntax(char *av);
int		check_duplicates(t_stack **a, int nbr);

/*algorithms.c*/
void	sort_three(t_stack *a);
void	big_sort(t_stack **a, t_stack **b);

/*algorithm_utils.c*/
void	find_index(t_stack *stack);
void	set_cheapest(t_stack *stack);
t_node	*find_max(t_stack *stack);
t_node	*get_cheapest(t_stack *stack);

/*init_a_for_pb.c*/
void	init_nodes_a(t_stack **a, t_stack **b);
void	set_target_for_a(t_stack *a, t_stack *b); // might be set to static
void	push_cost_analisys_a(t_stack *a, t_stack *b); // might be set to static

/*prep_push_utils.c*/
void	push_cheapest_a(t_stack **a, t_stack **b);
//void	push_cheapest_b(t_stack *b, t_stack *a);
void	rotate_both(t_stack **a, t_stack **b, t_node *cheapest);
void	rev_rotate_both(t_stack **a, t_stack **b, t_node *cheapest);
void	prep_push(t_stack **stack, t_node *cheapest, char stack_name);

void	print_stack(t_stack *stack, char stack_name); // remember to take this out

#endif