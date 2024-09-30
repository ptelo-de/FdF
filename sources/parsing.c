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

void ft_charscheck(char *file_path)
{
	int fd;
	char *line_reader;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_putstr_fd("[fdf] ERROR - fd not work in parsing\n", 2);
	line_reader = get_next_line(fd);
	free(line_reader);
	close(fd);
}
void	ft_arg_check(int ac, char **av)
{
	if (ac > 2)
	{
		ft_putstr_fd("[fdf] ERROR - Too many arguments | Usage: ", 2);
		ft_putstr_fd("./fdf \"MAP PATH\"", 2);
		exit(1);
	}
	else if (ac == 1)
	{
		ft_putstr_fd("[fdf] ERROR - No arguments | Usage: ", 2);
		ft_putstr_fd("./fdf \"MAP PATH\"", 2);
		exit(1);
	}
	else if (ft_strncmp(*av + ft_strlen(*av) - 4, ".fdf", 4))
	{
		ft_putstr_fd("[fdf] ERROR - Invalid file extension | Usage: ", 2);
		ft_putstr_fd("./fdf \"MAP PATH\"", 2);
		exit(1);
	}
	ft_charscheck(*av);
}
