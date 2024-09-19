/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:09:37 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/09/19 17:18:05 by ptelo-de         ###   ########.fr       */
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
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	ft_close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
int	main(void)
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
	
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);

	mlx_loop(vars.mlx);//initiates window rendering
}

//mlx_pixel_put function is very, very slow. This is because it tries to push the pixel instantly to the window (without waiting for the frame to be entirely rendered).
// Because of this sole reason, we will have to buffer all of our pixels to a image, which we will then push to the window.
//To write pixels to an image we must declare bpp var., also called the bits per pixel, pixel is int
//what is bit plane?
//TRGB 0xTTRRGGBB
//hooks : Event Listeners: Are a specific type of hook that listens for events and invokes callback functions in response.
// Hooking alias: mlx_expose_hook function is an alias of mlx_hook on expose event (12)
// Hooking alias: mlx_key_hook function is an alias of mlx_hook on key up event (3).
// Hooking alias: mlx_mouse_hook function is an alias of mlx_hook on mouse down event (4)