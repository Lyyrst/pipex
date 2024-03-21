/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:05:17 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/15 20:31:49 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_inset(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (c == set[i])
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	i = 0;
	start = 0;
	if (!s1 || !set)
		return (0);
	end = ft_strlen(s1);
	while (s1[start] && ft_inset(s1[start], set) == 1)
		start++;
	while (end > start && ft_inset(s1[end - 1], set) == 1)
		end--;
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (0);
	*str = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
