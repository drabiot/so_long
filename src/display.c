/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:28:14 by tchartie          #+#    #+#             */
/*   Updated: 2024/01/18 16:20:10 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	display_floor(t_map *map, int i, int j)
{
	int	rand;
	int	x;
	int	y;
	
	rand = ft_rand(0,2);
	x = j * SPRITE_PIXEL;
	y = i * SPRITE_PIXEL;
	if (rand == 0)
		mlx_image_to_window(map->mlx, map->img->floor[0], x, y);
	else if (rand == 1)
		mlx_image_to_window(map->mlx, map->img->floor[1], x, y);
	else if (rand == 2)
		mlx_image_to_window(map->mlx, map->img->floor[2], x, y);
}

static void	display_wall(t_map *map, int i, int j)
{
	int	x;
	int	y;
	
	x = j * SPRITE_PIXEL;
	y = i * SPRITE_PIXEL;
	if (i == 0 && j == 0)
		mlx_image_to_window(map->mlx, map->img->corner[0], x, y);
	else if (i == 0 && j == (map->width - 1))
		mlx_image_to_window(map->mlx, map->img->corner[1], x, y);
	else if (i == (map->height - 1) && j == (map->width - 1))
		mlx_image_to_window(map->mlx, map->img->corner[2], x, y);
	else if (i == (map->height - 1) && j == 0)
		mlx_image_to_window(map->mlx, map->img->corner[3], x, y);
	else if (i == 0)
		mlx_image_to_window(map->mlx, map->img->wall[0], x, y);
	else if (i == (map->height - 1))
		mlx_image_to_window(map->mlx, map->img->wall[2], x, y);
	else if (j == (map->width - 1))
		mlx_image_to_window(map->mlx, map->img->wall[1], x, y);
	else if (j == 0)
		mlx_image_to_window(map->mlx, map->img->wall[3], x, y);
	else
		mlx_image_to_window(map->mlx, map->img->obstacle[0], x, y);
}

static void	display_exit(t_map *map, int i, int j)
{
	int	x;
	int	y;
	
	x = j * SPRITE_PIXEL;
	y = i * SPRITE_PIXEL;
	mlx_image_to_window(map->mlx, map->img->exit[0], x, y);
}

static void	display_people(t_map *map, int i, int j)
{
	int	x;
	int	y;
	
	x = j * SPRITE_PIXEL;
	y = i * SPRITE_PIXEL;
	if (map->display_map[i][j] == 'P')
		mlx_image_to_window(map->mlx, map->img->player, x, y);
	else if (map->display_map[i][j] == 'C')
	{
		mlx_image_to_window(map->mlx, map->img->collectible[0], x, y);
		mlx_image_to_window(map->mlx, map->img->collectible[1], x, y);
		map->img->collectible[1]->instances[map->img->collectible[1]->count].enabled = 0;
	}
}

void	display_map(t_map *map)
{
	int	i;
	int	j;

	if (!map)
		return ;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			display_floor(map, i, j);
			if (map->display_map[i][j] == '1')
				display_wall(map, i, j);
			else if (map->display_map[i][j] == 'E')
				display_exit(map, i, j);
			else
				display_people(map, i, j);
			j++;
		}
		i++;
	}
}
