/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:58:32 by samoore           #+#    #+#             */
/*   Updated: 2023/12/05 14:01:37 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *dst, int n)
{
	unsigned char	*d;
	int				i;

	i = 0;
	d = (unsigned char *)dst;
	while (i < n)
	{
		d[i] = 0;
		i++;
	}
}

void	*ft_calloc(int nmemb, int size)
{
	void	*buf;
	int		t_size;

	t_size = nmemb * size;
	if (nmemb == 0 || size == 0)
	{
		buf = malloc(0);
		return (buf);
	}
	if (INT_MAX / nmemb < size)
	{
		return (0);
	}
	buf = malloc(t_size);
	if (!buf)
		return (NULL);
	ft_bzero(buf, t_size);
	return (buf);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	char	*res_p;

	if (!s1 && !s2)
		return (NULL);
	res = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (0);
	res_p = res;
	while (s1 && *s1)
		*res++ = *s1++;
	while (s2 && *s2)
		*res++ = *s2++;
	*res = 0;
	return (res_p);
}
