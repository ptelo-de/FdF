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
	struct t_2d_point *next;
    //double :variable with 64 bits, 
    //theerefore precision of 15 casasdec.
}	t_2d_point;



typedef struct s_line{
	int line_index;
	t_2d_point *pos;
	struct t_line *next_line;
	char *s;

}t_line;






//parsing
void	ft_arg_check(int argc, char **argv);
void ft_charscheck(char *file_path);

//init
void ft_file_to_lines(char *fd);

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;
// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;


// enum {
// 	ON_KEYDOWN = 2,
// 	ON_KEYUP = 3,
// 	ON_MOUSEDOWN = 4,
// 	ON_MOUSEUP = 5,
// 	ON_MOUSEMOVE = 6,
// 	ON_EXPOSE = 12,
// 	ON_DESTROY = 17
// 	//based on X11 protocol
// };

// int	create_trgb(int t, int r, int g, int b);
// int handle_keypress(int keycode, t_vars *vars);

#endif