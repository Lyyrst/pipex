/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:51:33 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/16 12:19:43 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_len(const char *str, int i, char sep)
{
	int	count;

	count = 0;
	while (str[i] && str[i] != sep)
	{
		i++;
		count++;
	}
	return (count);
}

static int	arraylen(char const *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[i] == '\0')
		return (0);
	if (str[0] != sep)
	{
		count++;
		i++;
	}
	while (str[i])
	{
		if (str[i] == sep && str[i + 1] != sep)
			count++;
		i++;
	}
	if (str[i - 1] == sep)
		count--;
	return (count);
}

void	ft_freesplit(char **array, int i)
{
	while (i >= 0)
		free(array[i--]);
	free(array);
}

static void	*ft_makesplit(char **array, char const *str, char sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			k = 0;
			array[j] = malloc(sizeof(char) * (ft_len(str, i, sep) + 1));
			if (!array[j])
			{
				ft_freesplit(array, j);
				return (0);
			}
			while (str[i] && str[i] != sep)
				array[j][k++] = str[i++];
			array[j++][k] = 0;
		}
		else
			i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (0);
	array = malloc(sizeof(char *) * (arraylen(s, c) + 1));
	if (!array)
		return (0);
	if (!ft_makesplit(array, s, c))
		return (0);
	array[arraylen(s, c)] = 0;
	return (array);
}
