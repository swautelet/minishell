/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:42:41 by swautele          #+#    #+#             */
/*   Updated: 2021/09/13 13:56:52 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (size > 1 && src[i])
	{
		dest[i] = src[i];
		i++;
		size--;
	}
	if (size >= 1)
		dest[i] = '\0';
	return (ft_strlen(src));
}
