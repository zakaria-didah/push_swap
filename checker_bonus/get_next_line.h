/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdidah <zdidah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:08:54 by zdidah            #+#    #+#             */
/*   Updated: 2025/02/02 09:36:30 by zdidah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "../libft/garb.h"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen_(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin_(char *s1, char *s2);
char	*ft_substr_(const char *s, unsigned int start, size_t len);
char	*check_line(int fd, char *left);
char	*ft_strchr_(const char *s, int c);
#endif