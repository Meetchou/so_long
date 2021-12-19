/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamanfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:54:09 by kamanfo           #+#    #+#             */
/*   Updated: 2021/11/29 13:23:43 by kamanfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_itoa_valabs(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
		return (-nb);
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		nblen;
	long	nb;

	nblen = ft_nbrlen(n);
	dest = (char *)malloc(sizeof(char) * (ft_nbrlen(n) + 1));
	if (!dest)
		return (NULL);
	nb = ft_itoa_valabs(n);
	dest[nblen--] = '\0';
	while (nblen >= 0)
	{
		dest[nblen] = (nb % 10) + 48;
		nb = nb / 10;
		nblen--;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}
