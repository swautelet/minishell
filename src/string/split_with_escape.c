/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_with_escape.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:35:37 by simonwautel       #+#    #+#             */
/*   Updated: 2022/05/05 18:51:31 by simonwautel      ###   ########.fr       */
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
	char	*next;

	d = 1;
	while (*str && *str != c)
	{
		next = find_next_element(str, 0);
		d += ft_strlen(next);
		str += ft_strlen(next);
		// printf("next = %p\n", next);
		free (next);
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
				flag = *str;
			r[l][i++] = *str++;
			if (*str == c && flag == 0)
				break ;
			if ((*str == "'"[0] || *str == '"') && flag != 0)
				flag = 0;
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
