/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:12:40 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/09/23 23:35:22 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "../minilibx-linux/mlx.h"
#include "libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h> //readonlymacro

typedef struct s_2d_point
{
	double	x;
	double	y;
	struct s_2d_point *next;
    //double :variable with 64 bits, 
    //theerefore precision of 15 casasdec.
}	t_2d_point;



typedef struct s_line{
	int line_index;
	t_2d_point *pos;
	struct s_line *next_line;

}t_line;






//parsing
void	ft_arg_check(int argc, char **argv);
void ft_charscheck(char *file_path);

//init
void ft_file_to_lines(char *fd);

//lineutils
void ft_linescheck(t_line **lines, int i, char *gnl);
void ft_free_lines(t_line *lines);

//print lines
void ft_print_line(t_line *line);

#endif