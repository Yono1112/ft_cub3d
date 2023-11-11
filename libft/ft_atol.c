/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuohno <yuohno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:05:26 by yuohno            #+#    #+#             */
/*   Updated: 2023/11/10 13:55:56 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	check_overflow(char c, int sign, long result, int *is_over_long)
{
	if (sign == 1 && (result > INT_MAX / 10 || (result == INT_MAX / 10
				&& c - '0' > INT_MAX % 10)))
	{
		*is_over_long = -1;
		return (1);
	}
	if (sign == -1 && (result > INT_MAX / 10 || (result == INT_MAX / 10
				&& c - '0' > INT_MAX % 10 + 1)))
	{
		*is_over_long = -1;
		return (1);
	}
	return (0);
}

long	ft_atol(const char *str, int *is_over_long)
{
	int		sign;
	long	result;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	while ((('\t' <= str[i] && str[i] <= '\r') || str[i] == ' ') && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		if (sign == 1 && check_overflow(str[i], sign, result, is_over_long))
			return (-1);
		if (sign == -1 && check_overflow(str[i], sign, result, is_over_long))
			return (-1);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
