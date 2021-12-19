/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamanfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:36:01 by kamanfo           #+#    #+#             */
/*   Updated: 2021/12/18 18:34:37 by kamanfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (0);
	if (!(*str))
		return (free(str), NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		++i;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	i = -1;
	while (str[++i] && str[i] != '\n')
		line[i] = str[i];
	line[i] = str[i];
	if (str[i] == '\n')
		line[++i] = '\0';
	return (line);
}

char	*get_save(char *str)
{
	char	*save;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str || !str[0])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	save = (char *)malloc(ft_strlen(&str[i]));
	if (!save)
		return (0);
	i++;
	while (str[i])
		save[j++] = str[i++];
	save[j] = '\0';
	free(str);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*save = NULL;
	int			reader;

	line = NULL;
	reader = 1;
	if (fd < 0)
		return (NULL);
	buff = (char *)malloc((4096 + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!has_backtoline(save) && reader != 0)
	{
		reader = read(fd, buff, 4096);
		if (reader == -1)
			return (free(buff), NULL);
		buff[reader] = '\0';
		save = ft_gnlstrjoin(save, buff);
	}
	free(buff);
	line = get_line(save);
	save = get_save(save);
	return (line);
}
