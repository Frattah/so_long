/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putting_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:23:57 by frmonfre          #+#    #+#             */
/*   Updated: 2023/03/30 10:00:20 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(t_vrs *vrs, int x, int y)
{
	t_data	i;

	i = vrs->img;
	i.img = mlx_xpm_file_to_image(vrs->mlx, vrs->ply.xpm, &i.wdt, &i.hgt);
	mlx_put_image_to_window(vrs->mlx, vrs->win, i.img, y * 64, x * 64);
	vrs->ply.x = x;
	vrs->ply.y = y;
}

void	put_staff(t_vrs *vrs, int x, int y, char *staff)
{
	t_data	i;
	void	*w;

	i = vrs->img;
	w = vrs->win;
	i.img = mlx_xpm_file_to_image(vrs->mlx, staff, &i.wdt, &i.hgt);
	if (!ft_strncmp("xpm/collectible", staff, 15))
		mlx_put_image_to_window(vrs->mlx, w, i.img, y * 64 + 16, x * 64 + 16);
	else
		mlx_put_image_to_window(vrs->mlx, w, i.img, y * 64, x * 64);
}

void	put_coins(t_vrs *vrs)
{
	char	*num;
	int		n;
	int		j;
	t_map	m;

	m = vrs->map;
	num = (char *) malloc(sizeof(char) * 10);
	n = vrs->ply.collect;
	if (n == 0)
		put_staff(vrs, m.rig + 1, m.col - 1, "xpm/0.xpm");
	j = 0;
	while (n > 0)
	{
		j++;
		choise_number(num, n % 10);
		put_staff(vrs, m.rig + 1, m.col - j, "xpm/black.xpm");
		put_staff(vrs, m.rig + 1, m.col - j, num);
		n /= 10;
	}
	if (j == 0)
		j++;
	put_staff(vrs, m.rig + 1, m.col - j - 1, "xpm/collectible3.xpm");
	free(num);
}

void	put_stats(t_vrs *vrs)
{
	char	*num;
	int		n;
	int		j;

	num = (char *) malloc(sizeof(char) * 10);
	n = vrs->ply.steps;
	if (n == 0)
		put_staff(vrs, vrs->map.rig, vrs->map.col - 1, "xpm/0.xpm");
	j = 1;
	while (n > 0)
	{
		choise_number(num, n % 10);
		put_staff(vrs, vrs->map.rig, vrs->map.col - j, "xpm/black.xpm");
		put_staff(vrs, vrs->map.rig, vrs->map.col - j, num);
		n /= 10;
		j++;
	}
	free(num);
}

void	put(t_vrs *vrs, int i, int j, int k)
{
	if (vrs->map.map[i][j] == '1' || vrs->map.map[i][j] == 'E')
		put_staff(vrs, i, j, "xpm/wall.xpm");
	if (vrs->map.map[i][j] == '0' || vrs->map.map[i][j] == 'P'
	|| vrs->map.map[i][j] == 'C' || vrs->map.map[i][j] == 'O')
		put_staff(vrs, i, j, "xpm/floor.xpm");
	if (vrs->map.map[i][j] == 'P')
		put_player(vrs, i, j);
	if (vrs->map.map[i][j] == 'O')
		put_staff(vrs, i, j, "xpm/enemy.xpm");
	if (vrs->map.map[i][j] == 'C')
		put_staff(vrs, i, j, vrs->anim[k]);
	if (vrs->map.map[i][j] == 'E' &&
		vrs->map.collect != vrs->ply.collect)
		put_staff(vrs, i, j, "xpm/wall.xpm");
	if (vrs->map.map[i][j] == 'E' &&
		vrs->map.collect == vrs->ply.collect)
		put_staff(vrs, i, j, "xpm/door.xpm");
}
