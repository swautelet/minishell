/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:42:34 by swautele          #+#    #+#             */
/*   Updated: 2021/09/13 14:45:40 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	n;

	if (size < ft_strlen(dest))
		n = (ft_strlen(src) + size);
	else
		n = (ft_strlen(dest) + ft_strlen(src));
	while (*dest != '\0')
	{
		dest++;
		if (size > 0)
			size--;
	}
	while (*src != '\0' && size > 1)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	*dest = '\0';
	return (n);
}
