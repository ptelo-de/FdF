/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:09:37 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/09/23 23:34:13 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://qst0.github.io/ft_libgfx/man_mlx.html

#include "../includes/fdF.h"

int	main(int ac, char **av)
{
	int	fd;
	
	ft_arg_check(ac, ++av);
	fd = open(argv[1], O_RDONLY);
	if (fd >= 0)
	{
		ft_file_to_array(fd);
	}
	else
		ft_putstr_fd("[fdf] ERROR - Invalid map or map path\n", 2);
	
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