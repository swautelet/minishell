/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:09:52 by swautele          #+#    #+#             */
/*   Updated: 2022/05/05 15:32:02 by simonwautel      ###   ########.fr       */
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

void	wr_heredoc(int fd, char *end)
{
	char	*buffer;
	// int		len;

	// len = 1;
	buffer = "";
	while (buffer)
	{
		buffer = readline(">");
		if (!buffer || endhere(buffer, end) == 0)
		{
			// printf("buffer = %p\n", buffer);
			free (buffer);
			break ;
		}
		write (fd, buffer, ft_strlen(buffer));
		write (fd, "\n", 1);
		// printf("buffer = %p\n", buffer);
		free (buffer);
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