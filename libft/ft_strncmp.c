/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:43:07 by swautele          #+#    #+#             */
/*   Updated: 2021/09/30 18:37:08 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *first, const char *second, size_t len)
{
	while (len > 1 && *first && *second && *first == *second)
	{
		len--;
		first++;
		second++;
	}
	if (len == 0)
		return (0);
	return (*(unsigned char *)first - *(unsigned char *)second);
}
