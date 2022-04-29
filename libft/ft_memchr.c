/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:40:10 by swautele          #+#    #+#             */
/*   Updated: 2021/09/13 13:55:37 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *memoryblock, int searched, size_t size)
{
	unsigned char	*s;

	s = (unsigned char *)memoryblock;
	while (size > 0)
	{
		if (*s == (unsigned char)searched)
		{
			return (s);
		}
		s++;
		size--;
	}
	return (NULL);
}
