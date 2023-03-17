/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshutko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:41:41 by dshutko           #+#    #+#             */
/*   Updated: 2023/02/28 21:43:53 by dshutko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (l[0] == '\0')
		return ((char *)b);
	while (b[i] != '\0')
	{
		j = 0;
		while (b[i + j] != '\0' && (b[i + j] == l[j]) && \
		(i + j) < len)
		{
			if (l[j + 1] == '\0')
				return ((char *)(b + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
