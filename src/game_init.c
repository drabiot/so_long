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

void	game_init(t_map *map, t_player *player)
{
	(void)player;
	map->mlx = mlx_init(map->width * SPRITE_PIXEL, map->height * SPRITE_PIXEL,
		"so_long", false);
	init_png(map);
	ft_srand(map->height * map->width);
	display_map(map);
	mlx_loop(map->mlx);
	mlx_close_window(map->mlx);
	mlx_terminate(map->mlx);
}
