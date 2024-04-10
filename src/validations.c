/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:33:48 by hiono             #+#    #+#             */
/*   Updated: 2024/04/10 15:06:56 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
