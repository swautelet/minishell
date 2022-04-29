/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:38:37 by swautele          #+#    #+#             */
/*   Updated: 2021/09/27 15:35:43 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_sign(const char *str)
{
	int	s;

	s = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			s = s * (-1);
		}
		str++;
	}
	return (s);
}

int	ft_atoi(const char *str)
{
	int				s;
	unsigned int	nb;

	nb = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
	{
		str++;
	}
	s = ft_sign(str);
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		nb = nb * 10 + (*str - 48);
		str++;
	}
	if (s == -1 && nb > 2147483648)
		return (0);
	if (s == 1 && nb > 2147483647)
		return (-1);
	return (nb * s);
}
