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

void	map_read(t_game *game, int fd)
{
	char	*line;

	game->map.row = 0;
	game->map.col = 0;
	game->map.total_map = (char **)malloc(sizeof(char *));
	line = get_line(fd);
	if (line == NULL)
		return ;
	game->map.total_map[game->map.col] = line;
	game->map.row = ft_strlen(line);
	while (line)
	{
		game->map.col++;
		game->map.total_map = (char **)hk_realloc(game->map.total_map, game->map.col - 1, game->map.col);
		game->map.total_map[game->map.col - 1] = line;
		line = get_line(fd);
	}
	printf("=====================\n");
	printf("col : %d || row : %d\n", game->map.col,game->map.row);
	for(int i = 0; i < game->map.col; i++)
		printf("|%s|\n",game->map.total_map[i]);
	printf("=====================\n");
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


