/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:09:52 by swautele          #+#    #+#             */
/*   Updated: 2022/04/28 19:29:11 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	endhere(char *buffer, char *end)
{
	while (*end && *buffer && *buffer == *end)
	{
		end++;
		buffer++;
	}
	if (!*end && !*buffer)
		return (0);
	else
		return (1);
}

static void	wr_heredoc(int fd, char *end)
{
	char	*buffer;
	int		len;

	len = 1;
	while (len != 0)
	{
		buffer = readline("here_doc>");
		if (endhere(buffer, end) == 0)
			break ;
		write (fd, buffer, ft_strlen(buffer));
	}
}

int	create_heredoc(char *end)
{
	int	fd;

	fd = open("/tmp/iwe.tmp", O_CREAT | O_WRONLY | O_TRUNC, 00777);
	wr_heredoc(fd, end);
	return (fd);
}