/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarakel <omerlutfu.k34@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:10:54 by okarakel          #+#    #+#             */
/*   Updated: 2022/02/09 15:26:37 by okarakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*new_str;
	int		len;
	int		i;

	len = ft_strlen(s1);
	new_str = malloc(len + 1);
	if (new_str == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}

char	*get_one_line(char *str, int fd)
{
	char	*s;
	char	*buff;
	int		read_size;

	buff = malloc(BUFFER_SIZE + 1);
	read_size = read(fd, buff, BUFFER_SIZE);
	if (read_size <= 0)
	{
		free(buff);
		s = malloc(ft_strlen(str) + 1);
		ft_strlcpy(s, str, ft_strlen(str) + 1);
		return (s);
	}
	buff[read_size] = 0;
	s = malloc(ft_strlen(str) + 1);
	ft_strlcpy(s, str, ft_strlen(str) + 1);
	s = ft_strjoin(s, buff);
	while (!ft_strchr(buff, '\n') && read_size == BUFFER_SIZE)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		buff[read_size] = 0;
		s = ft_strjoin(s, buff);
	}
	free(buff);
	return (s);
}

char	*get_after_new_line(char *s)
{
	char	*str;
	int		index;
	int		size;

	if (!ft_strchr(s, '\n'))
		return (ft_strdup(""));
	index = ft_strchr(s, '\n') - s;
	size = ft_strlen(s) - index + 1;
	str = (char *)malloc(size);
	ft_strlcpy(str, s + index + 1, size);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	s = get_one_line(str, fd);
	if (!s || !*s)
	{
		free(str);
		str = 0;
		free(s);
		return (0);
	}
	free(str);
	str = get_after_new_line(s);
	if (ft_strchr(s, '\n'))
		s[ft_strchr(s, '\n') - s + 1] = 0;
	return (s);
}
