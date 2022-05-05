/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:15:39 by swautele          #+#    #+#             */
/*   Updated: 2022/05/05 18:18:08 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ralloc_cut_string(char *str, size_t begin, size_t end)
{
	size_t	len;
	char	*new;
	size_t	i;
	size_t	j;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	if (begin > len || begin > end)
		return (str);
	new = calloc(len - (end - begin), sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (i < begin)
		{
			new[j] = str[i];
			j++;
		}
		if (i > end)
		{
			new[j] = str[i];
			j++;
		}
		i++;
	}
	free (str);
	return (new);
}
