/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:08:29 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/20 15:59:54 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/libft.h"

/*
** See if there a newline in the string
*/
int	new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

/*
** Join two string
*/
char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ar;

	if (!s1)
		ar = (char *)malloc(sizeof(char) * (ft_strlen(s2) + 1));
	else
		ar = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ar)
		return (NULL);
	ar = ft_strcat((const char *)s1, (const char *)s2, ar);
	free(s1);
	return (ar);
}

/*
** If check_nl == 0 : Copy the source until he see a newline to destination
** If check_nl != 0 : Copy the source to destination
*/
char	*ft_strccpy(char *dst, const char *src, int check_nl)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (check_nl == 0)
	{
		while (src[i] != '\n' && src[i])
			dst[j++] = src[i++];
		if (src[i] == '\n')
			dst[j++] = src[i++];
	}
	else if (check_nl != 0)
	{
		while (src[i])
			dst[j++] = src[i++];
	}
	dst[i] = '\0';
	return (dst);
}
