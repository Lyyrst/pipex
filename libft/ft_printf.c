/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:41:50 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/03 19:19:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_str(const char *str, va_list params, int n)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_str(str[i + 1], params, &n);
			i++;
		}
		else
			ft_putchar(str[i], &n);
		i++;
	}
	return (n);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		n;

	n = 0;
	if (!str)
		return (-1);
	va_start(params, str);
	n = check_str(str, params, n);
	va_end(params);
	return (n);
}
