/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:24:37 by tchartie          #+#    #+#             */
/*   Updated: 2024/01/04 18:26:04 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_up(t_map **map, char *arg)
{
	int		i;
	t_map	*current;

	if (!map || !*map)
		return ;
	current = *map;
	i = 0;
	while (current->display_map[0][i])
	{
		if (current->display_map[0][i] != '1')
			error_check(WALLS_ERROR, arg);
		i++;
	}
}

static void	check_down(t_map **map, char *arg)
{
	int		i;
	t_map	*current;

	if (!map || !*map)
		return ;
	current = *map;
	i = 0;
	while (current->display_map[current->height - 1][i])
	{
		if (current->display_map[current->height - 1][i] != '1')
			error_check(WALLS_ERROR, arg);
		i++;
	}
}

static void	check_right(t_map **map, char *arg)
{
	int		i;
	t_map	*current;

	if (!map || !*map)
		return ;
	current = *map;
	i = 0;
	while (i < current->height
		&& current->display_map[i][current->width - 1])
	{
		if (current->display_map[i][current->width - 1] != '1')
			error_check(WALLS_ERROR, arg);
		i++;
	}
}

static void	check_left(t_map **map, char *arg)
{
	int		i;
	t_map	*current;

	if (!map || !*map)
		return ;
	current = *map;
	i = 0;
	while (i < current->height && current->display_map[i][0])
	{
		if (current->display_map[i][0] != '1')
			error_check(WALLS_ERROR, arg);
		i++;
	}
}

void	check_walls(t_map **map, char *arg)
{
	check_up(map, arg);
	check_down(map, arg);
	check_right(map, arg);
	check_left(map, arg);
}
