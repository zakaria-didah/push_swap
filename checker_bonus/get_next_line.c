/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:28:29 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/02 09:43:12 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_left(char *res)
{
	char	*left;
	int		i;

	left = NULL;
	i = 0;
	if (!res[i])
		return (NULL);
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\0')
		left = NULL;
	else
	{
		left = ft_substr_(res, i + 1, ft_strlen_(res));
		res[i + 1] = '\0';
	}
	return (left);
}

char	*check_line(int fd, char *left)
{
	ssize_t	read_count;
	char	*tmp;
	char	*buffer;

	buffer = ft_calloc(((size_t)(BUFFER_SIZE + 1)), sizeof(char));
	if (!buffer)
		return (NULL);
	read_count = 1;
	while (read_count > 0)
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == -1)
			return (left = NULL, NULL);
		buffer[read_count] = '\0';
		if (read_count == 0)
			break ;
		tmp = left;
		left = ft_strjoin_(tmp, buffer);
		tmp = NULL;
		if (ft_strchr_(left, '\n'))
			break ;
	}
	return (buffer = NULL, left);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*res;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = check_line(fd, left);
	if (!res)
		return (NULL);
	left = find_left(res);
	if (res[0] == '\0')
	{
		res = NULL;
	}
	return (res);
}
