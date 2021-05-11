/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:12:59 by jlong             #+#    #+#             */
/*   Updated: 2021/05/11 09:19:53 by jlong            ###   ########.fr       */
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
			return (0);
		}
	}
	else
		*line = ft_strnew(0);
	return (endline);
}
int 	ft_returngood(int ret)
{
	return (ret != 0);
}
int		get_next_line(int fd, char **line)
{
	int				ret;
	char			*buf;
	char			*endline;
	static char		*nextline;
	char			*tmp;

	buf = '\0';
	ret = 1;
	if (fd < 0 || !line || read(fd, buf, 0) == -1 || BUFFER_SIZE <= 0)
		return (-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	endline = checknextline(nextline, line);
	while (!endline && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
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
	free(buf);
	return (ft_returngood(ret));
}

/*int	main(void)
{
	char	*line;
	int		fd;
	fd = open("text.txt", O_RDONLY);
	printf("%d\n",get_next_line(fd, &line));
	printf("%s\n", line);

	printf("%d\n",get_next_line(fd, &line));
	printf("%s\n", line);

	printf("%d\n",get_next_line(fd, &line));
	printf("%s\n", line);

	printf("%d\n",get_next_line(fd, &line));
	printf("%s\n", line);

	printf("%d\n",get_next_line(fd, &line));
	printf("%s\n", line);

	printf("%d\n",get_next_line(fd, &line));
	printf("%s\n", line);

	
}
*/