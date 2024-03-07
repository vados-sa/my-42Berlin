
#include "checker.h"

static void	apply_instructions(char *instruct, t_stack *a, t_stack *b);
static void	init_b(t_stack **b, t_stack **a);
static int	ft_strcmp(char *str_1, char *str_2);
static void	error(t_stack **a, t_stack **b);

static void	error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);

}

static void	init_b(t_stack **b, t_stack **a)
{
	*b = malloc(sizeof(t_stack));
	if (!*b)
		error(a, b);
	(*b)->top = NULL;
}

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2
		&& *s1)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

static void	apply_instructions(char *instruct, t_stack *a, t_stack *b)
{
	if (ft_strcmp(instruct, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(instruct, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(instruct, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(instruct, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(instruct, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(instruct, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(instruct, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(instruct, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(instruct, "rrr\n") == 0)
		rrr(a, b);
	else if (ft_strcmp(instruct, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(instruct, "pb\n") == 0)
		pb(b, a);
	else
		error(&a, &b);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	char	*instruction;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack(&a, av + 1, ac == 2);
	init_b(&b, &a);
	while ((instruction = get_next_line(0)))
	{
		apply_instructions(instruction, a, b);
		free (instruction);
	}
	if (stack_sorted(a) && b->top == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
