/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:18:01 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/12 15:22:31 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
** Search for where the enemy should move on the map
*/
void	pathfinding_enemy(t_map *map)
{
	char	**cpy_map;
	char	**travel_map;
	int		x;
	int		y;

	cpy_map = copy_map(map);
	travel_map = copy_map(map);
	x = map->player->pos_x;
	y = map->player->pos_y;
	cpy_map[y][x] = 1;
	ai_enemy(cpy_map, travel_map, x, y);
	check_flood_enemy(cpy_map, travel_map, x, y);
	move_enemy(map, cpy_map);
	free_matrix(cpy_map);
	free_matrix(travel_map);
}

static void	display_enemy(t_map *map, int x, int y)
{
	int	nb_enemy;

	map->display_map[y][x] = 'D';
	x *= SPRITE_PIXEL;
	y *= SPRITE_PIXEL;
	nb_enemy = map->img->enemy[0]->count;
	mlx_image_to_window(map->mlx, map->img->enemy[0], x, y);
	mlx_image_to_window(map->mlx, map->img->enemy[1], x, y);
	map->img->enemy[1]->instances[nb_enemy].enabled = 0;
}

/*
** Check the positions of the enemies to ensure they are
** in the correct locations
*/
static void	check_pos_enemy(t_map *map)
{
	int	x;
	int	y;

	x = ft_rand(1, map->width - 2);
	y = ft_rand(1, map->height - 1);
	while (map->display_map[y][x] != '0')
	{
		if (x >= map->width - 2)
			x -= 1;
		else if (y >= map->height - 1)
			y -= 1;
		else if (x <= 1)
			x += 1;
		else if (y <= 1)
			y += 1;
		else
		{
			x += ft_rand(-1, 1);
			y += ft_rand(-1, 1);
		}
	}
	display_enemy(map, x, y);
}

/*
** Initialize the number of enemies based on the given map
*/
void	enemy_init(t_map *map)
{
	int	nb_enemy;

	nb_enemy = (5 * (check_nb(map, '0') + check_nb(map, 'C'))) / 300;
	while (nb_enemy)
	{
		check_pos_enemy(map);
		nb_enemy--;
	}
}
