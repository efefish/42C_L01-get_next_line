/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujisaw <tfujisaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 22:01:25 by tfujisaw          #+#    #+#             */
/*   Updated: 2021/01/11 04:49:19 by tfujisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

int			get_next_line(int fd, char **line);
int			ft_check_line(int fd, char **line, char **nextl, char *buf);
int			read_error_free(char **line, char *nextl);
size_t		ft_strchr_gnl(const char *s, char c);
char		*ft_strjoin_gnl(char const *s1, char const *s2, size_t len);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);

#endif
