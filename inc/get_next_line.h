/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:04:42 by hiono             #+#    #+#             */
/*   Updated: 2024/04/12 19:04:52 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

size_t	gnl_ft_strlen(const char *str);
char	*gnl_ft_substr(char const *s, unsigned int start, size_t len);
char	*gnl_ft_strjoin(char *s1, char const *s2);
char	*gnl_ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif
