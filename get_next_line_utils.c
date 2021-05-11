/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:00:29 by jlong             #+#    #+#             */
/*   Updated: 2021/05/10 16:37:57 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*dst;

	size = 0;
	while (s1[size])
		size++;
	dst = malloc(sizeof(char) * (size + 1));
	if (!dst)
		return (0);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(const char *s1,const char *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (0);
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

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
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

