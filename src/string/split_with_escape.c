/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_with_escape.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:35:37 by simonwautel       #+#    #+#             */
/*   Updated: 2022/05/18 16:13:19 by swautele         ###   ########.fr       */
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

static size_t	ft_count(const char *str, const char c)
{
	size_t	l;

	l = 0;
	while (*str)
	{
		while (*str && *str == c)
		{
			str++;
		}
		if (*str != c && *str)
			l++;
		while (*str && *str != c)
		{
			str++;
		}
	}
	return (l);
}

static int	ft_len(char *str, const char c)
{
	int		d;
	char	flag;

	d = 1;
	flag = 0;
	while (*str && (*str != c && flag == 0))
	{
		if (*str == "'"[0] || *str == '"')
			flag = *str;
		if (flag != 0)
		{
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
		i = 0;
		l++;
		r[l] = malloc (sizeof(char) * (ft_len(str, c)));
		if (r[l] == NULL)
		{
			ft_free(r, l);
			return ;
		}
		while (*str)
		{
			if ((*str == "'"[0] || *str == '"') && flag == 0)
			{
				flag = *str;
				// str++;
			}
			// if (*str != flag)
			r[l][i++] = *str++;
			if (*str == flag && flag != 0)
			{
				// str++;
				flag = 0;
			}
			if (*str == c && flag == 0)
				break ;
		}
		if (*str == c || *str == '\0')
			r[l][i] = '\0';
	}
}

char	**split_with_escape(char *str, char c)
{
	char	**r;

	if (!str)
		return (0);
	r = ft_calloc (sizeof(char *), ft_count(str, c) + 1);
	if (r == NULL)
		return (NULL);
	alloc_memory(r, str, c);
	return (r);
}
