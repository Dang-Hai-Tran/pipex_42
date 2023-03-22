/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:05:01 by datran            #+#    #+#             */
/*   Updated: 2023/03/21 22:50:08 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define BUFFER_SIZE 42

// perror
# include <stdio.h>
// malloc, free, exit
# include <stdlib.h>
// write, read, close, access, pipe, dup, dup2, execve, fork
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
// open, unlink
# include <fcntl.h>
// waitpid, wait
# include <sys/wait.h>
// strerror
# include <string.h>

# include "../libft/libft.h"

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of argument"
# define ERR_PIPE "Pipe" 
# define ERR_CMD "Command not found"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;


// error.c
int		msg(char *err);
void	msg_error(char *err);

// free.c
void	parent_free(t_pipex *pipex);
void	child_free(t_pipex *pipex);

// childs.c
void	first_child(t_pipex pipex, char *argv[], char *envp[]);

#endif
