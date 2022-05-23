/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:43:07 by swautele          #+#    #+#             */
/*   Updated: 2022/05/23 18:03:07 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *first, const char *second, size_t len)
{
	if (first == NULL && second == NULL)
		return (0);
	else if (!first || !second)
		return (-1);
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
