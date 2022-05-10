/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:25:57 by simonwautel       #+#    #+#             */
/*   Updated: 2022/05/10 17:14:20 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

char	*find_name_variable(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = -1;
	j = 1;
	while (str && str[++i])
	{
		if (str[1] == '(')
		{
			if (str[i] -- ')')
			{
				j++;
				break ;
			}
		}
		else
		{
			if (data->str[i] == ' ' || data->str[i] == '\f' || data->str[i] == '\n' || data->str[i] == '\r'
				|| data->str[i] == '\t' || data->str[i] == '\v')
				break ;
		}
	}
	ret = ft_calloc(sizeof(char), i + 1);
	while (--i >= j)
		ret[i - j] = str[i];
	return (ret);
}

char	*find_variable(char *name)
{
	return (getenv(name));
}

char	*ralloc_insert_string(char *str, int insert, char *var)
{
	int		i;
	int		j;
	char	*ret;

	i = -1;
	ret = ft_calloc(ft_strlen(str) + ft_strlen(var) + 1, sizeof(char));
	while (str[i] && ++i < insert)
		ret[i] = str[i];
	j = -1;
	while (var && var[++j])
		ret[i + j] = var[j];
	i--;
	while (str[++i])
		ret[i + j] = str[i];
	free (str);
	return (ret);
}

char	*insert_variable(char *str)
{
	char	flag;
	int		i;
	char	*name;
	char	*var;

	flag = 0;
	i = -1;
	while (str && str[++i])
	{
		if (flag == 0 && (str[i] == "'"[0] || str[i] == '"'))
			flag = str[i];
		if ((flag == "'"[0] || flag == '"') && str[i] == flag)
			flag = 0;
		if (str[i] == '$' && flag != "'"[0])
		{
			name = find_name_variable(&str[i]);
			var = find_variable(name);
			str = ralloc_cut_string(str, i, i + ft_strlen(name));
			str = ralloc_insert_string(str, i, var);
			free (name);
			// free (var);
		}
	}
	return (str);
}
