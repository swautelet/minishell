/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:42:56 by swautele          #+#    #+#             */
/*   Updated: 2021/09/13 18:50:26 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char			*r;
	unsigned int	i;

	i = 0;
	if (!str || !f)
		return (NULL);
	r = malloc (sizeof (char) * (ft_strlen(str) + 1));
	if (r == NULL)
		return (NULL);
	while (str[i])
	{
		r[i] = f(i, str[i]);
		i++;
	}
	r[i] = '\0';
	return (r);
}
