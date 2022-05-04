/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:09:52 by swautele          #+#    #+#             */
/*   Updated: 2022/05/04 14:05:37 by simonwautel      ###   ########.fr       */
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
	if (!*end && *buffer == '\n')
		return (0);
	else
		return (1);
}

void	wr_heredoc(int fd, char *end)
{
	char	buffer[300];
	int		len;

	len = 1;
	while (len != 0)
	{
		len = read(0, buffer, 300);
		if (endhere(buffer, end) == 0)
			break ;
		write (fd, buffer, len);
	}
}

int	create_heredoc(char *end)
{
	int	fd;

	fd = open("/tmp/iwe.tmp", O_CREAT | O_WRONLY | O_TRUNC, 00777);
	wr_heredoc(fd, end);
	close (fd);
	fd = open("/tmp/iwe.tmp", O_RDONLY, 00777);
	unlink("/tmp/iwe.tmp");
	return (fd);
}