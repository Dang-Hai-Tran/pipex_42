/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:05:01 by datran            #+#    #+#             */
/*   Updated: 2023/03/24 15:55:23 by datran           ###   ########.fr       */
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

# define ERR_INFILE "Cant open input file"
# define ERR_OUTFILE "Cant create output file"
# define ERR_NUMS_ARGS "Number of arguments is invalid"
# define ERR_PIPE "Cant pipe"
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
void	msg_error(char *err);
void	msg_perror(char *err);

// free.c
void	close_pipes(t_pipex *pipex);
void	close_in_out(t_pipex *pipex);
void	free_cmd_paths(t_pipex *pipex);

// childs.c
void	first_redirect(t_pipex pipex, char **argv, char **envp);
void	second_redirect(t_pipex pipex, char **argv, char **envp);

#endif
