/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: showatan <showatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:20:11 by showatan          #+#    #+#             */
/*   Updated: 2025/08/21 14:43:04 by showatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	handle_error_and_cleanup(char **s1, char **s2)
{
	if (*s1 != NULL)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (*s2 != NULL)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (1);
}

static int	read_and_append(int fd, char **buf_p)
{
	int		read_bytes;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp == NULL)
		return (handle_error_and_cleanup(buf_p, &temp));
	read_bytes = read(fd, temp, BUFFER_SIZE);
	if (read_bytes == -1)
		return (handle_error_and_cleanup(buf_p, &temp));
	if (read_bytes == 0)
	{
		free(temp);
		temp = NULL;
		if (ft_strlen(*buf_p) == 0)
			return (handle_error_and_cleanup(buf_p, &temp));
		return (0);
	}
	temp[read_bytes] = '\0';
	*buf_p = ft_strjoin(*buf_p, temp);
	if (!*buf_p)
		return (handle_error_and_cleanup(buf_p, &temp));
	return (2);
}

char	*read_line(int fd, char	**buf_p)
{
	int	status;

	while (ft_strchr_len(*buf_p, '\n') == -1)
	{
		status = read_and_append(fd, buf_p);
		if (status == 1)
			return (NULL);
		if (status == 0)
			return (*buf_p);
	}
	return (*buf_p);
}

char	*make_new_line(char	**buf_p, char	*line)
{
	char	*temp;
	int		start_to_n_len;
	int		n_to_end_len;

	start_to_n_len = ft_strchr_len(*buf_p, '\n');
	n_to_end_len = ft_strlen(*buf_p) - start_to_n_len - 1;
	if (start_to_n_len != -1)
	{
		line = ft_strdnup(*buf_p, start_to_n_len + 1);
		temp = ft_strdnup(*buf_p + start_to_n_len + 1, n_to_end_len);
		free(*buf_p);
		*buf_p = temp;
	}
	else
	{
		line = ft_strdnup(*buf_p, ft_strlen(*buf_p));
		free(*buf_p);
		*buf_p = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= SIZE_MAX)
		return (NULL);
	if (buf == NULL)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return (NULL);
		buf[0] = '\0';
	}
	line = NULL;
	buf = read_line(fd, &buf);
	if (buf == NULL)
		return (NULL);
	line = make_new_line(&buf, line);
	if (line == NULL)
		return (NULL);
	return (line);
}
