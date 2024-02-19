/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:15:43 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/14 16:15:58 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
** Move the enemies to the correct positions
*/
static void	execute_movement(t_map *map, char **cpy_map, int i)
{
	int	enemy_x;
	int	enemy_y;

	enemy_x = map->img->enemy[0]->instances[i].x / SPRITE_PIXEL;
	enemy_y = map->img->enemy[0]->instances[i].y / SPRITE_PIXEL;
	if (cost_move_enemy_x(cpy_map, enemy_x, enemy_y)
		<= cost_move_enemy_y(cpy_map, enemy_x, enemy_y))
	{
		enemy_x += move_enemy_x(cpy_map, enemy_x, enemy_y);
		map->img->enemy[0]->instances[i].x = enemy_x * SPRITE_PIXEL;
		map->img->enemy[1]->instances[i].x = enemy_x * SPRITE_PIXEL;
	}
	else
	{
		enemy_y += move_enemy_y(cpy_map, enemy_x, enemy_y);
		map->img->enemy[0]->instances[i].y = enemy_y * SPRITE_PIXEL;
		map->img->enemy[1]->instances[i].y = enemy_y * SPRITE_PIXEL;
	}
	cpy_map[enemy_y][enemy_x] = 'D';
	if (map->display_map[enemy_y][enemy_x] == '0')
		map->display_map[enemy_y][enemy_x] = 'D';
}

/*
** Check if the enemies are within a distance of 7 tiles from the player
*/
static int	range_enemy(t_map *map, int i)
{
	int	player_x;
	int	player_y;
	int	enemy_x;
	int	enemy_y;

	player_x = map->player->pos_x;
	player_y = map->player->pos_y;
	enemy_x = map->img->enemy[0]->instances[i].x / SPRITE_PIXEL;
	enemy_y = map->img->enemy[0]->instances[i].y / SPRITE_PIXEL;
	if ((player_x + 7 >= enemy_x && player_x - 7 <= enemy_x)
		&& (player_y + 7 >= enemy_y && player_y - 7 <= enemy_y))
		return (1);
	else
		return (0);
}

/*
** Move the enemies
*/
void	move_enemy(t_map *map, char **cpy_map)
{
	int	i;
	int	enemy_x;
	int	enemy_y;

	i = map->img->enemy[0]->count - 1;
	while (i >= 0)
	{
		enemy_x = map->img->enemy[0]->instances[i].x / SPRITE_PIXEL;
		enemy_y = map->img->enemy[0]->instances[i].y / SPRITE_PIXEL;
		if (map->display_map[enemy_y][enemy_x] != 'C'
			&& map->display_map[enemy_y][enemy_x] != 'E')
			map->display_map[enemy_y][enemy_x] = '0';
		if (range_enemy(map, i))
			execute_movement(map, cpy_map, i);
		i--;
	}
}
