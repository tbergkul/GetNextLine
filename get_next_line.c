/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:41:44 by tbergkul          #+#    #+#             */
/*   Updated: 2019/11/04 15:30:47 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	ft_next_line(char **str, int re, char **line, const int fd)
{
	char	*temp;
	int		length;

	length = 0;
	while (str[fd][length] != '\n' && str[fd][length] != '\0')
		length++;
	if (str[fd][length] == '\n')
	{
		*line = ft_strsub(str[fd], 0, length);
		temp = ft_strdup(str[fd] + length + 1);
		free(str[fd]);
		str[fd] = temp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][length] == '\0')
	{
		if (re == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	size_t		re;
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	static char	*str[100];

	if (fd < 0)
		return (-1);
	while ((re = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[re] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(0);
		temp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (re < 0)
		return (-1);
	else if (re == 0 || str[fd] == NULL || str[fd][0] == '\0')
		return (0);
	return (ft_next_line(str, re, line, fd));
}
