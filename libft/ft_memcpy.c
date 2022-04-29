/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:41:07 by swautele          #+#    #+#             */
/*   Updated: 2021/09/13 13:55:47 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (destination == source)
		return (NULL);
	d = destination;
	s = source;
	i = 0;
	while (i < size)
	{
		d[i] = s [i];
		i++;
	}
	return (destination);
}
