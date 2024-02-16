/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:32:29 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/16 14:32:56 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	texture_numbers(t_map *map)
{
	map->tx->number[0] = mlx_load_png("./textures/0.png");
	map->tx->number[1] = mlx_load_png("./textures/1.png");
	map->tx->number[2] = mlx_load_png("./textures/2.png");
	map->tx->number[3] = mlx_load_png("./textures/3.png");
	map->tx->number[4] = mlx_load_png("./textures/4.png");
	map->tx->number[5] = mlx_load_png("./textures/5.png");
	map->tx->number[6] = mlx_load_png("./textures/6.png");
	map->tx->number[7] = mlx_load_png("./textures/7.png");
	map->tx->number[8] = mlx_load_png("./textures/8.png");
	map->tx->number[9] = mlx_load_png("./textures/9.png");
}

void	image_numbers(t_map *map)
{
	map->img->number[0] = mlx_texture_to_image(map->mlx, map->tx->number[0]);
	map->img->number[1] = mlx_texture_to_image(map->mlx, map->tx->number[1]);
	map->img->number[2] = mlx_texture_to_image(map->mlx, map->tx->number[2]);
	map->img->number[3] = mlx_texture_to_image(map->mlx, map->tx->number[3]);
	map->img->number[4] = mlx_texture_to_image(map->mlx, map->tx->number[4]);
	map->img->number[5] = mlx_texture_to_image(map->mlx, map->tx->number[5]);
	map->img->number[6] = mlx_texture_to_image(map->mlx, map->tx->number[6]);
	map->img->number[7] = mlx_texture_to_image(map->mlx, map->tx->number[7]);
	map->img->number[8] = mlx_texture_to_image(map->mlx, map->tx->number[8]);
	map->img->number[9] = mlx_texture_to_image(map->mlx, map->tx->number[9]);
}

static void	display_numbers(t_map *map, int x, int y)
{
	mlx_image_to_window(map->mlx, map->img->number[0], x, y);
	mlx_image_to_window(map->mlx, map->img->number[1], x, y);
	mlx_image_to_window(map->mlx, map->img->number[2], x, y);
	mlx_image_to_window(map->mlx, map->img->number[3], x, y);
	mlx_image_to_window(map->mlx, map->img->number[4], x, y);
	mlx_image_to_window(map->mlx, map->img->number[5], x, y);
	mlx_image_to_window(map->mlx, map->img->number[6], x, y);
	mlx_image_to_window(map->mlx, map->img->number[7], x, y);
	mlx_image_to_window(map->mlx, map->img->number[8], x, y);
	mlx_image_to_window(map->mlx, map->img->number[9], x, y);
}

void	display_counter(t_map *map)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		display_numbers(map, i * SPRITE_PIXEL, 0);
		map->img->number[1]->instances[i].enabled = 0;
		map->img->number[2]->instances[i].enabled = 0;
		map->img->number[3]->instances[i].enabled = 0;
		map->img->number[4]->instances[i].enabled = 0;
		map->img->number[5]->instances[i].enabled = 0;
		map->img->number[6]->instances[i].enabled = 0;
		map->img->number[7]->instances[i].enabled = 0;
		map->img->number[8]->instances[i].enabled = 0;
		map->img->number[9]->instances[i].enabled = 0;
		i++;
	}
}
