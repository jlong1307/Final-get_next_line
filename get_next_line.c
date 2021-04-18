/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:00:24 by jlong             #+#    #+#             */
/*   Updated: 2021/04/18 15:09:06 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	unsigned char	*ss;

	ss = (unsigned char *)s;
	i = -1;
	while (++i < ft_strlen(s))
		if (ss[i] == (char)c)
			return ((char *)&ss[i]);
	if (ss[i] == (char)c)
		return ((char *)&ss[i]);
	return (NULL);
}
char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*dst;

	size = 0;
	while (s1[size])
		size++;
	dst = malloc(sizeof(char) * (size + 1));
	if (!(dst))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = -1;
	j = -1;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	while (s1[++i] != '\0')
	{
		dst[++j] = s1[i];
	}
	i = -1;
	while (s2[++i] != '\0')
	{
		dst[++j] = s2[i];
	}
	dst[++j] = '\0';
	return (dst);
}
char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (size > 0)
		str[size--] = '\0';
	str[0] = '\0';
	return (str);
}
char	*check_reminder(char *reminder, char **line)
{
	char *p_n;
	p_n = NULL;
	if (reminder)
	{
		if ((p_n = ft_strchr(reminder, '\n')))
		{
			*line = ft_strdup(reminder);
		}
	}
	else
	{
		*line = ft_strnew(1);
	}
}
int	get_next_line(int fd, char **line)
{
	char		buf[1000 + 1];
	int			byte_was_read;
	char		*p_n;
	int			flag;
	static char	*reminder;

	flag = 1;
	if (reminder)
		*line = ft_strdup(reminder);
	else
		*line = ft_strnew(1);
	while (flag && (byte_was_read = read (fd, buf, 1000)))
	{
		buf[byte_was_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			flag = 0;
			reminder = ft_strdup(p_n);
		}
		*line = ft_strjoin(*line, buf);
	}

	return (0);
}

int	main(void)
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



}