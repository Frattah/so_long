/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:49:22 by frmonfre          #+#    #+#             */
/*   Updated: 2023/03/30 11:53:23 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vrs *vrs)
{
	int	tmp;

	tmp = (vrs->ply.collect == vrs->map.collect);
	if (vrs->map.map[vrs->ply.x - 1][vrs->ply.y] == '1')
		return ;
	if (vrs->map.map[vrs->ply.x - 1][vrs->ply.y] == 'C')
		vrs->ply.collect++;
	if (vrs->map.map[vrs->ply.x - 1][vrs->ply.y] == 'E' && tmp)
		close_program(vrs);
	if (vrs->map.map[vrs->ply.x - 1][vrs->ply.y] == 'O')
		close_program(vrs);
	if (vrs->map.map[vrs->ply.x - 1][vrs->ply.y] == 'E')
		return ;
	vrs->map.map[vrs->ply.x - 1][vrs->ply.y] = 'P';
	vrs->map.map[vrs->ply.x][vrs->ply.y] = '0';
	vrs->ply.steps++;
	render_map(vrs);
}

void	move_down(t_vrs *vrs)
{
	int	tmp;

	tmp = (vrs->ply.collect == vrs->map.collect);
	if (vrs->map.map[vrs->ply.x + 1][vrs->ply.y] == '1')
		return ;
	if (vrs->map.map[vrs->ply.x + 1][vrs->ply.y] == 'C')
		vrs->ply.collect++;
	if (vrs->map.map[vrs->ply.x + 1][vrs->ply.y] == 'E' && tmp)
		close_program(vrs);
	if (vrs->map.map[vrs->ply.x + 1][vrs->ply.y] == 'O')
		close_program(vrs);
	if (vrs->map.map[vrs->ply.x + 1][vrs->ply.y] == 'E')
		return ;
	vrs->map.map[vrs->ply.x + 1][vrs->ply.y] = 'P';
	vrs->map.map[vrs->ply.x][vrs->ply.y] = '0';
	vrs->ply.steps++;
	render_map(vrs);
}

void	move_right(t_vrs *vrs)
{
	int	tmp;

	tmp = (vrs->ply.collect == vrs->map.collect);
	if (vrs->map.map[vrs->ply.x][vrs->ply.y + 1] == '1')
		return ;
	if (vrs->map.map[vrs->ply.x][vrs->ply.y + 1] == 'C')
		vrs->ply.collect++;
	if (vrs->map.map[vrs->ply.x][vrs->ply.y + 1] == 'E' && tmp)
		close_program(vrs);
	if (vrs->map.map[vrs->ply.x][vrs->ply.y + 1] == 'O')
		close_program(vrs);
	if (vrs->map.map[vrs->ply.x][vrs->ply.y + 1] == 'E')
		return ;
	vrs->map.map[vrs->ply.x][vrs->ply.y + 1] = 'P';
	vrs->map.map[vrs->ply.x][vrs->ply.y] = '0';
	if (!ft_strncmp(vrs->ply.xpm, "xpm/player_lft.xpm", 19))
		ft_strlcpy(vrs->ply.xpm, "xpm/player_rgt.xpm", 20);
	vrs->ply.steps++;
	render_map(vrs);
}

void	move_left(t_vrs *vrs)
{
	int	tmp;

	tmp = (vrs->ply.collect == vrs->map.collect);
	if (vrs->map.map[vrs->ply.x][vrs->ply.y - 1] == '1')
		return ;
	if (vrs->map.map[vrs->ply.x][vrs->ply.y - 1] == 'E' && tmp)
		close_program(vrs);
	if (vrs->map.map[vrs->ply.x][vrs->ply.y - 1] == 'C')
		vrs->ply.collect++;
	if (vrs->map.map[vrs->ply.x][vrs->ply.y - 1] == 'O')
		close_program(vrs);
	if (vrs->map.map[vrs->ply.x][vrs->ply.y - 1] == 'E')
		return ;
	vrs->map.map[vrs->ply.x][vrs->ply.y - 1] = 'P';
	vrs->map.map[vrs->ply.x][vrs->ply.y] = '0';
	if (!ft_strncmp(vrs->ply.xpm, "xpm/player_rgt.xpm", 19))
		ft_strlcpy(vrs->ply.xpm, "xpm/player_lft.xpm", 20);
	vrs->ply.steps++;
	render_map(vrs);
}

int	command(int keycode, t_vrs *vrs)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vrs->mlx, vrs->win);
		free(vrs->ply.xpm);
		free_map(&vrs->map, 1);
		exit(0);
	}
	else if (keycode == UP)
		move_up(vrs);
	else if (keycode == DOWN)
		move_down(vrs);
	else if (keycode == RIGHT)
		move_right(vrs);
	else if (keycode == LEFT)
		move_left(vrs);
	return (0);
}
