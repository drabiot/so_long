/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:12:10 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/12 17:12:31 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
** Take coordinates x and y and look for the smallest value around them
*/
static int	check_min(char **map, int x, int y)
{
	int	min;

	min = 2147483647;
	if (map[y + 1][x] < min)
		min = map[y + 1][x];
	if (map[y - 1][x] < min)
		min = map[y - 1][x];
	if (map[y][x + 1] < min)
		min = map[y][x + 1];
	if (map[y][x - 1] < min)
		min = map[y][x - 1];
	return (min);
}

void	check_flood_enemy(char **map, char **travel_map, int x, int y)
{
	if (travel_map[y][x] == 'O' || travel_map[y][x] == 'W'
		|| map[y][x] == 'D' || map[y][x] == 'C' || map[y][x] == 'E')
		return ;
	travel_map[y][x] = 'O';
	if (map[y][x] != 'O' && check_min(map, x, y) < map[y][x])
		map[y][x] = check_min(map, x, y) + 1;
	check_flood_enemy(map, travel_map, x, y + 1);
	check_flood_enemy(map, travel_map, x, y - 1);
	check_flood_enemy(map, travel_map, x + 1, y);
	check_flood_enemy(map, travel_map, x - 1, y);
}

/*
** Flood fill the map and assign a value to each of the
** cells based on the given starting position
*/
void	ai_enemy(char **map, char **travel_map, int x, int y)
{
	if (travel_map[y][x] == '1' || travel_map[y][x] == 'W'
		|| map[y][x] == 'D' || map[y][x] == 'C' || map[y][x] == 'E')
		return ;
	travel_map[y][x] = '1';
	if (map[y + 1][x] == 'O')
		map[y + 1][x] = check_min(map, x, y + 1) + 1;
	if (map[y - 1][x] == 'O')
		map[y - 1][x] = check_min(map, x, y - 1) + 1;
	if (map[y][x + 1] == 'O')
		map[y][x + 1] = check_min(map, x + 1, y) + 1;
	if (map[y][x - 1] == 'O')
		map[y][x - 1] = check_min(map, x - 1, y) + 1;
	ai_enemy(map, travel_map, x, y + 1);
	ai_enemy(map, travel_map, x, y - 1);
	ai_enemy(map, travel_map, x + 1, y);
	ai_enemy(map, travel_map, x - 1, y);
}
