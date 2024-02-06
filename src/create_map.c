/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:58:17 by tchartie          #+#    #+#             */
/*   Updated: 2024/01/03 21:21:59 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/libft.h"
#include <fcntl.h>

static void	add_exit_pos(t_map **map)
{
	t_map	*current;
	int		i;
	int		j;

	current = *map;
	i = 0;
	while (i < current->height)
	{
		j = 0;
		while (j < current->width)
		{
			if (current->display_map[i][j] == 'E')
			{
				current->pos_x_exit = j;
				current->pos_y_exit = i;
			}
			j++;
		}
		i++;
	}
}

static void	check_null_line(char *full_map, char *arg)
{
	char	*check;
	size_t	len;

	if (!full_map)
		error_check(NO_MAP_ERROR, arg);
	len = ft_strlen(full_map);
	check = ft_strnstr(full_map, "\n\n", len);
	if (check)
	{
		free(full_map);
		error_check(MAP_ERROR, arg);
	}
}

static void	init_value(t_map *map, int height, int width, char **split_map)
{
	map->width = width;
	map->height = height;
	map->display_map = split_map;
	map->pos_x_exit = 0;
	map->pos_y_exit = 0;
	map->player = NULL;
	map->mlx = NULL;
	map->tx = NULL;
	map->img = NULL;
}

t_map	*map_node_init(t_map **map, char *full_map, int width, char *arg)
{
	char	**split_map;
	int		i;

	i = 0;
	check_null_line(full_map, arg);
	split_map = ft_split(full_map, '\n');
	free(full_map);
	while (split_map[i])
	{
		if ((int)ft_strlen(split_map[i]) != width)
		{
			free_matrix(split_map);
			error_check(SIZE_ERROR, arg);
		}
		i++;
	}
	*map = malloc(sizeof(t_map));
	if (!*map || !map)
		return (NULL);
	init_value(*map, i, width, split_map);
	add_exit_pos(map);
	return (*map);
}

void	map_init(t_map **map, char *arg)
{
	int		fd;
	char	*line;
	char	*full_map;
	int		height;
	int		width;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		error_check(NO_MAP_ERROR, arg);
	line = get_next_line(fd);
	height = 0;
	full_map = NULL;
	while (line)
	{
		width = 0;
		while (line[width])
			width++;
		full_map = ft_strjoin(full_map, ft_strdup(line));
		if (line)
			free(line);
		line = get_next_line(fd);
		height++;
	}
	*map = map_node_init(map, full_map, width - 1, arg);
	check_map(map, arg);
}
