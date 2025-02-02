/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:37:00 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/02 16:46:52 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	a2i(char *str)
{
	long	res;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if ((res * sign) < INT_MIN || (res > INT_MAX && sign == 1))
			return (LONG_MAX);
		i++;
	}
	return ((int)res * sign);
}

char	*ft_strjoin_x(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	str = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i++] = s2[j++];
	}
	if (str[i] != ' ')
		str[i++] = ' ';
	str[i] = 0;
	return (str);
}

int	valid(char **arr)
{
	int (j), (i) = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[j])
		{
			if (i == j)
				j++;
			if (!arr[j])
			{
				if (!id(arr[i]) || (a2i(arr[i]) > INT_MAX
						|| a2i(arr[i]) < INT_MIN))
					return (0);
				return (1);
			}
			if ((!id(arr[i]) || !id(arr[j])) || (a2i(arr[i]) == a2i(arr[j]))
				|| (a2i(arr[i]) > INT_MAX || a2i(arr[i]) < INT_MIN)
				|| (a2i(arr[j]) > INT_MAX || a2i(arr[j]) < INT_MIN))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	id(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (!str[i + 1] || (str[i + 1] < '0' || str[i + 1] > '9'))
			return (0);
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] && (str[i] > '9' || str[i] < '0'))
		return (0);
	return (1);
}
