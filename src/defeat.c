/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defeat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:48:05 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/15 18:48:19 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/ft_printf.h"

/*
** Close the window after a certain time following the player's death
*/
static void	death_screen(t_map *map)
{
	static int	ticks = 0;

	ticks++;
	if (ticks % 120 == 0)
	{
		kill_sounds();
		mlx_close_window(map->mlx);
	}
}

/*
** Display the death banner after the player's death with the given coordinate
*/
static void	show_banner(t_map *map, int len, int middle)
{
	int	top;
	int	bottom;

	top = middle - SPRITE_PIXEL;
	bottom = middle + SPRITE_PIXEL;
	mlx_image_to_window(map->mlx, map->img->banner[1], len, top);
	mlx_image_to_window(map->mlx, map->img->banner[0], len, middle);
	mlx_image_to_window(map->mlx, map->img->banner[2], len, bottom);
}

/*
** Display the full death banner after the player's death
*/
static void	title_screen(t_map *map)
{
	static int	ticks = 0;
	int			title_pos;
	int			middle;
	int			i;
	int			len;

	i = 0;
	title_pos = ((map->width / 2) - 1) * SPRITE_PIXEL;
	ticks++;
	if (map->height % 2 != 0)
		middle = ((map->height / 2) + 1) * SPRITE_PIXEL;
	else
		middle = (map->height / 2) * SPRITE_PIXEL - (SPRITE_PIXEL / 2);
	if (ticks % 50 == 0)
	{
		while (i < map->width)
		{
			len = i * SPRITE_PIXEL;
			show_banner(map, len, middle);
			i++;
		}
		mlx_image_to_window(map->mlx, map->img->banner[3], title_pos, middle);
	}
}

/*
** Add an appearing effect to the banner
*/
static void	add_banner(t_map *map, int middle)
{
	int	frame;

	frame = 0;
	middle *= SPRITE_PIXEL;
	while (frame < 8)
	{
		mlx_loop_hook(map->mlx, (void *)title_screen, (void *)map);
		frame++;
	}
}

void	defeat(t_map *map)
{
	int	middle;

	map->dead = 1;
	play_sound("sounds/death.wav &");
	if (map->height % 2 != 0)
		middle = (map->height / 2) + 1;
	else
		middle = (map->height / 2) * SPRITE_PIXEL - (SPRITE_PIXEL / 2);
	map->img->player[0]->instances[0].enabled = 0;
	map->img->player[1]->instances[0].enabled = 0;
	add_banner(map, middle);
	ft_printf("You lost...");
	mlx_loop_hook(map->mlx, (void *)death_screen, (void *)map);
}
