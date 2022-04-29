/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:41:21 by swautele          #+#    #+#             */
/*   Updated: 2021/10/02 13:57:16 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t				i;
	unsigned char		*p;

	p = pointer;
	i = 0;
	while (i < count)
	{
		p[i] = value;
		i++;
	}
	return (pointer);
}
