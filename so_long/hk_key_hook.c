#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	hk_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		destroy_win(game);
	else if (keycode == KEY_A)
		left(keycode, game);
	else if (keycode == KEY_D)
		right(keycode, game);
	else if (keycode == KEY_S)
		down(keycode, game);
	else if (keycode == KEY_W)
		up(keycode, game);
	else
		game->player.move_status = NONE;
	return (0);
}
