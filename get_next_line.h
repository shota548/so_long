/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: showatan <showatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:42:53 by marvin            #+#    #+#             */
/*   Updated: 2025/07/29 17:23:05 by showatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		ft_strchr_len(const char *s, int search_c );
void	*ft_memcpy(void *dst, const void *src, size_t len);
char	*ft_strdnup(const char *s1, int n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
