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

/*
** Fill the values of one list into another
*/
static void	copy_base_struct(t_map **map, t_map *copy)
{
	copy->height = (*map)->height;
	copy->width = (*map)->width;
	copy->display_map = NULL;
	copy->player = NULL;
	copy->display_map = malloc(sizeof(char *) * (copy->height + 1));
	if (!copy->display_map)
	{
		free(copy);
		exit(1);
	}
}

/*
** Duplicate the list passed as a parameter
*/
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

/*
** Flood fill the map starting from the given coordinate of the player
*/
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

/*
** Check the flood fill to verify if the map is correct
** & everything is accessible
*/
static int	check_flood_fill(t_map *copy)
{
	int	i;
	int	j;

	i = 0;
	if (!copy)
		return (0);
	while (i < copy->height)
	{
		j = 0;
		while (j < copy->width)
		{
			if (copy->display_map[i][j] == 'E')
				return (1);
			else if (copy->display_map[i][j] == 'C')
				return (2);
			j++;
		}
		i++;
	}
	free_struct_map(copy);
	return (0);
}

/*
** Check the validity of the map and ensure that the exit
** & all the collectibles are accessible
*/
void	check_path(t_map **map, t_player **player, char *arg)
{
	t_map	*copy;
	int		check;

	if (!map || !*map || !player || !*player)
		return ;
	copy = copy_struct(map);
	if (!copy || !copy->display_map)
		return ;
	ft_flood_fill(&copy, (*player)->pos_x, (*player)->pos_y);
	check = check_flood_fill(copy);
	if (check != 0)
	{
		free_struct_map(copy);
		free_struct_map(*map);
		if (check == 1)
			error_check(PATH_EXIT_ERROR, arg);
		else if (check == 2)
			error_check(PATH_COLLECTIBLE_ERROR, arg);
	}
}
