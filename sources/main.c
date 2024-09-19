/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:09:37 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/09/19 13:44:39 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://qst0.github.io/ft_libgfx/man_mlx.html

#include "../includes/fdF.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color) //pushing pixel to image, mind overlaping image input, need to store images
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	printf("adress%s\n", (unsigned char*)dst);//is empty and should not
	
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init(); //processo, location of minilibx instance (instance ?)
	
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!"); //returns a pointer to the window it creates, the window closes with ctrl c
	
	img.img = mlx_new_image(mlx, 1920, 1080);//retona uma grelha de pixels?
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);//initiates window rendering
}

//mlx_pixel_put function is very, very slow. This is because it tries to push the pixel instantly to the window (without waiting for the frame to be entirely rendered).
// Because of this sole reason, we will have to buffer all of our pixels to a image, which we will then push to the window.
//To write pixels to an image we must declare bpp var., also called the bits per pixel, pixel is int
//what is bit plane?