/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:26:13 by frmonfre          #+#    #+#             */
/*   Updated: 2023/03/30 10:49:07 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vrs_init(t_vrs *vrs)
{
	vrs->ply.collect = 0;
	vrs->ply.steps = 0;
	vrs->ply.xpm = ft_strdup("xpm/player_rgt.xpm");
	vrs->map.start = 0;
	vrs->map.exit = 0;
	vrs->map.collect = 0;
	vrs->map.rig = 0;
	ft_strlcpy(vrs->anim[0], "xpm/collectible1.xpm", 22);
	ft_strlcpy(vrs->anim[1], "xpm/collectible2.xpm", 22);
	ft_strlcpy(vrs->anim[2], "xpm/collectible3.xpm", 22);
	ft_strlcpy(vrs->anim[3], "xpm/collectible4.xpm", 22);
	ft_strlcpy(vrs->anim[4], "xpm/collectible5.xpm", 22);
	ft_strlcpy(vrs->anim[5], "xpm/collectible0.xpm", 22);
}

int	main(int argc, char **str)
{
	t_vrs	vrs;
	int		tmp;

	if (argc != 2)
	{
		write(1, "Invalid Number of parameters\n", 29);
		exit(1);
	}
	vrs_init(&vrs);
	tmp = get_map(&vrs.map, str[1]);
	if (!tmp || !is_valid(&vrs.map))
	{
		free(vrs.ply.xpm);
		free_map(&vrs.map, tmp);
		write(1, "Error\n", 6);
		exit(0);
	}
	vrs.mlx = mlx_init();
	vrs.win = mlx_new_window(vrs.mlx, vrs.map.col * 64,
			(vrs.map.rig + 2) * 64, "Game");
	render_map(&vrs);
	mlx_hook(vrs.win, 2, 1L << 0, command, &vrs);
	mlx_loop(vrs.mlx);
}
