/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:08:50 by datran            #+#    #+#             */
/*   Updated: 2023/03/21 22:51:23 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	msg(char *err)
{
	ft_putendl_fd(err, 2);
	return (1);
}

void	msg_error(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}
