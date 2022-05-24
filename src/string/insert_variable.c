/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:25:57 by simonwautel       #+#    #+#             */
/*   Updated: 2022/05/24 17:11:14 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_name_variable(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 1;
	if (is_whitespace(str[1]) || !str[1])
		return (NULL);
	while (str && str[++i])
	{
		if (str[1] == '(')
		{
			if (str[i] == ')')
			{
				j++;
				break ;
			}
		}
		else if (ft_isalnum(str[i]) == FALSE && str[i] != '?')
			break ;
	}
	ret = ft_calloc(sizeof(char), i + 1);
	while (--i >= j)
		ret[i - j] = str[i];
	return (ret);
}

char	*find_variable(char *name)
{
	if (!name || !*name)
		return (NULL);
	if (ft_strncmp(name, "?", 2) == 0)
		return (ft_itoa(g_data->lastex));
	return (my_getenv(g_data, name));
}

char	*ralloc_insert_string(char *str, int insert, char *var)
{
	int		i;
	int		j;
	char	*ret;

	i = -1;
	if (var == NULL)
		return (str);
	ret = ft_calloc(ft_strlen(str) + ft_strlen(var) + 1, sizeof(char));
	while (str[++i] && i < insert)
		ret[i] = str[i];
	j = -1;
	while (var && var[++j])
		ret[i + j] = var[j];
	i--;
	while (str[++i])
		ret[i + j] = str[i];
	free(str);
	return (ret);
}

char	*insert_variable(char *str)
{
	t_var	t;

	t.flag = 0;
	t.i = -1;
	while (str && str[++t.i])
	{
		if (t.flag == 0 && (str[t.i] == "'"[0] || str[t.i] == '"'))
			t.flag = str[t.i];
		else if ((t.flag == "'"[0] || t.flag == '"') && str[t.i] == t.flag)
			t.flag = 0;
		if (str[t.i] == '$' && t.flag != "'"[0])
		{
			t.name = find_name_variable(&str[t.i]);
			t.var = find_variable(t.name);
			if (str[t.i + 1] != '(')
				str = ralloc_cut_string(str, t.i, t.i + ft_strlen(t.name));
			else
				str = ralloc_cut_string(str, t.i, t.i + ft_strlen(t.name) + 2);
			str = ralloc_insert_string(str, t.i, t.var);
			if (ft_strncmp(t.name, "?", 2) == 0)
				free(t.var);
			free(t.name);
		}
	}
	return (str);
}
