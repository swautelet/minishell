/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:28:18 by swautele          #+#    #+#             */
/*   Updated: 2022/04/28 19:27:10 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
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
