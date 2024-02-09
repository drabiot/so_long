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
	static int	ticks = 0;
	static int	frame = 1;
	size_t		i;

	ticks++;
	if (ticks % 20 == 0)
	{
		i = 0;
		if (frame > 1)
			frame = 0;
		while (i < map->img->collectible[0]->count)
		{
			if (!(map->img->collectible[0]->instances[i].enabled == 0
					&& map->img->collectible[1]->instances[i].enabled == 0))
			{
				map->img->collectible[frame]->instances[i].enabled = 0;
				map->img->collectible[(frame + 1) % 2]->instances[i].enabled = 1;
			}
			i++;
		}
		map->img->player[frame]->instances[0].enabled = 0;
		map->img->player[(frame + 1) % 2]->instances[0].enabled = 1;
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
	display_map(map, player);
	mlx_loop_hook(map->mlx, (t_loop_hook_f)hook, (void *)map);
	mlx_key_hook(map->mlx, (void *)key_press, map);
	mlx_loop(map->mlx);
}
