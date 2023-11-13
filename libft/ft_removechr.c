/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removechr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:11:04 by rnaka             #+#    #+#             */
/*   Updated: 2023/11/13 10:08:13 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char* removechr(char* str, char ch)
{
	int	count;
	int	i;
	char	*result;
	int	index;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			count++;
		i++;
	}
	result = malloc(ft_strlen(str) - count + 1);
	if (!result)
		return NULL;
	i = 0;
	index = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ch)
			result[index++] = str[i];
		i++;
	}
	result[index] = '\0';
	free(str);
	return result;
}
