/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:00:18 by gajayme           #+#    #+#             */
/*   Updated: 2021/11/09 11:33:24 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*fd_find(t_list **fd_list, int fd)
{
	t_list	*fd_current;

	fd_current = *fd_list;
	while (fd_current && fd_current->fd != fd)
		fd_current = fd_current->next;
	if (fd_current)
		return (fd_current);
	fd_current = (t_list *)malloc(sizeof(t_list));
	if (!fd_current)
		return (NULL);
	fd_current->buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!fd_current->buf)
		return (NULL);
	fd_current->fd = fd;
	fd_current->next = *fd_list;
	*fd_list = fd_current;
	return (fd_current);
}

int	fd_free(int fd, t_list	**fd_list, t_list *fd_current)
{
	t_list	*tmp;

	tmp = *fd_list;
	if ((*fd_list)->fd == fd)
	{
		*fd_list = (*fd_list)->next;
		free(tmp->buf);
		free(tmp);
		tmp = NULL;
		return (1);
	}
	while (tmp->next && tmp->next != fd_current)
		tmp = tmp->next;
	if (!tmp)
		return (1);
	tmp->next = fd_current->next;
	free(fd_current->buf);
	free(fd_current);
	fd_current = NULL;
	return (1);
}

char	*main_loop(int fd, t_list **fd_list, t_list *fd_current)
{
	char			*n_ptr;
	char			*line;
	int				ret;

	n_ptr = NULL;
	line = NULL;
	ret = 1;
	buf_checker(fd_current->buf, &line, &n_ptr);
	while (ret && !n_ptr)
	{
		ret = read(fd, fd_current->buf, BUFFER_SIZE);
		if (ret == -1 && fd_free(fd, fd_list, fd_current))
			return (NULL);
		else if (ret == 0 && fd_free(fd, fd_list, fd_current))
			break ;
		fd_current->buf[ret] = '\0';
		line = ft_strjoin(&line, fd_current->buf);
		n_ptr = ft_strchr(line, '\n');
	}
	if (n_ptr)
		*(n_ptr + 1) = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*fd_list = NULL;
	t_list			*fd_current;

	fd_current = NULL;
	if (fd < 0)
		return (NULL);
	fd_current = fd_find(&fd_list, fd);
	if (!fd_current)
		return (NULL);
	return (main_loop(fd, &fd_list, fd_current));
}
