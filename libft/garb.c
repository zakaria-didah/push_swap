/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:41:16 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/02 10:39:14 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garb.h"

t_garb	**_get_head(void)
{
	static t_garb	*head = NULL;

	return (&head);
}

void	_link_list(t_garb *node)
{
	t_garb	**head;

	head = _get_head();
	if (!*head)
	{
		(*head) = node;
	}
	else
	{
		node->prev = NULL;
		node->next = *head;
		(*head)->prev = node;
		*head = node;
	}
}

void	free_garb(void)
{
	t_garb	*tmp;
	t_garb	*head;

	head = *_get_head();
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->ptr);
		free(tmp);
	}
}

void	*add_garb(void *ptr)
{
	t_garb	*node;

	node = malloc(sizeof(t_garb));
	if (!node)
		return (NULL);
	node->ptr = ptr;
	node->prev = NULL;
	node->next = NULL;
	_link_list(node);
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = NULL;
	if (size && count > ((size_t)(-1)) / size)
		return (NULL);
	tmp = malloc(size * count);
	if (!tmp)
		return (NULL);
	ft_bzero_(tmp, size * count);
	if (!add_garb(tmp))
		return (free(tmp), NULL);
	return (tmp);
}
