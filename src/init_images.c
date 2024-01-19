/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:22:09 by tchartie          #+#    #+#             */
/*   Updated: 2024/01/17 18:51:31 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/ft_printf.h"

static void png_to_texture(t_map *map)
{
	map->tx = malloc(sizeof(t_textures));
	if (!map->tx)
		return ;
	map->tx->floor[0] = mlx_load_png("./textures/floor.png");
	map->tx->floor[1] = mlx_load_png("./textures/floor2.png");
	map->tx->floor[2] = mlx_load_png("./textures/floor3.png");
	map->tx->player = mlx_load_png("./textures/player.png");
	map->tx->wall = mlx_load_png("./textures/wall.png");
	map->tx->collectible = mlx_load_png("./textures/collectible.png");
	map->tx->exit[0] = mlx_load_png("./textures/close_exit.png");
	map->tx->exit[1] = mlx_load_png("./textures/open_exit.png");
}

static void	texture_to_image(t_map *map)
{
	map->img = malloc(sizeof(t_images));
	if (!map->img)
		return ;
	map->img->floor[0] = mlx_texture_to_image(map->mlx, map->tx->floor[0]);
	map->img->floor[1] = mlx_texture_to_image(map->mlx, map->tx->floor[1]);
	map->img->floor[2] = mlx_texture_to_image(map->mlx, map->tx->floor[2]);
	map->img->player = mlx_texture_to_image(map->mlx, map->tx->player);
	map->img->wall = mlx_texture_to_image(map->mlx, map->tx->wall);
	map->img->collectible = mlx_texture_to_image(map->mlx, map->tx->collectible);
	map->img->exit[0] = mlx_texture_to_image(map->mlx, map->tx->exit[0]);
	map->img->exit[1] = mlx_texture_to_image(map->mlx, map->tx->exit[1]);
}

void	init_png(t_map *map)
{
	png_to_texture(map);
	texture_to_image(map);
}
