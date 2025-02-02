/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:21:38 by zdidah            #+#    #+#             */
/*   Updated: 2024/11/10 19:21:41 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		len;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (src[i] && dstsize - 1 > i)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (len);
}
