/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:53:40 by simonwautel       #+#    #+#             */
/*   Updated: 2022/05/16 16:40:16 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

char	*find_next_name(t_param *data, int i)
{
	int		j;
	char	begin;
	char	*new;
	int		k;

	while (is_whitespace(data->str[i]) == TRUE)
		i++;
	if (!data->str[i])
		return (NULL);
	else if (data->str[i] == "'"[0] || data->str[i] == '"')
	{
		begin = data->str[i++];
	}
	else
		begin = 0;
	j = 0;
	if (begin != 0)
	{
		while (data->str[i + j] && data->str[i + j] != begin)
		{
			j++;
			if (!data->str[i + j])
			{
				data->str = find_next_escape(data->str);
			}
			else if (data->str[i + j] == begin)
			{
				break ;
			}
		}
	}
	else
	{
		while (data->str[i + j] && is_whitespace(data->str[i + j]) == FALSE)
		{
			j++;
			if ((data->str[i + j] == "'"[0] || data->str[i + j] == '"') && begin == 0)
			{
				begin = data->str[i + j];
			}
			else if (data->str[i + j] == begin && begin != 0)
			{
				begin = 0;
			}
			else if (!data->str[i + j] && begin != 0)
			{
				data->str = find_next_escape(data->str);
			}
		}
	}
	new = calloc(j + 1, sizeof(char));
	if (!new)
		return (NULL);
	k = -1;
	while (++k < j)
		new[k] = data->str[i + k];
	return (new);
}
