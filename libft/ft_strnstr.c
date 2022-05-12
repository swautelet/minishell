/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:43:13 by swautele          #+#    #+#             */
/*   Updated: 2022/05/12 12:59:59 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *str, const char *searched, ssize_t n)
{
	size_t	i;

	if (str == searched || *searched == '\0')
		return ((char *)str);
	if (n == 0)
		return (NULL);
	while (*str && n - ft_strlen(searched) >= 0)
	{
		i = 0;
		while (str[i] == searched[i] && searched[i] && n - i > 0)
		{
			i++;
		}
		if (searched[i] == '\0')
			return ((char *)str);
		str++;
		n--;
	}
	return (NULL);
}
