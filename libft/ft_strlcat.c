/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:21:34 by zdidah            #+#    #+#             */
/*   Updated: 2024/11/10 19:21:37 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dst_len == dstsize)
		return (dst_len + src_len);
	if (dst_len > dstsize)
		return (dstsize + src_len);
	if (dstsize == 0)
		return (src_len);
	while ((i + dst_len < dstsize - 1) && src[i])
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = 0;
	return (src_len + dst_len);
}
