/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:23:42 by frmonfre          #+#    #+#             */
/*   Updated: 2023/03/30 11:55:42 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = -1;
	if (dstsize > 0)
	{
		while (++i < (dstsize - 1) && src[i])
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (ft_strlen((char *) src));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

char	*ft_strdup(const char *s1)
{
	char	*nw;
	size_t	len;

	len = ft_strlen((char *) s1) + 1;
	nw = (char *) malloc(sizeof(char) * len);
	if (nw == NULL)
		return (NULL);
	ft_strlcpy(nw, s1, len);
	return (nw);
}

void	choise_number(char *num, int n)
{
	if (n == 0)
		ft_strlcpy(num, "xpm/0.xpm", 10);
	if (n == 1)
		ft_strlcpy(num, "xpm/1.xpm", 10);
	if (n == 2)
		ft_strlcpy(num, "xpm/2.xpm", 10);
	if (n == 3)
		ft_strlcpy(num, "xpm/3.xpm", 10);
	if (n == 4)
		ft_strlcpy(num, "xpm/4.xpm", 10);
	if (n == 5)
		ft_strlcpy(num, "xpm/5.xpm", 10);
	if (n == 6)
		ft_strlcpy(num, "xpm/6.xpm", 10);
	if (n == 7)
		ft_strlcpy(num, "xpm/7.xpm", 10);
	if (n == 8)
		ft_strlcpy(num, "xpm/8.xpm", 10);
	if (n == 9)
		ft_strlcpy(num, "xpm/8.xpm", 10);
}

void	close_program(t_vrs *vrs)
{
	mlx_destroy_window(vrs->mlx, vrs->win);
	free(vrs->ply.xpm);
	free_map(&vrs->map, 1);
	exit(0);
}
