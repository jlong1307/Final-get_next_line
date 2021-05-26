/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:12:59 by jlong             #+#    #+#             */
/*   Updated: 2021/05/17 10:46:05 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_save(char *save)
{
	char	*save_next;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	save_next = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1));
	if (!save_next)
		return (0);
	i++;
	while (save[i])
		save_next[j++] = save[i++];
	save_next[j] = '\0';
	free(save);
	return (save_next);
}

char	*next_line(char *str)
{
	int		i;
	char	*nextline;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	nextline = malloc(sizeof(char) * (i + 1));
	if (!nextline)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		nextline[i] = str[i];
		i++;
	}
	nextline[i] = '\0';
	return (nextline);
}

int	get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*save_line;
	int				reader;

	reader = 1;
	buff = "\0";
	if (fd < 0 || !line || read(fd, buff, 0) == -1 || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	while (reader != 0 && !check_line(save_line))
	{
		reader = read(fd, buff, BUFFER_SIZE);
		buff[reader] = '\0';
		save_line = join_str(save_line, buff);
	}
	free(buff);
	*line = next_line(save_line);
	save_line = line_save(save_line);
	if (reader == 0)
		return (0);
	return (1);
}
