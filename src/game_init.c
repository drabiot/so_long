/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:34:11 by tchartie          #+#    #+#             */
/*   Updated: 2024/01/17 18:41:21 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	hook(t_map *map)
{
	static int ticks = 0;
	static int frame = 1;
	static mlx_image_t *r = 0;
	ticks++;
	if (ticks % 20 == 0) {
		if(frame > 1) frame = 0;
		mlx_image_t *tmp = r;
		r = mlx_texture_to_image(map->mlx, map->tx->collectible[frame]);
		if(tmp) mlx_delete_image(map->mlx, tmp);
		mlx_image_to_window(map->mlx, r, 0, 0);
		frame++;
	}
}

void	game_init(t_map *map, t_player *player)
{
	(void)player;
	map->mlx = mlx_init(map->width * SPRITE_PIXEL, map->height * SPRITE_PIXEL,
		"so_long", false);
	init_png(map);
	ft_srand(map->height * map->width);
	display_map(map);
	mlx_loop_hook(map->mlx, (t_loop_hook_f)hook, (void *)map);
	mlx_loop(map->mlx);
	mlx_close_window(map->mlx);
	mlx_terminate(map->mlx);
}