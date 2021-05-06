/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:12:59 by jlong             #+#    #+#             */
/*   Updated: 2021/05/06 15:52:00 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (size > 0)
		str[size--] = '\0';
	str[0] = '\0';
	return (str);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_strclr(char *s)
{
	if (s)
	{
		while (*s)
		{
			*s = '\0';
			s++;
		}
	}
}

char	*checknextline(char *nextline, char **line)
{
	char	*endline;

	endline = NULL;
	if (nextline)
	{
		endline = ft_strchr(nextline, '\n');
		if (endline)
		{
			*endline = '\0';
			*line = ft_strdup(nextline);
			ft_strcpy(nextline, ++endline);
		}
		else
		{
			*line = ft_strdup(nextline);
			ft_strclr(nextline);
		}
	}
	else
	{
		*line = ft_strnew(1);
	}
	return (endline);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[BUFFER_SIZE + 1];
	char			*endline;
	static char		*nextline;
	char			*tmp;

	if (!fd || !line)
		return (-1);
	endline = checknextline(nextline, line);
	if (endline)
		return (1);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret && !endline)
	{
		buf[ret] = '\0';
		endline = ft_strchr(buf ,'\n');
		if (endline)
		{
			*endline = '\0';
			endline++;
			nextline = ft_strdup(endline);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	// encore retourner le -1 ou 0 ou 1
	return (0);
}
/* int	main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line);
	printf("%s\n", line);
}
*/