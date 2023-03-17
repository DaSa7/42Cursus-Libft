/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshutko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:09:49 by dshutko           #+#    #+#             */
/*   Updated: 2023/02/28 22:11:48 by dshutko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_elements(char const *s, char c)
{
	int	elements;
	int	i;

	elements = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
		{
			i++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
		elements++;
	}
	return (elements);
}

char	**ft_array(char *trim, int elements, char **array, char c)
{
	int		i;
	int		j;
	int		strlen;

	i = 0;
	j = 0;
	while (trim[i] != '\0' && j < elements)
	{	
		strlen = 0;
		while (trim[i] != c && trim[i] != '\0')
		{
			i++;
			strlen++;
		}
		array[j] = (char *)malloc((strlen + 1) * sizeof(char));
		if (!array[j])
			return (NULL);
		ft_strlcpy(array[j], &trim[i - strlen], (strlen + 1));
		while (trim[i] == c)
			i++;
		j++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*trim;
	int		elements;
	char	set[2];

	if (!s)
		return (NULL);
	set[0] = c;
	set[1] = '\0';
	trim = ft_strtrim(s, set);
	if (trim == NULL)
	{
		array = (char **) malloc(1 * sizeof(char *));
		array[0] = NULL;
		return (array);
	}
	elements = ft_num_elements(trim, c);
	array = (char **) malloc((elements + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array[elements] = NULL;
	array = ft_array(trim, elements, array, c);
	free (trim);
	return (array);
}
