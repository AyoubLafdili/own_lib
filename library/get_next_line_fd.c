/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:45:27 by alafdili          #+#    #+#             */
/*   Updated: 2023/12/26 22:04:45 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*buffer_update(char *buffer)
{
	char	*updated;
	int		start;

	start = 0;
	while (buffer[start] != '\n' && buffer[start])
		start++;
	if (buffer[start] == '\n')
		start++;
	else if (buffer[start] == '\0')
		return (free(buffer), NULL);
	updated = ft_substr(buffer, start, ft_strlen(buffer) - start);
	free(buffer);
	return (updated);
}

static char	*cut_nl(char *buffer)
{
	char	*line;
	int		len;

	len = 0;
	if (!buffer[0])
		return (NULL);
	while (buffer[len] != '\n' && buffer[len])
		len++;
	if (buffer[len] == '\n')
		len++;
	line = ft_substr(buffer, 0, len);
	return (line);
}

static char	*read_lines(int fd, char *buffer)
{
	int		r_value;
	char	*read_buffer;

	read_buffer = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buffer)
		return (free(buffer), NULL);
	while (1)
	{
		r_value = read(fd, read_buffer, BUFFER_SIZE);
		if (r_value == -1)
		{
			free(buffer);
			free(read_buffer);
			return (NULL);
		}
		else if (r_value == 0)
			break ;
		read_buffer[r_value] = '\0';
		buffer = str_join(buffer, read_buffer);
		if (ft_strchr(read_buffer, '\n') != NULL)
			break ;
	}
	free(read_buffer);
	return (buffer);
}

char	*get_next_line_fd(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer[fd] = read_lines(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = cut_nl(buffer[fd]);
	buffer[fd] = buffer_update(buffer[fd]);
	return (line);
}
