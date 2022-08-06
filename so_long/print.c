#include "so_long.h"

void	die_game(t_game *game)
{
	hk_error("You died\n", game);
}

void	success_game(t_game *game)
{
	game->player.exit_flag = SUCCESS;
	hk_error("SUCCESS\n", game);
}

int	destroy_win(t_game *game)
{
	hk_error("The End", game);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
