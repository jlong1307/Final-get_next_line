/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:00:29 by jlong             #+#    #+#             */
/*   Updated: 2021/05/17 10:39:21 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*zone1;
	unsigned char	*zone2;

	zone1 = (unsigned char *)src;
	zone2 = (unsigned char *)dst;
	if (!dst && !src)
		return (0);
	while (n > 0)
	{
		*zone2++ = *zone1++;
		n--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*zdst;
	unsigned char	*zsrc;

	zdst = (unsigned char *)dst;
	zsrc = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (zdst < zsrc)
		return (ft_memcpy(zdst, zsrc, n));
	n++;
	while (--n)
		zdst[n - 1] = zsrc[n - 1];
	return (dst);
}

char	*join_str(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;
	char	*dst;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	total_len = s1_len + s2_len + 1;
	dst = malloc(sizeof(char) * total_len);
	if (!dst)
		return (0);
	ft_memmove(dst, s1, s1_len);
	ft_memmove(dst + s1_len, s2, s2_len);
	dst[total_len - 1] = '\0';
	free((char *)s1);
	return (dst);
}

int	check_line(char *check)
{
	int	i;

	i = 0;
	if (!check)
		return (0);
	while (check[i])
	{
		if (check[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
