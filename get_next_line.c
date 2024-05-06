/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:54:46 by samoore           #+#    #+#             */
/*   Updated: 2023/12/05 14:20:34 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_contains(char *buf, char c)
/*
	Checks if "buf" contains character "c"
*/
{
	int	i;

	if (!buf || !*buf)
		return (-1);
	i = 0;
	while (buf[i])
	{
		if (buf[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_copy_res(char *buffer)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	res = ft_calloc(sizeof(char), (i + 1));
	if (!res)
		return (NULL);
	while (j < i)
	{
		res[j] = buffer[j];
		j++;
	}
	res[j] = 0;
	return (res);
}

char	*ft_trim(char *buf)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	i = ft_contains(buf, '\n');
	if (i == -1)
		return (NULL);
	i++;
	res = ft_calloc(sizeof(char), (ft_strlen(buf) - i + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (buf[i + j])
	{
		res[j] = buf[i + j];
		j++;
	}
	return (res);
}

char	*ft_read(int fd, char *buffer)
{
	char	*buf;
	char	*tmp;
	int		bytes;

	bytes = BUFFER_SIZE;
	buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	while (bytes == BUFFER_SIZE && ft_contains(buf, '\n') == -1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			if (buffer)
			{
				free (buffer);
				buffer = NULL;
			}
			break ;
		}
		buf[bytes] = 0;
		tmp = ft_strjoin(buffer, buf);
		free (buffer);
		buffer = tmp;
	}
	free (buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*res;
	char		*tmp;

	if (fd < 0 || fd > SHRT_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_contains(buffer, '\n') == -1)
		buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	res = ft_copy_res(buffer);
	tmp = ft_trim(buffer);
	if (buffer)
		free (buffer);
	buffer = tmp;
	return (res);
}
/*
int main(void)
{
	int fd = open("test.file", O_RDONLY);
	char	*res;
	int i = 0;

	while (i < 9)
	{
		res = get_next_line(fd);
		printf("%s", res);
		i++;
	}
}*/
