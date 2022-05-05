/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:42:12 by swautele          #+#    #+#             */
/*   Updated: 2022/05/05 17:22:22 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_closure(char *str, char begin)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == begin)
			return (0);
		i++;
	}
	return (1);
}

char	*find_next_escape(char begin, int i, char *str)
{
	int		start;
	char	flag;
	char	*add;
	char	*new;

	start = i;
	flag = 0;
	while (str[++i])
	{
		if (str[i] == begin && flag == 0)
			flag++;
		if (str[i] == begin && flag == 1)
		{
			flag--;
			break ;
		}
	}
	new = str;
	if (flag == 1)
	{
		add = readline("dquote>");
		new = ft_strjoin(str, add);
		free (str);
		free (add);
		if (find_closure(new, begin))
			new = find_next_escape(begin, i, new);
		// while (find_closure(&new[i], begin))
		// {
		// 	add = readline("dquote>");
		// 	new = ft_strjoin(new, add);
		// 	free (str);
		// 	free (add);
		// }
	}
	return (new);
}

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
		while (str[i + j] != ' ' && str[i + j] != '\f' && str[i + j] != '\n'
			&& str[i + j] != '\r' && str[i + j] != '\t' && str[i + j] != '\v')
			j++;
	}
	new = calloc(j + 1, sizeof(char));
	if (!new)
		return (NULL);
	k = -1;
	while (++k < j)
		new[k] = str[i + k];
	return (new);
}
