#include "so_long.h"

void	move_left(t_game *game)
{
	if (game->map.total_map[game->player.y / 64] \
	[(game->player.x - 64) / 64] == '1')
		return ;
	draw_wall(game);
	draw_pce(game);
	game->l_sprite = game->l_sprite->next;
	mlx_put_image_to_window(game->mlx, game->win, game->l_sprite->img, \
	game->player.x - game->i, game->player.y);
	game->i += 8;
	if (game->i >= 64)
	{
		game->flag = 0;
		game->i = 0;
		game->player.x -= 64;
		if (game->map.total_map[game->player.y / 64] \
		[game->player.x / 64] == 'a')
		{
			game->map.total_map[game->player.y / 64][game->player.x / 64] = 'c';
			game->player.collect++;
		}
	}
}

void	move_right(t_game *game)
{
	if (game->map.total_map[game->player.y / 64] \
	[(game->player.x + 64) / 64] == '1')
		return ;
	draw_wall(game);
	draw_pce(game);
	game->r_sprite = game->r_sprite->next;
	mlx_put_image_to_window(game->mlx, game->win, game->r_sprite->img, \
	game->player.x + game->i, game->player.y);
	game->i += 8;
	if (game->i >= 64)
	{
		game->flag = 0;
		game->i = 0;
		game->player.x += 64;
		if (game->map.total_map[game->player.y / 64] \
		[game->player.x / 64] == 'a')
		{
			game->map.total_map[game->player.y / 64] \
			[game->player.x / 64] = 'c';
			game->player.collect++;
		}
	}
}
