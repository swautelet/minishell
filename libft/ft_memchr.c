/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:40:10 by swautele          #+#    #+#             */
/*   Updated: 2022/05/04 16:05:36 by simonwautel      ###   ########.fr       */
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
