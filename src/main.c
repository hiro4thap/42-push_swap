/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:24:40 by hiono             #+#    #+#             */
/*   Updated: 2024/04/13 15:44:50 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

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
		ft_printf("Error\n");
		free_args(ac, args);
		return (1);
	}
	a = init_sa(ac - 1, args);
	b = init_sb(ac - 1);
	turk_sort(a, b);
	free_stacks(a, b);
	free_args(ac, args);
	return (1);
}
