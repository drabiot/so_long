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
#include "../include/libft.h"

static void	copy_base_struct(t_map **map, t_map *copy)
{
	copy->height = (*map)->height;
	copy->width = (*map)->width;
	copy->display_map = malloc(sizeof(char *) * copy->height);
	if (!copy->display_map)
	{
		free(copy);
		exit(1);
	}
}

static t_map	*copy_struct(t_map **map)
{
	t_map	*copy;
	int		i;

	copy = malloc(sizeof(t_map));
	if (!copy)
		exit (1);
	copy_base_struct(map, copy);
	i = 0;
	while (i < copy->height)
	{
		copy->display_map[i] = ft_strdup((*map)->display_map[i]);
		if (!copy->display_map[i])
		{
			free(copy->display_map);
			free(copy);
			exit(1);
		}
		i++;
	}
	copy->display_map[copy->height] = NULL;
	return (copy);
}

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
	t_map	*copy;
	int		i;
	int		j;

	if (!map || !*map)
		return ;
	copy = copy_struct(map);
	ft_flood_fill(&copy, (*player)->pos_x, (*player)->pos_y);
	i = 0;
	while (copy->display_map[i])
	{
		j = 0;
		while (copy->display_map[i][j])
		{
			if (copy->display_map[i][j] == 'E')
				error_check(PATH_EXIT_ERROR);
			else if (copy->display_map[i][j] == 'C')
				error_check(PATH_COLLECTIBLE_ERROR);
			j++;
		}
		i++;
	}
}
