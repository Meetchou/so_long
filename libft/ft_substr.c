/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamanfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:48:22 by kamanfo           #+#    #+#             */
/*   Updated: 2021/11/26 12:48:35 by kamanfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if ((size_t)start >= ft_strlen(s))
	{
		res = malloc(sizeof(char));
		if (!res)
			return (NULL);
		res[i] = 0;
		return (res);
	}
	if (len > ft_strlen(s) - start)
		res = malloc(sizeof(char) * ft_strlen(s) - start + 1);
	else
		res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	while (i < len && s[(int)start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}
