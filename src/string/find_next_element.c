/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:42:12 by swautele          #+#    #+#             */
/*   Updated: 2022/04/28 17:56:04 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_next_element(char *str, int i)
{
	int		j;
	char	begin;
	char	*new;
	int		k;

	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == "'"[0])
		begin = str[i++];
	else if (str[i] == '"')
		begin = str[i++];
	else
		begin = 0;
	j = 0;
	if (begin != 0)
	{
		while (str[i + j] != begin)
			j++;
	}
	else
	{
		while (str[i] != ' ' || str[i] != '\f' || str[i] != '\n'
			|| str[i] != '\r' || str[i] != '\t' || str[i] != '\v')
			j++;
	}
	new = malloc(j + 1);
	if (!new)
		return (NULL);
	k = -1;
	while (++k < j)
		new[k] = str[i + k];
	return (new);
}
