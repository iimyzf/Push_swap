/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:07:59 by yagnaou           #+#    #+#             */
/*   Updated: 2021/12/07 01:24:19 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	s1len;
	size_t	i;
	char	*str;

	i = 0;
	s1len = ft_strlen(s1);
	str = (char *) malloc(sizeof(char) * s1len + 1);
	if (!str)
		return (NULL);
	while (s1[i] && i < s1len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 && s2)
		return (ft_strdup(s2));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	joined = (char *) malloc(sizeof(char) * (s1len + s2len + 1));
	if (!joined)
		return (NULL);
	i = -1;
	while (++i < s1len)
		joined[i] = s1[i];
	while (i < s1len + s2len)
	{
		joined[i] = s2[i - s1len];
		i++;
	}
	joined[i] = '\0';
	return (joined);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
