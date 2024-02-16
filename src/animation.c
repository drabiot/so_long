/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:38:10 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/14 17:38:29 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	animation_player(t_map *map, int frame)
{
	if (!(map->img->player[0]->instances[0].enabled == 0
			&& map->img->player[1]->instances[0].enabled == 0))
	{
		map->img->player[frame]->instances[0].enabled = 0;
		map->img->player[(frame + 1) % 2]->instances[0].enabled = 1;
	}
}

static void	animation_collectible(t_map *map, int frame)
{
	int	i;

	i = 0;
	while (i < (int)map->img->collec[0]->count)
	{
		if (!(map->img->collec[0]->instances[i].enabled == 0
				&& map->img->collec[1]->instances[i].enabled == 0))
		{
			map->img->collec[frame]->instances[i].enabled = 0;
			map->img->collec[(frame + 1) % 2]->instances[i].enabled = 1;
		}
		i++;
	}
}

static void	animation_enemy(t_map *map, int frame)
{
	int	i;

	i = 0;
	while (i < (int)map->img->enemy[0]->count)
	{
		map->img->enemy[frame]->instances[i].enabled = 0;
		map->img->enemy[(frame + 1) % 2]->instances[i].enabled = 1;
		i++;
	}
}

void	animation(t_map *map)
{
	static int	ticks = 0;
	static int	frame = 1;

	ticks++;
	if (ticks % 20 == 0)
	{
		if (frame > 1)
			frame = 0;
		animation_collectible(map, frame);
		animation_enemy(map, frame);
		animation_player(map, frame);
		frame++;
	}
}
