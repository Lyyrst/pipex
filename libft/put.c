/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:40:34 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/22 16:59:06 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_upperc(int c, int *n)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	ft_putchar(c, n);
}

void	ft_putchar(char c, int *n)
{
	(*n)++;
	write (1, &c, 1);
}

void	ft_putstr(char *str, int *n)
{
	int	i;

	i = -1;
	if (!str)
	{
		ft_putstr("(null)", n);
		return ;
	}
	while (str[++i])
		ft_putchar(str[i], n);
}

void	ft_putnbr_base(long long int n, char *base, int *nb)
{
	int	blen;

	blen = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar('-', nb);
		n *= -1;
	}
	if (n >= blen)
	{
		ft_putnbr_base(n / blen, base, nb);
		ft_putnbr_base(n % blen, base, nb);
	}
	else
		ft_putchar(base[n], nb);
}

void	ft_putupper_base(long long int n, char *base, int *nb)
{
	int	blen;

	blen = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar('-', nb);
		n *= -1;
	}
	if (n >= blen)
	{
		ft_putupper_base(n / blen, base, nb);
		ft_putupper_base(n % blen, base, nb);
	}
	else
		put_upperc(base[n], nb);
}
