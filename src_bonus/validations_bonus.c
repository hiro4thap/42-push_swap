/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:33:48 by hiono             #+#    #+#             */
/*   Updated: 2024/04/12 19:15:13 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

static int	is_str_int(char *str)
{
	int		i;
	char	*istr;

	i = ft_atoi(str);
	istr = ft_itoa(i);
	if (ft_strncmp(str, istr, ft_strlen(str)))
		return (0);
	return (1);
}

static int	is_str_number(char *str)
{
	if (*str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_args_int(int len, char **args)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (!is_str_number(args[i]) || !is_str_int(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_args_unique(int len, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_inst(char *inst)
{
	if (!ft_strncmp(inst, "pa\n", 4)
			|| !ft_strncmp(inst, "pb\n", 4)
			|| !ft_strncmp(inst, "sa\n", 4)
			|| !ft_strncmp(inst, "sb\n", 4)
			|| !ft_strncmp(inst, "ss\n", 4)
			|| !ft_strncmp(inst, "ra\n", 4)
			|| !ft_strncmp(inst, "rb\n", 4)
			|| !ft_strncmp(inst, "rr\n", 4)
			|| !ft_strncmp(inst, "rra\n", 5)
			|| !ft_strncmp(inst, "rrb\n", 5)
			|| !ft_strncmp(inst, "rrr\n", 5))
		return (1);
	return (0);
}
