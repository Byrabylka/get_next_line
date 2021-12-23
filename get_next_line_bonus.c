/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:01:17 by fooswyn           #+#    #+#             */
/*   Updated: 2021/12/22 18:16:27 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_l(char *str)
{
	char	ch;
	int		len;

	len = 0;
	if (ft_strchr(str, '\n'))
		ch = '\n';
	else
		ch = '\0';
	while (str[len] != ch)
		len++;
	return (len + 1);
}

char	*ft_read(char *begin, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		readed;

	readed = 1;
	if (!begin)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed <= 0)
			return (NULL);
		buf[readed] = 0;
		begin = ft_strdup(buf);
	}
	while (!(ft_strchr(begin, '\n')) && readed)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		buf[readed] = 0;
		begin = ft_strjoin(begin, buf, 0);
	}
	return (begin);
}

int	plus(char *a, char *b)
{
	return (ft_strlen(a) + ft_strlen(b));
}

char	*get_next_line(int fd)
{
	static char	*begin[1024];
	char		*tmp;
	char		*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	begin[fd] = ft_read(begin[fd], fd);
	if (!begin[fd])
		return (NULL);
	tmp = NULL;
	str = NULL;
	if (ft_strchr(begin[fd], '\n'))
	{
		tmp = begin[fd];
		str = ft_substr(tmp, 0, ft_l(begin[fd]));
		begin[fd] = ft_substr(tmp, ft_l(begin[fd]), plus(begin[fd], str));
		free(tmp);
		return (str);
	}
	if (begin[fd][0] != 0)
		str = ft_substr(begin[fd], 0, ft_l(begin[fd]));
	free(begin[fd]);
	begin[fd] = NULL;
	return (str);
}
