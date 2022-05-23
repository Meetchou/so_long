/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamanfo <kamanfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:42:51 by kamanfo           #+#    #+#             */
/*   Updated: 2022/01/01 20:07:01 by kamanfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *) s);
	return (NULL);
}

char	*maj_txt(char *actual, char *to_free)
{
	char	*new_txt;
	int		index;

	if (!actual)
		return (NULL);
	new_txt = malloc(sizeof(char) * (ft_strlen(actual) + 1));
	index = 0;
	while (*(actual + index))
	{
		*(new_txt + index) = *(actual + index);
		index++;
	}	
	*(new_txt + index) = '\0';
	free(to_free);
	return (new_txt);
}

char	*ft_gnljoin(char *s1, char *s2)
{
	int		index;
	char	*s3;
	char	*start_buffer;

	if (!s2)
		return (s1);
	start_buffer = s1;
	index = 0;
	s3 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!s3)
		return (NULL);
	while (s1 && *s1)
		*(s3 + index++) = *(char *)s1++;
	while (*s2)
		*(s3 + index++) = *(char *)s2++;
	*(s3 + index) = '\0';
	free(start_buffer);
	return (s3);
}
