/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:21:34 by tchartie          #+#    #+#             */
/*   Updated: 2024/01/11 16:21:51 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	add_pos_player(t_map **map, t_player **player)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*map)->height)
	{
		j = 0;
		while (j < (*map)->width)
		{
			if ((*map)->display_map[i][j] == 'P')
			{
				(*player)->pos_x = j;
				(*player)->pos_y = i;
			}
			j++;
		}
		i++;
	}
}

void	display_player(t_map *map, t_player *player)
{
	int	x;
	int	y;

	x = player->pos_x * SPRITE_PIXEL;
	y = player->pos_y * SPRITE_PIXEL;
	mlx_image_to_window(map->mlx, map->img->player[0], x, y);
	mlx_image_to_window(map->mlx, map->img->player[1], x, y);
	map->img->player[1]->instances[0].enabled = 0;
}

void	player_init(t_map **map, t_player **player)
{
	*player = malloc(sizeof(t_player));
	if (!*player)
		exit(1);
	(*player)->pos_x = -1;
	(*player)->pos_y = -1;
	(*player)->coll = 0;
	add_pos_player(map, player);
	(*map)->player = *player;
}
