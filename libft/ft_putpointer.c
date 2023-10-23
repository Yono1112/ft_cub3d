/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:17:07 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/20 16:55:10 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>

static void	ft_putpoint(unsigned long long n, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
		ft_putpoint(n / 16, count);
	write(1, &base[n % 16], 1);
	*count = *count + 1;
}

int	ft_putpointer(unsigned long long point)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	ft_putpoint(point, &count);
	return (count);
}
