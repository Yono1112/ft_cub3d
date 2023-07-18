/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:01:13 by rnaka             #+#    #+#             */
/*   Updated: 2023/03/20 16:55:39 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft.h"

static int	ft_disp(char fmt, va_list *args)
{
	if (fmt == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (fmt == 's')
		return (ft_putstr(va_arg(*args, const char *)));
	else if (fmt == 'p')
		return (ft_putpointer(va_arg(*args, unsigned long long)));
	else if (fmt == 'i' || fmt == 'd')
		return (ft_putnbrbase(va_arg(*args, int), 10, fmt, 0));
	else if (fmt == 'u')
		return (ft_putulong(va_arg(*args, int), 10, fmt, 0));
	else if (fmt == 'x' || fmt == 'X')
		return (ft_putnbrbase(va_arg(*args, unsigned int), 16, fmt, 0));
	else if (fmt == '%')
		return (write(1, "%", 1));
	else
		return (-1);
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	int		count;
	int		error;
	va_list	args;

	error = 0;
	count = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			error = ft_disp(*(++fmt), &args);
			if (error == -1)
				return (-1);
			fmt++;
			count += error;
		}
		else
		{
			count += write(1, (const void *)fmt, 1);
			fmt++;
		}
	}
	va_end(args);
	return (count);
}
