/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:43:26 by swautele          #+#    #+#             */
/*   Updated: 2021/09/13 18:42:23 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_len2(const char *s1, const char *del)
{
	size_t	i;
	size_t	l;
	size_t	len;

	i = 0;
	len = 0;
	while (s1[i])
		i++;
	l = 0;
	i--;
	while (del[l] && i > 0)
	{
		if (s1[i] == del[l])
		{
			len = len + 1;
			l = (-1);
			i--;
		}
		l++;
	}
	return (len);
}

static size_t	ft_len(const char *s1, const char *del)
{
	size_t	len;
	size_t	i;
	size_t	l;

	i = 0;
	len = ft_strlen(s1);
	l = 0;
	while (del[l])
	{
		if (s1[i] == del[l])
		{
			len = len - 1;
			l = -1;
			i++;
		}
		l++;
	}
	if (!s1[i])
		return (0);
	len = len - ft_len2(s1, del);
	return (len);
}

char	*ft_strtrim(const char *s1, const char *del)
{
	size_t	l;
	size_t	i;
	size_t	len;
	char	*r;

	if (!s1 || !del)
		return (NULL);
	len = ft_len(s1, del);
	r = malloc(len + 1);
	if (r == NULL)
		return (NULL);
	i = 0;
	l = -1;
	while (del[++l])
	{
		if (*s1 == del[l])
		{
			s1++;
			l = -1;
		}
	}
	while (len-- > 0)
		r[i++] = *s1++;
	r[i] = '\0';
	return (r);
}
