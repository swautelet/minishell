/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:28:18 by swautele          #+#    #+#             */
/*   Updated: 2022/05/02 19:47:42 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include "libft.h"
# include "pipex.h"

typedef struct s_command{
	char	*str;
	int		fdin;
	int		fdout;
}	t_param;

char	**ft_split(char const *str, char c);
char	*my_cut_string(char *str, size_t begin, size_t end);
size_t	ft_strlen(const char *str);
char	*find_next_element(char *str, int i);
void	just_parse_it(t_param *data);
void	*ft_calloc(size_t count, size_t size);
int		create_heredoc(char *end);

#endif
