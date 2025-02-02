/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:03:08 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/02 18:10:49 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_puterror(char *c)
{
	int	count;

	count = 0;
	while (*c)
	{
		count += write(2, c, 1);
		c++;
	}
	return (count);
}

int	ft_putstr(char *c)
{
	int	count;

	count = 0;
	if (!c)
		return (count += write(1, "(null)", 6));
	while (*c)
	{
		count += write(1, c, 1);
		c++;
	}
	return (count);
}
