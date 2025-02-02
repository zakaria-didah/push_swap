/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:20:47 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/01 14:21:33 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	*create_word(char *s, char c, int *j)
{
	int		i;
	char	*str;

	while (s[*j] == c)
		(*j)++;
	i = *j;
	while (s[i] && s[i] != c)
		i++;
	str = ft_substr(s, *j, i - *j);
	*j = i;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	int		words_len;
	char	**words;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	words_len = count_words(s, c);
	words = ft_calloc(words_len + 1, sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	j = 0;
	while (i < words_len)
	{
		words[i] = create_word((char *)s, c, &j);
		if (!words[i])
			return (free_garb(), NULL);
		i++;
	}
	words[i] = 0;
	return (words);
}
