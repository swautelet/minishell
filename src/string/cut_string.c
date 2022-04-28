/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:15:39 by swautele          #+#    #+#             */
/*   Updated: 2022/04/28 15:38:27 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*cut_string(char *str, int begin, int end)
{
	size_t	len;
	char	*new;
	int		i;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	if (begin > len || begin >= end)
		return (str);
	new = malloc(len - (end - begin));
	if (!new)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		if (i < begin)
			new[i] = str[i];
		if (i > end)
			new[i - (end - begin)] = str[i];
	}
	free (str);
	return (new);
}
