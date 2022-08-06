#include "so_long.h"

void	left(int keycode, t_game *game)
{
	game->player.move_status = LEFT;
	game->flag = LEFT;
}

void	right(int keycode, t_game *game)
{
	game->flag = RIGHT;
	game->player.move_status = RIGHT;
}

void	up(int keycode, t_game *game)
{
	game->flag = TOP;
}

void	down(int keycode, t_game *game)
{
	game->flag = BOTTOM;
}
