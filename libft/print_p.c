/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:24:16 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/03 19:19:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_pointer(unsigned long int n, char *base, int *nb)
{
	unsigned long int	blen;

	blen = (unsigned long int)ft_strlen(base);
	if (n >= blen)
	{
		ft_putnbr_base(n / blen, base, nb);
		ft_putnbr_base(n % blen, base, nb);
	}
	else
		ft_putchar(base[n], nb);
}

void	print_p(unsigned long int n, int *nb)
{
	if (!n)
	{
		ft_putstr("(nil)", nb);
		return ;
	}
	ft_putstr("0x", nb);
	ft_put_pointer(n, "0123456789abcdef", nb);
}
