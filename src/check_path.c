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
	copy->display_map = NULL;
	copy->display_map = malloc(sizeof(char *) * (copy->height + 1));
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
	return (copy);
}

void	player_init(t_map **map, t_player **player)
{
	int	i;
	int	j;

	*player = malloc(sizeof(t_player));
	if (!*player)
		exit(1);
	i = 0;
	(*player)->pos_x = -1;
	(*player)->pos_y = -1;
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

void	check_path(t_map **map, t_player **player, char *arg)
{
	t_map	*copy;
	int		i;
	int		j;

	if (!map || !*map || !player || !*player)
		return ;
	copy = copy_struct(map);
	i = 0;
	if (!copy || !copy->display_map[i])
		return ;
	ft_flood_fill(&copy, (*player)->pos_x, (*player)->pos_y);
	while (i < copy->height)
	{
		j = 0;
		while (j < copy->width)
		{
			if (copy->display_map[i][j] == 'E')
				error_check(PATH_EXIT_ERROR, arg);
			else if (copy->display_map[i][j] == 'C')
				error_check(PATH_COLLECTIBLE_ERROR, arg);
			j++;
		}
		i++;
	}
	free_struct_map(copy);
}
