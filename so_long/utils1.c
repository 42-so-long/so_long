#include "so_long.h"

void	map_destroy(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.total_map[i++])
		free(game->map.total_map[i]);
}

void	hk_error(char *str, t_game *game)
{
	// if (game->player.exit_flag == SUCCESS)
	// 	mlx_destroy_window(game->mlx, game->win);
	//if (game == NULL)
	//{
	//	ft_putendl_fd(str, 2);
	//	exit(0);	
	//}
	// if (game->map.total_map)
	// 	map_destroy(game);
	ft_putendl_fd(str, 2);
	if (game->player.exit_flag == SUCCESS)
		exit(0);
	exit(1);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	chr;
	size_t	i;

	last = (char *)s;
	chr = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (last[i] == chr)
			return (last + i);
		i--;
	}
	if (last[i] == chr)
		return (last);
	return (0);
}

char	*ft_strnstr(const char *hay, const char *nid, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*nid == '\0')
	{
		return ((char *)hay);
	}
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (hay[i + j] == nid[j] && (i + j) < len)
		{
			j++;
			if (nid[j] == '\0')
			{
				return ((char *)(&hay[i]));
			}
		}
		i++;
	}
	return (0);
}
