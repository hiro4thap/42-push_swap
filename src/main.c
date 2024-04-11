/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:24:40 by hiono             #+#    #+#             */
/*   Updated: 2024/04/11 18:11:22 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//TODO:delete before submission
void	print_stacks(t_stack *a, t_stack *b)
{
	int atop = a->top;
	ft_printf("---insides stacks---\n");
	ft_printf("a->top:%d\n", a->top);
	while (0 <= atop)
	{
		ft_printf("a->istack[%d]:%d\n", atop, a->istack[atop]);
		atop--;
	}
	int	btop = b->top;
	ft_printf("b->top:%d\n", b->top);
	while (0 <= btop)
	{
		ft_printf("b->istack[%d]:%d\n", btop ,b->istack[btop]);
		btop--;
	}
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

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	if (ac == 1)
		exit (1);
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
		exit(1);
	}
	a = init_sa(ac - 1, args);
	b = init_sb(ac - 1);
	//print_stacks(a, b);
	//ft_printf("---operations---\n");
	turk_sort(a, b);
	//print_stacks(a, b);
	free(a);
	free(b);
	if (ac == 2)
		free(args);
	return (1);
}
