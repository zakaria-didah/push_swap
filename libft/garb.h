/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garb.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:32:49 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/02 09:38:59 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARB_H
# define GARB_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_garb
{
	void			*ptr;

	struct s_garb	*prev;
	struct s_garb	*next;
}					t_garb;

void				ft_remove(void *ptr);
void				_link_list(t_garb *node);
t_garb				**_get_head(void);
void				*add_garb(void *ptr);
void				*ft_calloc(size_t count, size_t size);
void				free_garb(void);
size_t				list_len_(t_garb *head);
void				*ft_bzero_(void *s, size_t n);

#endif
