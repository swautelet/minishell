/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:53:40 by simonwautel       #+#    #+#             */
/*   Updated: 2022/05/09 15:01:19 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

char	*find_next_name(t_param *data, int i)
{
		int		j;
	char	begin;
	char	*new;
	int		k;

	while (data->str[i] == ' ' || data->str[i] == '\f' || data->str[i] == '\n' || data->str[i] == '\r'
		|| data->str[i] == '\t' || data->str[i] == '\v')
		i++;
	if (!data->str[i])
		return (NULL);
	else if (data->str[i] == "'"[0] || data->str[i] == '"')
	{
		begin = data->str[i++];
		// data->str = ralloc_cut_string(data->str, i, i);
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
				// data->str = ralloc_cut_string(data->str, i + j, i + j);
				break ;
			}
		}
		// i have to correct this 
		// printf("str[i + j] = %c\n", str[i + j]);
		// if (!str[i + j])
			// str = find_next_escape(begin, i + j, str, 1);
	}
	else
	{
		while (data->str[i+ j] && data->str[i + j] != ' ' && data->str[i + j] != '\f' && data->str[i + j] != '\n'
			&& data->str[i + j] != '\r' && data->str[i + j] != '\t' && data->str[i + j] != '\v')
		{
			j++;
			if (data->str[i + j] == "'"[0] || data->str[i + j] == '"')
			{
				return (find_next_element(data, i + j));
			}
		}
	}
	new = calloc(j + 1, sizeof(char));
	if (!new)
		return (NULL);
	k = 0;
	while (k++ < j)
		new[k] = data->str[i + k];
	return (new);
}