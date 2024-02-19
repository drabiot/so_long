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

/*
** Generate the textures of the numbers
*/
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
	map->tx->number[10] = mlx_load_png("./textures/separator.png");
}

/*
** Convert the textures of the numbers into images
*/
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
	map->img->number[10] = mlx_texture_to_image(map->mlx, map->tx->number[10]);
}

/*
** Place the numbers in the correct positions within the given position
*/
static void	display_numbers(t_map *map, int x)
{
	int	y;

	y = -(SPRITE_PIXEL / 16);
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

/*
** Place the banner behind the numbers and behind any potential numbers
*/
static void	display_layout_banner(t_map *map)
{
	int	i;
	int	wdt;
	int	hgt;

	i = 0;
	hgt = (map->height - 1) * SPRITE_PIXEL;
	while (i < 5)
	{
		wdt = i * SPRITE_PIXEL;
		mlx_image_to_window(map->mlx, map->img->banner[5], wdt, hgt);
		if (i != 0)
			map->img->banner[5]->instances[i].enabled = 0;
		i++;
	}
}

/*
** Place the numbers in the correct positions within the game
** & place the banner in the right place
*/
void	display_counter(t_map *map)
{
	int	i;

	i = 0;
	mlx_image_to_window(map->mlx, map->img->banner[4], 0, 0);
	display_layout_banner(map);
	while (i < 3)
	{
		display_numbers(map, i * SPRITE_PIXEL);
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
	display_numbers_coll(map);
}
