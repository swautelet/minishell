/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_with_escape.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:35:37 by simonwautel       #+#    #+#             */
/*   Updated: 2022/05/24 13:18:12 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free(char **r, int l)
{
	while (l >= 0)
	{
		free(r[l]);
		l--;
	}
	free(r);
}

static int	ft_len(char *str, const char c)
{
	int		d;
	char	flag;

	d = 1;
	flag = 0;
	while (*str && *str != c)
	{
		if (*str == "'"[0] || *str == '"')
			flag = *str;
		if (flag != 0)
		{
			str++;
			while (*str != flag)
			{
				d++;
				str++;
			}
			flag = 0;
		}
		d++;
		str++;
	}
	return (d);
}

static char	*skip_token(char *str, char c, int l, char **r)
{
	char	flag;
	int		i;

	i = 0;
	while (*str)
	{
		if ((*str == "'"[0] || *str == '"') && flag == 0)
			flag = *str;
		r[l][i++] = *str;
		str++;
		if (*str == flag && flag != 0)
		{
			flag = 0;
			r[l][i++] = *str;
			str++;
		}
		if (*str == c && flag == 0)
			break ;
	}
	return (str);
}

static void	alloc_memory(char **r, char *str, char c)
{
	size_t	i;
	size_t	l;
	char	flag;

	l = -1;
	flag = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (!*str)
			break ;
		l++;
		r[l] = ft_calloc(sizeof(char), (ft_len(str, c) + 1));
		if (r[l] == NULL)
			return (ft_free(r, l));
		str = skip_token(str, c, l, r);
	}
}

char	**split_with_escape(char *str, char c)
{
	char	**r;

	if (!str)
		return (0);
	r = ft_calloc(sizeof(char *), ft_count(str, c) + 1);
	if (r == NULL)
		return (NULL);
	alloc_memory(r, str, c);
	return (r);
}
