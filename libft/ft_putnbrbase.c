/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:56:06 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/20 16:54:40 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

int	ft_putnbrbase(long n, int base, char c, int count)
{
	const char	*base10 = "0123456789";
	const char	*base16 = "0123456789abcdef";

	if (n < 0 && (c == 'd' || c == 'i'))
	{
		n *= -1;
		count += write(1, "-", 1);
	}
	if (n > base - 1)
	{
		count += ft_putnbrbase(n / base, base, c, count);
	}
	if (c == 'd' || c == 'i')
		count += write(1, &base10[n % base], 1);
	else if (c == 'x')
		count += write(1, &base16[n % base], 1);
	else if (c == 'X')
		count += ft_putchar(ft_toupper(base16[n % base]));
	return (count);
}
