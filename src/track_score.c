/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_score.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:39:15 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/18 23:39:27 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	display_score_numbers(t_map *map, int x)
{
	int	y;

	y = ((map->height - 1) * SPRITE_PIXEL) + (SPRITE_PIXEL / 16);
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
	mlx_image_to_window(map->mlx, map->img->number[10], x, y);
}

/*
** Display the right numbers at the start of the game
*/
void	display_numbers_coll(t_map *map)
{
	int	i;

	i = 3;
	while (i < 10)
	{
		display_score_numbers(map, (i - 3) * SPRITE_PIXEL);
		map->img->number[0]->instances[i].enabled = 0;
		map->img->number[1]->instances[i].enabled = 0;
		map->img->number[2]->instances[i].enabled = 0;
		map->img->number[3]->instances[i].enabled = 0;
		map->img->number[4]->instances[i].enabled = 0;
		map->img->number[5]->instances[i].enabled = 0;
		map->img->number[6]->instances[i].enabled = 0;
		map->img->number[7]->instances[i].enabled = 0;
		map->img->number[8]->instances[i].enabled = 0;
		map->img->number[9]->instances[i].enabled = 0;
		map->img->number[10]->instances[i - 3].enabled = 0;
		i++;
	}
}

/*
** Hide all the numbers
*/
static void	hide_all_score(t_map *map)
{
	int	i;

	i = 3;
	while (i < 10)
	{
		hide_all_number(map, i);
		map->img->number[10]->instances[i - 3].enabled = 0;
		i++;
	}
}

void	display_score_collectible(t_map *map)
{
	int	i;
	int	coll_total;
	int	coll_grab;

	i = 3;
	coll_total = map->tot_coll;
	coll_grab = map->player->coll;
	hide_all_score(map);
	i = track_coll_base(map, i, coll_grab);
	reveal_number(map, i - 3, 10);
	i++;
	if (i >= 6)
		map->img->banner[5]->instances[i - 6].enabled = 1;
	i = track_coll_base(map, i, coll_total);
}
