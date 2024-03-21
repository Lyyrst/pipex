/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:40:38 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/15 20:31:57 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_len(char const *s, unsigned int start, size_t len)
{
	size_t	count;

	count = 0;
	while (s[start++] && count < len)
		count++;
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		lstr;

	if (!s)
		return (0);
	if ((size_t)ft_strlen(s) < start)
		len = 0;
	lstr = get_len(s, start, len);
	str = malloc(sizeof(char) * (lstr + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < len && s[start])
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
