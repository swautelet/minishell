/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:42:04 by swautele          #+#    #+#             */
/*   Updated: 2021/09/30 18:24:46 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *str, int searched)
{
	while (*str)
	{
		if (*str == searched % 256)
			return ((char *)str);
		str++;
	}
	if (searched == '\0')
		return ((char *)str);
	return (NULL);
}
