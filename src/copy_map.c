/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:36:36 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/12 17:00:08 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/libft.h"

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/*
** Change the characters of the map as follows:
** Replace '1' with 'W'
** Replace '0' and 'P' with 'O'
** Replace 'C' and 'E' with 'F'
*/
static char	**change_charac_map(t_map *real_map, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < real_map->height)
	{
		j = 0;
		while (j < real_map->width)
		{
			if (map[i][j] == '1')
				map[i][j] = 'W';
			else if (map[i][j] == '0' || map[i][j] == 'P')
				map[i][j] = 'O';
			else if (map[i][j] == 'C' || map[i][j] == 'E')
				map[i][j] = 70;
			j++;
		}
		i++;
	}
	return (map);
}

/*
** Duplicate the given map (char **) and return it
*/
char	**copy_map(t_map *map)
{
	int		i;
	char	**copy_map;

	copy_map = malloc(sizeof(char *) * (map->height + 1));
	if (!copy_map)
	{
		free(copy_map);
		exit(1);
	}
	i = 0;
	while (i < map->height)
	{
		copy_map[i] = ft_strdup(map->display_map[i]);
		if (!copy_map[i])
		{
			free_map(copy_map);
			exit(1);
		}
		i++;
	}
	copy_map[i] = NULL;
	copy_map = change_charac_map(map, copy_map);
	return (copy_map);
}
