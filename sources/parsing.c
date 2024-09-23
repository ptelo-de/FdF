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
		ft_printf("[fdf] ERROR - Too many arguments | Usage: ");
		ft_printf("./fdf \"MAP PATH\"");
		exit(0);
	}
	else if (argc == 1)
	{
		ft_printf("[fdf] ERROR - No arguments | Usage: ");
		ft_printf("./fdf \"MAP PATH\"");
		exit(0);
	}
	else if (ft_strncmp(*argv + ft_strlen(*argv) - 4, ".fdf", 4))
	{
		ft_printf("[fdf] ERROR - Invalid file extension | Usage: ");
		ft_printf("./fdf \"MAP PATH\"");
		exit(0);
	}
}
