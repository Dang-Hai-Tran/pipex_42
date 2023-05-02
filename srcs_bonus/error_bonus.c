/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:13:24 by datran            #+#    #+#             */
/*   Updated: 2023/05/01 23:14:22 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	ft_perror(char *str)
{
	ft_printf("Error\n");
	perror(str);
	exit(EXIT_FAILURE);
}
