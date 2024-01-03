/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:28:14 by tchartie          #+#    #+#             */
/*   Updated: 2024/01/03 19:34:57 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

void	display(t_map **map)
{
	int	j;

	printf("Height : %d\n", (*map)->height);
	printf("Width : %d\n", (*map)->width);
	printf("Map :\n");
	j = 0;
	while ((*map)->display_map[j])
	{
		printf("%s\n", (*map)->display_map[j]);
		j++;
	}
}
