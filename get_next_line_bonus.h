/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:00:21 by gajayme           #+#    #+#             */
/*   Updated: 2021/11/09 11:09:24 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE -1
# endif

typedef struct s_list
{
	int				fd;
	char			*buf;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char **s1, char const *s2);
char	*ft_strchr(const char *string, int symbol);
void	buf_checker(char *buf, char **line, char **n_ptr);
void	*ft_memmove(void *dest, const void *src, size_t n);
#endif