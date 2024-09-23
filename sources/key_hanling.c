/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hanling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:05:03 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/09/23 22:05:42 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdF.h"

int handle_keypress(int keycode, t_vars *vars) 
{
    printf("Key pressed: %d\n", keycode); // Print the key code
    if (keycode == 65307) { // ESC key on school keybord del
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0); // Exit the program if ESC is pressed
    }
    return (0);
}