/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:41:44 by tbergkul          #+#    #+#             */
/*   Updated: 2019/11/01 16:45:04 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
	size_t		re;
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	static char	*str[100];

	if (fd < 0)
		return (-1);
	re = 1;
	//printf("starting read\n");
	while ((re = read(fd, buff, BUFF_SIZE)) > 0)
	{
		//printf("size read: %zu\n", re);
		buff[re] = '\0';
		//printf("inside read\n");
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		//printf("strnew done\n");
		temp = ft_strjoin((const char *)str[fd], buff); //kanske int str[fd]
		free(str[fd]);
		//printf("free done\n");
		str[fd] = temp;
		//printf("str[fd] is temp\n");
		if (ft_strchr(buff, '\n'))
		{
			printf("end of line\n");
			break ;
		}
		//printf("end of while loop\n");
		//printf("%s\n", str[fd]);
	}
	//printf("done read\n");
	printf("TEXT:\n%s", str[fd]);
	if (re < 0)
		return (-1);
	else if (re == 0 || str[fd] == NULL || str[fd][0] == '\0')
		return (0);
	return (0);
}
