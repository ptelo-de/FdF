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

void ft_charslinecheck(char *line)
{
    int i;
    int j;

    i = 0;
    while (line[i])
    {
        while (line[i] == 32 || line[i] == '\n')
            i++;
        
        j = 0;
        while (line[i + j] && line[i + j] != 32 && line[i + j] != '\n')
            j++;

        if (j > 0)
            ft_atoi2(ft_substr(line, i, j), 0, 1);

        i += j;
    }
}
void ft_charscheck(char *file_path)
{
	int fd;
	char *line_reader;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_putstr_fd("[fdf] ERROR - fd not work in parsing\n", 2);
	line_reader = get_next_line(fd);
	while(line_reader)
	{
		ft_charslinecheck(line_reader);
		line_reader = get_next_line(fd);
	}
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
