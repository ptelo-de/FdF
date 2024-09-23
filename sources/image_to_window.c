/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:09:01 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/09/23 22:10:41 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdF.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color) //pushing pixel to image, mind overlaping image input, need to store images
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	printf("adress%s\n", dst);//is empty and should not
	
}

void image_to_window(void)
{
	t_vars vars;
	t_data	img;

	vars.mlx = mlx_init(); //processo, location of minilibx instance (instance ?)
	
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!"); //returns a pointer to the window it creates, the window closes with ctrl c
	
	img.img = mlx_new_image(vars.mlx, 1920, 1080);//retona uma grelha de pixels?
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 15, 35, create_trgb(0, 255, 255, 255));
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
//	mlx_loop_hook(vars.mlx, render_next_frame, YourStruct);
	mlx_hook(vars.win, 2, 1L<<0, handle_keypress, &vars);

	mlx_loop(vars.mlx);//initiates window rendering
}