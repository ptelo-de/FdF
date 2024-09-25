/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:34:39 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/09/23 23:35:45 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdF.h"

void	ft_arg_check(int argc, char **argv)
{
	if (argc > 2)
	{
		ft_putstr_fd("[fdf] ERROR - Too many arguments | Usage: ", 2);
		ft_putstr_fd("./fdf \"MAP PATH\"", 2);
		exit(1);
	}
	else if (argc == 1)
	{
		ft_putstr_fd("[fdf] ERROR - No arguments | Usage: ", 2);
		ft_putstr_fd("./fdf \"MAP PATH\"", 2);
		exit(1);
	}
	else if (ft_strncmp(*argv + ft_strlen(*argv) - 4, ".fdf", 4))
	{
		ft_putstr_fd("[fdf] ERROR - Invalid file extension | Usage: ", 2);
		ft_putstr_fd("./fdf \"MAP PATH\"", 2);
		exit(1);
	}
}
