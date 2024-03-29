/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:22:09 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/19 16:45:30 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/ft_printf.h"

static void	texture_walls(t_map *map)
{
	map->tx->floor[0] = mlx_load_png("./textures/floor.png");
	map->tx->floor[1] = mlx_load_png("./textures/floor2.png");
	map->tx->floor[2] = mlx_load_png("./textures/floor3.png");
	map->tx->wall[0] = mlx_load_png("./textures/wall_up.png");
	map->tx->wall[1] = mlx_load_png("./textures/wall_right.png");
	map->tx->wall[2] = mlx_load_png("./textures/wall_down.png");
	map->tx->wall[3] = mlx_load_png("./textures/wall_left.png");
	map->tx->corner[0] = mlx_load_png("./textures/corner_ul.png");
	map->tx->corner[1] = mlx_load_png("./textures/corner_ur.png");
	map->tx->corner[2] = mlx_load_png("./textures/corner_dr.png");
	map->tx->corner[3] = mlx_load_png("./textures/corner_dl.png");
	map->tx->obs[0] = mlx_load_png("./textures/pot.png");
	if (!map->tx->floor[0] || !map->tx->floor[1] || !map->tx->floor[2]
		|| !map->tx->wall[0] || !map->tx->wall[1] || !map->tx->wall[2]
		|| !map->tx->wall[3] || !map->tx->corner[0] || !map->tx->corner[1]
		|| !map->tx->corner[2] || !map->tx->corner[3] || !map->tx->obs[0])
	{
		destroy_walls_tx(map);
		free(map->tx);
		free_malloc_error(map);
	}
}

static void	png_to_texture(t_map *map)
{
	map->tx = malloc(sizeof(t_textures));
	if (!map->tx)
		return ;
	texture_walls(map);
	texture_numbers(map);
	map->tx->player[0] = mlx_load_png("./textures/player.png");
	map->tx->player[1] = mlx_load_png("./textures/player1.png");
	map->tx->collec[0] = mlx_load_png("./textures/collec.png");
	map->tx->collec[1] = mlx_load_png("./textures/collec1.png");
	map->tx->exit[0] = mlx_load_png("./textures/close_exit.png");
	map->tx->exit[1] = mlx_load_png("./textures/open_exit.png");
	map->tx->enemy[0] = mlx_load_png("./textures/enemy.png");
	map->tx->enemy[1] = mlx_load_png("./textures/enemy1.png");
	map->tx->banner[0] = mlx_load_png("./textures/banner_odd.png");
	map->tx->banner[1] = mlx_load_png("./textures/banner_even_top.png");
	map->tx->banner[2] = mlx_load_png("./textures/banner_even_bot.png");
	map->tx->banner[3] = mlx_load_png("./textures/banner_title.png");
	map->tx->banner[4] = mlx_load_png("./textures/layout_score.png");
	map->tx->banner[5] = mlx_load_png("./textures/layout_coll.png");
	if (!map->tx->player[0] || !map->tx->player[1] || !map->tx->collec[0]
		|| !map->tx->collec[1] || !map->tx->exit[0] || !map->tx->exit[1]
		|| !map->tx->enemy[0] || !map->tx->enemy[1] || !map->tx->banner[0]
		|| !map->tx->banner[1] || !map->tx->banner[2] || !map->tx->banner[3]
		|| !map->tx->banner[4] || !map->tx->banner[5])
		error_texture(map);
}

static void	image_walls(t_map *map)
{
	map->img->floor[0] = mlx_texture_to_image(map->mlx, map->tx->floor[0]);
	map->img->floor[1] = mlx_texture_to_image(map->mlx, map->tx->floor[1]);
	map->img->floor[2] = mlx_texture_to_image(map->mlx, map->tx->floor[2]);
	map->img->wall[0] = mlx_texture_to_image(map->mlx, map->tx->wall[0]);
	map->img->wall[1] = mlx_texture_to_image(map->mlx, map->tx->wall[1]);
	map->img->wall[2] = mlx_texture_to_image(map->mlx, map->tx->wall[2]);
	map->img->wall[3] = mlx_texture_to_image(map->mlx, map->tx->wall[3]);
	map->img->corner[0] = mlx_texture_to_image(map->mlx, map->tx->corner[0]);
	map->img->corner[1] = mlx_texture_to_image(map->mlx, map->tx->corner[1]);
	map->img->corner[2] = mlx_texture_to_image(map->mlx, map->tx->corner[2]);
	map->img->corner[3] = mlx_texture_to_image(map->mlx, map->tx->corner[3]);
	map->img->obs[0] = mlx_texture_to_image(map->mlx, map->tx->obs[0]);
	if (!map->img->floor[0] || !map->img->floor[1] || !map->img->floor[2]
		|| !map->img->wall[0] || !map->img->wall[1] || !map->img->wall[2]
		|| !map->img->wall[3] || !map->img->corner[0] || !map->img->corner[1]
		|| !map->img->corner[2] || !map->img->corner[3] || !map->img->obs[0])
		free_malloc_error(map);
}

static void	texture_to_image(t_map *map)
{
	map->img = malloc(sizeof(t_images));
	if (!map->img)
		return ;
	image_walls(map);
	image_numbers(map);
	map->img->player[0] = mlx_texture_to_image(map->mlx, map->tx->player[0]);
	map->img->player[1] = mlx_texture_to_image(map->mlx, map->tx->player[1]);
	map->img->collec[0] = mlx_texture_to_image(map->mlx, map->tx->collec[0]);
	map->img->collec[1] = mlx_texture_to_image(map->mlx, map->tx->collec[1]);
	map->img->exit[0] = mlx_texture_to_image(map->mlx, map->tx->exit[0]);
	map->img->exit[1] = mlx_texture_to_image(map->mlx, map->tx->exit[1]);
	map->img->enemy[0] = mlx_texture_to_image(map->mlx, map->tx->enemy[0]);
	map->img->enemy[1] = mlx_texture_to_image(map->mlx, map->tx->enemy[1]);
	map->img->banner[0] = mlx_texture_to_image(map->mlx, map->tx->banner[0]);
	map->img->banner[1] = mlx_texture_to_image(map->mlx, map->tx->banner[1]);
	map->img->banner[2] = mlx_texture_to_image(map->mlx, map->tx->banner[2]);
	map->img->banner[3] = mlx_texture_to_image(map->mlx, map->tx->banner[3]);
	map->img->banner[4] = mlx_texture_to_image(map->mlx, map->tx->banner[4]);
	map->img->banner[5] = mlx_texture_to_image(map->mlx, map->tx->banner[5]);
	if (!map->img->player[0] || !map->img->player[1] || !map->img->collec[0]
		|| !map->img->collec[1] || !map->img->exit[0] || !map->img->exit[1]
		|| !map->img->enemy[0] || !map->img->enemy[1] || !map->img->banner[0]
		|| !map->img->banner[1] || !map->img->banner[2] || !map->img->banner[3]
		|| !map->img->banner[4] || !map->img->banner[5])
		free_malloc_error(map);
}

void	init_png(t_map *map)
{
	png_to_texture(map);
	texture_to_image(map);
}
