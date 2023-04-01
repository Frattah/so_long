/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:01:24 by frmonfre          #+#    #+#             */
/*   Updated: 2023/03/30 12:43:25 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->rig)
	{
		j = -1;
		while (++j < map->col)
		{
			if ((i == 0 || j == map->col - 1) && map->map[i][j] != '1')
				return (0);
			else if ((i == map->rig - 1 || j == 0) && map->map[i][j] != '1')
				return (0);
			else if (map->map[i][j] == 'E')
				map->exit = 1;
			else if (map->map[i][j] == 'P')
				map->start = 1;
			else if (map->map[i][j] == 'C')
				map->collect++;
			else if (map->map[i][j] == '1' && map->map[i][j] == '0' &&
					map->map[i][j] == 'O')
				return (0);
		}
	}
	return (map->exit && map->collect && map->start);
}

void	free_map(t_map *map, int tmp)
{
	int	i;

	i = -1;
	if (tmp)
		while (++i < map->rig)
			free(map->map[i]);
	free(map->map);
}

void	get_col(t_map *map, char *line, int fd)
{
	int	i;
	int	j;

	i = -1;
	while (line != NULL)
	{
		j = -1;
		map->map[++i] = (char *) malloc(sizeof(char) * map->col);
		while (line[++j])
			map->map[i][j] = line[j];
		free(line);
		line = get_next_line(fd);
	}
}

int	get_map(t_map *map, char *str)
{
	char	*line;
	int		fd;

	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	map->col = ft_strlen(line) - 1;
	while (line != NULL)
	{
		map->rig++;
		if (ft_strlen(line) - 1 != map->col && ft_strlen(line) != map->col)
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	map->map = (char **) malloc(sizeof(char *) * map->rig);
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	get_col(map, line, fd);
	return (1);
}

void	render_map(t_vrs *vrs)
{
	int			j;
	int			i;
	static int	k;

	i = -1;
	while (++i < vrs->map.rig)
	{
		j = -1;
		while (++j < vrs->map.col)
			put(vrs, i, j, k);
	}
	k++;
	if (k > 5)
		k = 0;
	put_stats(vrs);
	put_coins(vrs);
}
