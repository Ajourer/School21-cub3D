/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralverta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 06:52:28 by ralverta          #+#    #+#             */
/*   Updated: 2021/04/29 16:05:33 by ralverta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*gnl_strchr(char *s, int c)
{
	if (s)
	{
		while (*s != '\0')
		{
			if (*s == c)
				return (s);
			s++;
		}
	}
	if (c == 0)
		return (s);
	return (NULL);
}

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*sum;
	size_t	size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	size = gnl_strlen(s1) + gnl_strlen(s2);
	sum = (char *)malloc(size + 1);
	if (!sum)
		return (NULL);
	while (s1 && s1[i])
	{
		sum[i] = s1[i];
		i++;
	}
	while (s2[j])
		sum[i++] = s2[j++];
	sum[i] = '\0';
	free((void *)s1);
	return (sum);
}

char	*gnl_strdup(const char *s1)
{
	char	*s2;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	s2 = (char *)malloc(len + 1);
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
