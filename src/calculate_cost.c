/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 03:31:51 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/13 03:32:09 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
** Look for the smallest value around the given coordinates
** on the horizontal axis
*/
int	cost_move_enemy_x(char **map, int x, int y)
{
	int	min;

	min = 2147483647;
	if (map[y][x + 1] < min)
		min = map[y][x + 1];
	if (map[y][x - 1] < min)
		min = map[y][x - 1];
	return (min);
}

/*
** Look for the smallest value around the given coordinates
** on the vertical axis
*/
int	cost_move_enemy_y(char **map, int x, int y)
{
	int	min;

	min = 2147483647;
	if (map[y + 1][x] < min)
		min = map[y + 1][x];
	if (map[y - 1][x] < min)
		min = map[y - 1][x];
	return (min);
}

/*
** Check if the enemy should move up or down based
** on the given coordinates
*/
int	move_enemy_x(char **map, int x, int y)
{
	int	min;

	min = 2147483647;
	if (map[y][x + 1] < min)
		min = map[y][x + 1];
	if (map[y][x - 1] < min)
	{
		min = map[y][x - 1];
		return (-1);
	}
	return (1);
}

/*
** Check if the enemy should move right or left based
** on the given coordinates
*/
int	move_enemy_y(char **map, int x, int y)
{
	int	min;

	min = 2147483647;
	if (map[y + 1][x] < min)
		min = map[y + 1][x];
	if (map[y - 1][x] < min)
	{
		min = map[y - 1][x];
		return (-1);
	}
	return (1);
}
