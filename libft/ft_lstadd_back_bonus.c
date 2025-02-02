/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:18:31 by zdidah            #+#    #+#             */
/*   Updated: 2024/11/10 19:28:05 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_lst;

	if (!lst || !new)
		return ;
	else if (*lst == NULL)
		*lst = new;
	else
	{
		last_lst = ft_lstlast(*lst);
		if (!last_lst)
			return ;
		last_lst->next = new;
	}
}
