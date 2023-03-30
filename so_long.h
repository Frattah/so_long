/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:30:18 by frmonfre          #+#    #+#             */
/*   Updated: 2023/03/30 10:40:48 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/wait.h>
# define ESC 53
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		wdt;
	int		hgt;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	char	**map;
	int		rig;
	int		col;
	int		collect;
	int		start;
	int		exit;
}	t_map;

typedef struct s_ply
{
	int		collect;
	char	*xpm;
	int		steps;
	int		x;
	int		y;
}	t_ply;

typedef struct s_vrs
{
	int		x;
	int		y;
	void	*mlx;
	t_data	img;
	void	*win;
	t_map	map;
	t_ply	ply;
	char	anim[10][22];
}	t_vrs;

void	window(char *str);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	square(t_data *img);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strdup(const char *s1);

void	choise_number(char *num, int n);

void	put_player(t_vrs *vrs, int x, int y);

void	put_staff(t_vrs *vrs, int x, int y, char *staff);

void	put_coins(t_vrs *vrs);

void	put_stats(t_vrs *vrs);

int		is_valid(t_map *map);

void	free_map(t_map *map, int tmp);

int		get_map(t_map *map, char *str);

void	render_map(t_vrs *vrs);

void	move_down(t_vrs *vrs);

void	move_right(t_vrs *vrs);

void	move_left(t_vrs *vrs);

int		command(int keycode, t_vrs *vrs);

void	put(t_vrs *vrs, int i, int j, int k);

void	close_program(t_vrs *vrs);

#endif
