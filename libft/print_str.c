/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:56:49 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/03 19:19:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_str(char c, va_list params, int *n)
{
	if (c == 'c')
		ft_putchar(va_arg(params, int), n);
	if (c == 's')
		ft_putstr(va_arg(params, char *), n);
	if (c == 'p')
		print_p(va_arg(params, unsigned long int), n);
	if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(params, int), "0123456789", n);
	if (c == 'u')
		ft_putnbr_base(va_arg(params, unsigned int), "0123456789", n);
	if (c == 'x')
		ft_putnbr_base(va_arg(params, unsigned int), "0123456789abcdef", n);
	if (c == 'X')
		ft_putupper_base(va_arg(params, unsigned int), "0123456789abcdef", n);
	if (c == '%')
		ft_putchar('%', n);
}
