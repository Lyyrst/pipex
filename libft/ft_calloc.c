/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:32:59 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/18 15:26:14 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*array;

	if (n && size > 4294967295)
		return (0);
	array = malloc(n * size);
	if (!array)
		return (0);
	ft_bzero(array, n * size);
	return (array);
}
