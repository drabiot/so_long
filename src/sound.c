/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:47:08 by tchartie          #+#    #+#             */
/*   Updated: 2024/02/19 15:47:26 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/libft.h"

/*
** Play the given sound
*/
void	play_sound(char *path)
{
	char	*str;

	str = ft_strjoin(ft_strdup("paplay "), ft_strdup(path));
	if (!str)
		return ;
	system(str);
	free(str);
}

/*
** Kill all the sound
*/
void	kill_sounds(void)
{
	system("pkill paplay &");
}

/*
** Play randomly the sound when player grab a collectible
*/
void	play_collectible(void)
{
	int	random;

	random = ft_rand(0, 1);
	if (random == 0)
		play_sound("sounds/chomp.wav &");
	else
		play_sound("sounds/eating.wav &");
}
