/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralverta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 06:51:00 by ralverta          #+#    #+#             */
/*   Up{dated: 2021/04/29 15:55:58 by ralverta         ###   ########.fr      */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#define BUFFER_SIZE 10

size_t	len_before_n(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int		n_found(char **cash, char **line)
{
	char	*remainder;
	int		n;

	n = len_before_n(*cash);
	remainder = gnl_strdup(*cash + n + 1);
	(*cash)[n] = '\0';
	*line = gnl_strdup(*cash);
	free(*cash);
	*cash = remainder;
	return (1);
}

int		n_not_found(char **cash, char **line)
{
	if (*cash)
		*line = gnl_strdup(*cash);
	else
		*line = gnl_strdup("");
	free(*cash);
	*cash = 0;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*cash;
	char		*buf;
	int			r;


	if (BUFFER_SIZE <= 0 || fd < 0 || (!line) ||
			!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);

	while (!gnl_strchr(cash, '\n') && (r = read(fd, buf, BUFFER_SIZE)))
	{
		if (r == -1)
		{
			free(buf);
			return (-1);
		}
		buf[r] = '\0';
		cash = gnl_strjoin(cash, buf);
	}
	free(buf);
	if (!gnl_strchr(cash, '\n'))
		return (n_not_found(&cash, line));
	else
		return (n_found(&cash, line));
}
