/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:43:20 by swautele          #+#    #+#             */
/*   Updated: 2021/09/30 18:24:14 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *str, int searched)
{
	const char	*start;

	start = str;
	while (*str)
		str++;
	while (str >= start)
	{
		if (*str == searched % 256)
			return ((char *)str);
		str--;
	}
	return (NULL);
}
