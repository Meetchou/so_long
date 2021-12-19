/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamanfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:55:10 by kamanfo           #+#    #+#             */
/*   Updated: 2021/12/02 13:57:11 by kamanfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

int		has_backtoline(char *str);
char	*ft_gnlstrjoin(char *s1, char *s2);
char	*get_save(char *str);
char	*get_line(char *str);
char	*get_next_line(int fd);

#endif
