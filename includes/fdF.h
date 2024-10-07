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

//	Screen Resolution
# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

typedef struct s_3d_point
{
	double	x;
	double	y;
	double	z;
	struct s_3d_point *next;
    //double :variable with 64 bits, 
    //theerefore precision of 15 casasdec.
}	t_3d_point;



typedef struct s_line{
	int line_index;
	t_3d_point *pos;
	struct s_line *next_line;

}t_line;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	//0 for little-endian, 1 for big-endian
	//Endianness determines how multi-byte pixel data is stored in memory.
}				t_img;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	t_img			*img;
	struct s_line *map;
}				t_mlx; 




//parsing
int	ft_arg_check(int argc, char **argv);
int ft_charscheck(char *file_path);

//init
t_line *ft_file_to_lines(char *fd, int number_lines);

//lineutils
void ft_linescheck(t_line **lines, int i, char *gnl);
void ft_free_lines(t_line *lines);

//print lines
void ft_print_line(t_line *line);

//draw
 void	ft_mlx_init(t_mlx *mlx, t_line *map);
 void    draw_pixels(t_mlx *mlx, int color);
 void	draw_pixel(t_img *img, int x, int y, int color);

#endif