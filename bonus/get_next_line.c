/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:20:18 by yagnaou           #+#    #+#             */
/*   Updated: 2022/04/15 02:29:12 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_newline_inbuffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_switch_left(char *buffer)
{
	int	i;
	int	j;

	if (ft_newline_inbuffer(buffer))
	{
		i = 0;
		while (buffer[i] != '\n')
			i++;
		i += 1;
		j = 0;
		while (buffer[i])
			buffer[j++] = buffer[i++];
		while (buffer[j])
			buffer[j++] = 0;
	}
	else
		ft_bzero(buffer, 1);
}

char	*ft_read_file(int fd, char *buffer)
{
	char	*line;
	char	*keep_line;
	size_t	bytes;

	line = NULL;
	if (buffer[0])
		line = ft_strjoin(line, buffer);
	while (!ft_newline_inbuffer(buffer))
	{
		ft_bzero(buffer, 1);
		bytes = read(fd, buffer, 1);
		if (bytes < 0 || (bytes == 0 && !line))
			return (NULL);
		keep_line = line;
		line = ft_strjoin(line, buffer);
		free (keep_line);
		if (bytes < 1 && line)
			return (line);
	}
	return (line);
}

char	*ft_which_case(int fd, char *buffer)
{
	char	*line;

	line = NULL;
	if (!buffer[0] || !ft_newline_inbuffer(buffer))
	{
		line = ft_read_file(fd, buffer);
		if (!line)
			return (NULL);
		ft_switch_left(buffer);
	}
	else if (ft_newline_inbuffer(buffer))
	{
		line = ft_strdup(buffer);
		if (!line)
			return (NULL);
		ft_switch_left(buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[1 + 1];
	char		*line;

	if (fd < 0 || 1 <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	line = ft_which_case(fd, buffer);
	if (!line)
		return (NULL);
	return (line);
}
