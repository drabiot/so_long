/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:07:13 by tchartie          #+#    #+#             */
/*   Updated: 2024/01/04 20:45:05 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_init(t_map **map, t_player **player)
{
	int			i;
	int			j;
	t_player	*current;

	current = malloc(sizeof(t_player));
	current = *player;
	i = 0;
	while ((*map)->display_map[i])
	{
		j = 0;
		while ((*map)->display_map[i][j])
		{
			if ((*map)->display_map[i][j] == 'P')
			{
				current->pos_x = j;
				current->pos_y = i;
			}
			j++;
		}
		i++;
	}
}

void	ft_flood_fill(t_map **map, int x, int y)
{
	t_map	*current;

	if (!map || !*map)
		return ;
	current = *map;
	if (current->display_map[y][x] != '1'
		&& current->display_map[y][x] != 'T')
	{
		current->display_map[y][x] = 'T';
		ft_flood_fill(map, x - 1, y);
		ft_flood_fill(map, x + 1, y);
		ft_flood_fill(map, x, y - 1);
		ft_flood_fill(map, x, y + 1);
	}
	else
		return ;
}

void	check_path(t_map **map, t_player **player)
{
	int	i;
	int	j;

	if (!map || !*map)
		return ;
	ft_flood_fill(map, (*player)->pos_x, (*player)->pos_y);
	i = 0;
	while ((*map)->display_map[i])
	{
		j = 0;
		while ((*map)->display_map[i][j])
		{
			if ((*map)->display_map[i][j] == 'E')
				error_check(PATH_EXIT_ERROR);
			else if ((*map)->display_map[i][j] == 'C')
				error_check(PATH_COLLECTIBLE_ERROR);
			j++;
		}
		i++;
	}
}
