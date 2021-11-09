/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:00:18 by gajayme           #+#    #+#             */
/*   Updated: 2021/11/09 11:09:30 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	buf_checker(char *buf, char **line, char **n_ptr)
{
	*n_ptr = ft_strchr(buf, '\n');
	if (*n_ptr)
	{
		**n_ptr = 'a';
		*line = ft_strjoin(line, *n_ptr + 1);
	}
	*n_ptr = NULL;
	*n_ptr = ft_strchr(*line, '\n');
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*n_ptr;
	int			ret;

	n_ptr = NULL;
	line = NULL;
	ret = 1;
	buf_checker(buf, &line, &n_ptr);
	while (ret && !n_ptr)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		line = ft_strjoin(&line, buf);
		n_ptr = ft_strchr(line, '\n');
	}
	if (n_ptr)
		*(n_ptr + 1) = '\0';
	return (line);
}
