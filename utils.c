#include "so_long.h"

void	hk_error(char *str, t_game *game)
{
	// destroy_win(game);
	ft_putendl_fd(str, 2);
	exit(1);
}