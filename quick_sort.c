/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:37:26 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/02 10:01:42 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}

void	_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(char **arr, int low, int high)
{
	int	pi;
	int	i;
	int	j;

	pi = a2i(arr[low]);
	i = low;
	j = high;
	while (i < j)
	{
		while (a2i(arr[i]) <= pi && i <= high - 1)
		{
			i++;
		}
		while (a2i(arr[j]) > pi && j >= low + 1)
		{
			j--;
		}
		if (i < j)
		{
			_swap(&arr[i], &arr[j]);
		}
	}
	_swap(&arr[low], &arr[j]);
	return (j);
}

void	quick_sort(char **arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}
