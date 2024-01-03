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

t_map	*map_node_init(t_map **map, char *full_map, int height, int width)
{
	t_map	*current;
	char	**split_map;
	int		i;

	i = 0;
	split_map = ft_split(full_map, '\n');
	while (split_map[i])
	{
		if ((int)ft_strlen(split_map[i]) + 1 != width)
			error_check(SIZE_ERROR);
		i++;
	}
	current = *map;
	current = malloc(sizeof(t_map));
	if (!current)
		return (NULL);
	current->width = width - 1;
	current->height = height;
	current->display_map = split_map;
	return (current);
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
		error_check(NO_MAP_ERROR);
	line = get_next_line(fd);
	height = 0;
	full_map = NULL;
	while (line)
	{
		width = 0;
		while (line[width])
			width++;
		full_map = ft_strjoin(full_map, line);
		if (line)
			free(line);
		line = get_next_line(fd);
		height++;
	}
	*map = map_node_init(map, full_map, height, width);
}
