#include "so_long.h"

void	move_up_move(t_game *game)
{
	game->i += 8;
	if (game->i >= 64)
	{
		game->flag = 0;
		game->i = 0;
		game->player.y -= 64;
		if (game->map.total_map[game->player.y / 64] \
		[game->player.x / 64] == 'a')
		{
			game->map.total_map[game->player.y / 64] \
			[game->player.x / 64] = 'c';
			game->player.collect++;
		}
	}
}

void	move_up(t_game *game)
{
	if (game->map.total_map[(game->player.y - 64) / 64] \
	[game->player.x / 64] == '1')
		return ;
	draw_wall(game);
	draw_pce(game);
	if (game->player.move_status == RIGHT)
	{
		game->r_sprite = game->r_sprite->next;
		mlx_put_image_to_window(game->mlx, game->win, game->r_sprite->img, \
		game->player.x, game->player.y - game->i);
	}
	else
	{
		game->l_sprite = game->l_sprite->next;
		mlx_put_image_to_window(game->mlx, game->win, game->l_sprite->img, \
		game->player.x, game->player.y - game->i);
	}
	move_up_move(game);
}

void	move_down_move(t_game *game)
{
	game->i += 8;
	if (game->i >= 64)
	{
		game->flag = 0;
		game->i = 0;
		game->player.y += 64;
		if (game->map.total_map[game->player.y / 64] \
		[game->player.x / 64] == 'a')
		{
			game->map.total_map[game->player.y / 64] \
			[game->player.x / 64] = 'c';
			game->player.collect++;
		}
	}
}

void	move_down(t_game *game)
{
	if (game->map.total_map[(game->player.y + 64) / 64] \
	[game->player.x / 64] == '1')
		return ;
	draw_wall(game);
	draw_pce(game);
	if (game->player.move_status == RIGHT)
	{
		game->r_sprite = game->r_sprite->next;
		mlx_put_image_to_window(game->mlx, game->win, game->r_sprite->img, \
		game->player.x, game->player.y + game->i);
	}
	else
	{
		game->l_sprite = game->l_sprite->next;
		mlx_put_image_to_window(game->mlx, game->win, game->l_sprite->img, \
		game->player.x, game->player.y + game->i);
	}
	move_down_move(game);
}
