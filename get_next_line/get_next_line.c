/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:52:13 by kbeceren          #+#    #+#             */
/*   Updated: 2022/09/13 09:52:15 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <unistd.h>

int	ft_error(char *str)
{
	if (str)
		free(str);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	int			read_bytes;
	char		*buff;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (ft_error(str));
	read_bytes = 1;
	while (!find_newline(str) && read_bytes > 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes < 0)
			return (ft_error(buff));
		buff[read_bytes] = '\0';
		str = ft_strjoin_gnl(str, buff);
	}
	free(buff);
	*line = ft_get_line(str);
	str = ft_trim(str);
	if (read_bytes == 0 && !str)
		return (0);
	return (read_bytes);
}
