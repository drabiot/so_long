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
	map->tx->wall[0] = mlx_load_png("./textures/wall_up.png");
	map->tx->wall[1] = mlx_load_png("./textures/wall_right.png");
	map->tx->wall[2] = mlx_load_png("./textures/wall_down.png");
	map->tx->wall[3] = mlx_load_png("./textures/wall_left.png");
	map->tx->corner[0] = mlx_load_png("./textures/corner_ul.png");
	map->tx->corner[1] = mlx_load_png("./textures/corner_ur.png");
	map->tx->corner[2] = mlx_load_png("./textures/corner_dr.png");
	map->tx->corner[3] = mlx_load_png("./textures/corner_dl.png");
	map->tx->obstacle[0] = mlx_load_png("./textures/pot.png");
	map->tx->collectible[0] = mlx_load_png("./textures/collectible.png");
	map->tx->collectible[1] = mlx_load_png("./textures/collectible1.png");
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
	map->img->wall[0] = mlx_texture_to_image(map->mlx, map->tx->wall[0]);
	map->img->wall[1] = mlx_texture_to_image(map->mlx, map->tx->wall[1]);
	map->img->wall[2] = mlx_texture_to_image(map->mlx, map->tx->wall[2]);
	map->img->wall[3] = mlx_texture_to_image(map->mlx, map->tx->wall[3]);
	map->img->corner[0] = mlx_texture_to_image(map->mlx, map->tx->corner[0]);
	map->img->corner[1] = mlx_texture_to_image(map->mlx, map->tx->corner[1]);
	map->img->corner[2] = mlx_texture_to_image(map->mlx, map->tx->corner[2]);
	map->img->corner[3] = mlx_texture_to_image(map->mlx, map->tx->corner[3]);
	map->img->obstacle[0] = mlx_texture_to_image(map->mlx, map->tx->obstacle[0]);
	map->img->collectible[0] = mlx_texture_to_image(map->mlx, map->tx->collectible[0]);
	map->img->collectible[1] = mlx_texture_to_image(map->mlx, map->tx->collectible[1]);
	map->img->exit[0] = mlx_texture_to_image(map->mlx, map->tx->exit[0]);
	map->img->exit[1] = mlx_texture_to_image(map->mlx, map->tx->exit[1]);
}

void	init_png(t_map *map)
{
	png_to_texture(map);
	texture_to_image(map);
}
