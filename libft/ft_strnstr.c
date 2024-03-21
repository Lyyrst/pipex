/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:18:41 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/13 18:40:12 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t n)
{
	size_t	i;
	size_t	n2;
	int		i2;

	n2 = n;
	i = -1;
	if ((!str && !n))
		return (0);
	if (tofind[0] == 0)
		return ((char *)&str[0]);
	while (str[++i] && n-- > 0)
	{
		if (str[i] == tofind[0])
		{
			i2 = 0;
			while (tofind[i2++])
			{
				if (ft_strlen(tofind) == i2 && i + i2 <= n2)
					return ((char *)&str[i]);
				if (tofind[i2] != str[i2 + i] && i2 < ft_strlen(tofind))
					break ;
			}
		}
	}
	return (0);
}
