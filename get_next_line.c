/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujisaw <tfujisaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 22:01:15 by tfujisaw          #+#    #+#             */
/*   Updated: 2021/01/11 03:10:11 by tfujisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_line(int fd, char **line, char **nextl, char *buf)
{
	ssize_t	flag;
	size_t	len;
	char	*temp_line;
	char	*temp_nextl;

	flag = 0;
	len = ft_strchr_gnl(buf, '\n');
	temp_line = ft_strjoin_gnl(*line, buf, len);
	if (temp_line == NULL)
		return (-1);
	free(*line);
	*line = temp_line;
	temp_nextl = NULL;
	if (buf[len] == '\n')
	{
		temp_nextl = ft_strdup(buf + (len + 1));
		if (temp_nextl == NULL)
			return (-1);
		flag = 1;
	}
	free(nextl[fd]);
	nextl[fd] = temp_nextl;
	return (flag);
}

int		read_error_free(char **line, char *nextl)
{
	free(*line);
	*line = NULL;
	free(nextl);
	nextl = NULL;
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	int				flag;
	static	char	*nextl[256];
	char			*buf;
	ssize_t			len;

	flag = 0;
	if (BUFFER_SIZE <= 0 || fd < 0 || 255 < fd || !line)
		return (-1);
	if (!(buf = (char *)malloc((size_t)BUFFER_SIZE + 1)))
		return (-1);
	if (!(*line = (char *)malloc(1)))
		return (-1);
	line[0][0] = '\0';
	if (nextl[fd])
		flag = ft_check_line(fd, line, nextl, nextl[fd]);
	while (flag == 0 && (len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[len] = '\0';
		flag = ft_check_line(fd, line, nextl, buf);
	}
	free(buf);
	if (len == -1)
		return (read_error_free(line, nextl[fd]));
	return (flag);
}
