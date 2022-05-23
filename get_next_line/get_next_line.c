/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamanfo <kamanfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:36:01 by kamanfo           #+#    #+#             */
/*   Updated: 2022/01/01 17:34:36 by kamanfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

char	*get_next_txt(char *buffer_txt, int fd)
{
	int		read_vl;
	char	*line_buffer;

	read_vl = 0;
	line_buffer = malloc(sizeof(char) * (4096 + 1));
	if (!line_buffer)
		return (NULL);
	while (ft_strchr(buffer_txt, 10) == NULL)
	{	
		read_vl = read(fd, line_buffer, 4096);
		if (read_vl == -1)
		{
			free(line_buffer);
			return (NULL);
		}
		else if (read_vl == 0)
		{
			free(line_buffer);
			return (buffer_txt);
		}
		*(line_buffer + read_vl) = 0;
		buffer_txt = ft_gnljoin(buffer_txt, line_buffer);
	}
	free(line_buffer);
	return (buffer_txt);
}

char	*get_extract_line(char *gt_txt)
{
	char		*new_line;
	size_t		index;

	if (!gt_txt)
		return (NULL);
	index = 0;
	while (*(gt_txt + index) && (*(gt_txt + index) != '\n'))
		index++;
	new_line = malloc(sizeof(char) * (index + 2));
	if (!new_line)
		return (NULL);
	index = 0;
	while (*(gt_txt + index) && (*(gt_txt + index) != '\n'))
	{
		*(new_line + index) = *(gt_txt + index);
		index++;
	}
	if (*(gt_txt + index) == 10)
	{
		*(new_line + index) = *(gt_txt + index);
		index++;
	}
	*(new_line + index) = 0;
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char		*buffer_txt;
	char			*line;

	if (fd < 0 || fd > 65535)
		return (NULL);
	else if (ft_strchr(buffer_txt, 10) == NULL)
		buffer_txt = get_next_txt(buffer_txt, fd);
	line = get_extract_line(buffer_txt);
	if (line)
	{
		if (ft_strlen(buffer_txt) == 0)
		{
			free(line);
			free(buffer_txt);
			return (NULL);
		}
		buffer_txt = maj_txt(buffer_txt + ft_strlen(line), buffer_txt);
	}
	return (line);
}
