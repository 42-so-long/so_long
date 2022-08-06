#include "so_long.h"

void	*hk_realloc(void *buf, int before_size, int after_size)
{
	char	**src;
	char	**dst;
	int		idx;

	src = (char **)buf;
	dst = (char **)malloc((sizeof(char *) * after_size));
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

void	free_rsprite(t_game *game)
{
	t_sprite	*tmp;

	tmp = game->r_sprite;
	while (game->r_sprite)
	{
		game->r_sprite = game->r_sprite->next;
		free(tmp);
	}
}

void	free_lsprite(t_game *game)
{
	t_sprite	*tmp;

	tmp = game->l_sprite;
	while (game->l_sprite)
	{
		game->l_sprite = game->l_sprite->next;
		free(tmp);
	}
}

void	free_node(t_game *game)
{
	free_rsprite(game);
	free_lsprite(game);
}
