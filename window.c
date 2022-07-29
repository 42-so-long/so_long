#include "so_long.h"
#include <stdio.h>

void	*hk_realloc(void *buf, int before_size, int after_size)
{
	char	**src;
	char	**dst;
	int		idx;
	src = (char **)buf;
	dst = (char**)malloc(sizeof(char *) * after_size);

	idx = 0;
	while (idx < before_size)
	{
		dst[idx] = src[idx];
		idx++;
	}
	free(buf);
	return ((void *)dst);
}

char	*get_line(int fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	if (!line)
		return (0);
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = 0;	
	return (line);
}

void	check_rec(t_game *game)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = ft_strlen(game->map.total_map[i]);
	while (i < game->map.col)
	{
		if (tmp != ft_strlen(game->map.total_map[i]))
			hk_error("Is not rec", game);
		i++;
	}
}


void	check_wall(t_game *game)
{
	int	col;
	int	row;

	col = 0;
	while (col < game->map.col)
	{
		row = 0;
		if (col == 0 || col == game->map.col - 1)
		{
			while (row < game->map.row)
			{
				if (game->map.total_map[col][row] != '1')
				{
					hk_error("WALL IS NOT SURROUND BY WALL - row", game);
					break ;
				}
				row++;
			}
		}
		else if (game->map.total_map[col][0] != '1' || game->map.total_map[col][game->map.row - 1] != '1')
		{
			hk_error("WALL IS NOT SURROUND BY WALL - col", game);
			break ;
		}
		col++;
	}
}

void	count_PCE(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.col)
	{
		j = 0;
		while(j < game->map.row)
		{
			if (game->map.total_map[i][j] == 'P')
				game->map.p_cnt++;
			else if (game->map.total_map[i][j] == 'C')
				game->map.c_cnt++;
			else if (game->map.total_map[i][j] == 'E')
				game->map.e_cnt++;
			j++;
		}
		i++;
	}
}

void	check_PCE(t_game *game)
{
	count_PCE(game);
	if (game->map.p_cnt != 1)
		hk_error("We need only one player", game);
	else if (game->map.c_cnt < 1)
		hk_error("at least 1 collect", game);
	else if (game->map.e_cnt < 1)
		hk_error("at least 1 exit", game);
}

void	valid_map(t_game *game)
{
	check_rec(game);
	check_wall(game);
	check_PCE(game);
}

void	map_init(t_game *game, char *line)
{
	game->map.row = ft_strlen(line);
	game->map.col = 0;
	game->map.c_cnt = 0;
	game->map.p_cnt = 0;
	game->map.e_cnt = 0;
	game->map.total_map = (char **)malloc(sizeof(char *));
}

void	map_read(t_game *game, int fd)
{
	char	*line;

	line = get_line(fd);
	if (line == NULL)
		return ;
	map_init(game, line);
	game->map.total_map[game->map.col] = line;
	while (line)
	{
		game->map.col++;
		game->map.total_map = (char **)hk_realloc(game->map.total_map, game->map.col - 1, game->map.col);
		game->map.total_map[game->map.col - 1] = line;
		line = get_line(fd);
	}
	valid_map(game);
}

void	hk_window(t_game *game, char **argv)
{
	int fd;
	int	col;
	
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		hk_error("FD ERROR !", game);
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		hk_error("Wrong argument", game);
	map_read(game, fd);
	//game->map.row = hk_window_size(fd, &col) * 64;
	//if (col <= 1)
	//	hk_error("Too short file content", game);
	//game->map.col = col * 64;
}


