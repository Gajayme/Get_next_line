/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:00:15 by gajayme           #+#    #+#             */
/*   Updated: 2021/11/09 11:33:34 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	inc;

	if (!dest || !src)
		return (NULL);
	i = 0;
	inc = 1;
	if (src < dest)
	{
		inc = -1;
		i = n - 1;
	}
	while (n--)
	{
		*((char *)dest + i) = *((char *)src + i);
		i += inc;
	}
	return (dest);
}

char	*ft_strchr(const char *string, int symbol)
{
	if (!string)
		return (NULL);
	while (*string != (char)symbol && *string)
	{
		string++;
	}
	if (*string == '\0' && symbol != '\0')
		return (NULL);
	return ((char *)string);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i += 1;
	return (i);
}

char	*ft_strjoin(char **s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	if (!s2[0])
		return (*s1);
	s1_len = ft_strlen(*s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)malloc(s1_len + s2_len + 1);
	if (!ptr)
		return (NULL);
	ft_memmove(ptr, *s1, s1_len);
	ft_memmove(ptr + s1_len, s2, s2_len);
	ptr[s1_len + s2_len] = '\0';
	if (*s1)
		free(*s1);
	return (ptr);
}
