/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:24:40 by hiono             #+#    #+#             */
/*   Updated: 2024/04/12 19:17:29 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	display_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

int	get_ac(char **args)
{
	int	i;

	i = 1;
	while (*args)
	{
		args++;
		i++;
	}
	return (i);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	free(a);
	free(b);
}

void	free_args(int ac, char **args)
{
	int	i;

	if (ac != 2)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	execute_inst(t_stack *a, t_stack *b, char *inst)
{
	if (!ft_strncmp(inst, "pa\n", 3))
		pa(a, b);
	else if (!ft_strncmp(inst, "pb\n", 3))
		pb(b,a );
	else if (!ft_strncmp(inst, "sa\n", 3))
		sa(a);
	else if (!ft_strncmp(inst, "sb\n", 3))
		sb(b);
	else if (!ft_strncmp(inst, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(inst, "ra\n", 3))
		ra(a);
	else if (!ft_strncmp(inst, "rb\n", 3))
		rb(b);
	else if (!ft_strncmp(inst, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(inst, "rra\n", 4))
		rra(a);
	else if (!ft_strncmp(inst, "rrb\n", 4))
		rrb(b);
	else if (!ft_strncmp(inst, "rrr\n", 4))
		rrr(a, b);
}

int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->top)
	{
		if (s->istk[i] < s->istk[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	char	*inst;

	if (ac == 1)
		return (1);
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		ac = get_ac(args);
	}
	else
		args = &av[1];
	if (!is_args_int(ac - 1, args) || !is_args_unique(ac - 1, args))
	{
		display_error("Error\n");
		free_args(ac, args);
	}
	a = init_sa(ac - 1, args);
	b = init_sb(ac - 1);
	while (1)
	{
		inst = get_next_line(0);
		if (!inst)
			break ;
		if (!is_valid_inst(inst))
		{
			display_error("Error\n");
			free(inst);
			free_stacks(a, b);
			free_args(ac, args);
			return (1);
		}
		execute_inst(a, b, inst);
	}
	if (is_sorted(a) && b->top == -1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(a, b);
	free_args(ac, args);
	return (1);
}
