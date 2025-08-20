/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: showatan <showatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:18:55 by showatan          #+#    #+#             */
/*   Updated: 2025/07/29 18:42:20 by showatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

int	ft_strchr_len(const char *s, int search_c )
{
	int	len;

	if (!s)
		return (-1);
	len = 0;
	while (*s != '\0')
	{
		if (*s == (char)search_c)
			return (len);
		s++;
		len++;
	}
	return (-1);
}

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*uc_src;
	unsigned char	*uc_dst;

	if (dst == NULL && src == NULL)
		return (NULL);
	uc_src = (unsigned char *)src;
	uc_dst = (unsigned char *)dst;
	while (len-- > 0)
		*uc_dst++ = *uc_src++;
	return (dst);
}

char	*ft_strdnup(const char *s1, int n)
{
	char	*copy;

	copy = (char *)malloc(n + 1);
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, s1, n);
	copy[n] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined_str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (joined_str == NULL)
		return (NULL);
	ft_memcpy(joined_str, s1, len1);
	ft_memcpy(joined_str + len1, s2, len2 + 1);
	free((void *)s1);
	free((void *)s2);
	return (joined_str);
}
