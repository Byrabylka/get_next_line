/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:02:30 by fooswyn           #+#    #+#             */
/*   Updated: 2021/12/22 18:18:02 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a && a[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*arr;
	size_t	i;
	size_t	buf;

	i = 0;
	buf = ft_strlen(str);
	arr = (char *)malloc(buf + 1);
	if (!arr)
		return (NULL);
	else
	{
		while (str[i])
		{
			arr[i] = (char)str[i];
			i++;
		}
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strchr(const char *str, int c)
{
	char	*temp;

	temp = (char *)str;
	while (*temp)
	{
		if (*temp == (char)c)
			return (temp);
		temp++;
	}
	if ((char)c == *temp)
		return (temp);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2, int param)
{
	char	*arr;
	size_t	i;
	size_t	j;
	size_t	buf;

	i = 0;
	j = 0;
	buf = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(buf + 1);
	if (!arr)
		return (NULL);
	else
	{
		while (s1 && s1[i])
			arr[j++] = s1[i++];
		i = 0;
		while (s2 && s2[i])
			arr[j++] = s2[i++];
		arr[j] = 0;
	}
	if (param == 0 || param == 2)
		free((void *)s1);
	if (param == 1 || param == 2)
		free((void *)s2);
	return (arr);
}
