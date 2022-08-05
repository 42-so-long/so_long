#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	hk_hook(int keycode, t_game *game)
{
	game->status = ON;
	hk_key_hook(keycode, game);
	move(game);

	return (0);
}

void	move(t_game *game)
{
	printf(" y : %d : x : %d\n", game->player.y, game->player.x);
	game->player.prev_y = game->player.y;
	game->player.prev_x = game->player.x;
	// if (game->player.move_status == LEFT && game->map.total_map[game->player.y / 64][game->player.x / 64 - 1] != '1')
	// 		game->player.x -= 64;
	// else if (game->player.move_status == RIGHT && game->map.total_map[game->player.y / 64][game->player.x / 64 + 1] != '1')
	// 		game->player.x += 64;
	// else if (game->player.move_status == TOP && game->map.total_map[game->player.y / 64 - 1][game->player.x / 64] != '1')
	// 		game->player.y -= 64;
	// else if (game->player.move_status == BOTTOM && game->map.total_map[game->player.y / 64 + 1][game->player.x / 64] != '1')
	// 		game->player.y += 64;
	// else
	// 	return ;
	game->player.move_count++;
}

void	update(t_game *game)
{
	// mlx_put_image_to_window(game->mlx, game->win, game->img.floor, game->player.prev_x, game->player.prev_y);
	if (game->map.total_map[game->player.y / 64][game->player.x / 64] == 'e')
		die_game(game);
	if (game->map.total_map[game->player.y / 64][game->player.x / 64] == 'C')
	{
		game->player.collect++;
		if (game->player.collect == game->map.c_cnt)
			game->player.collect_status = SUCCESS;
		mlx_put_image_to_window(game->mlx, game->win, game->img.floor, game->player.x, game->player.y);
		game->map.total_map[game->player.y / 64][game->player.x / 64] = 'c';
	}
	//mlx_put_image_to_window(game->mlx, game->win, game->img.player, game->player.x, game->player.y);
	move_player(game);
	if (game->map.total_map[game->player.prev_y / 64][game->player.prev_x / 64] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, game->player.prev_x, game->player.prev_y);
	if (game->map.total_map[game->player.y / 64][game->player.x / 64] == 'E' && game->player.collect_status == SUCCESS)
		success_game(game);
}

void	die_game(t_game *game)
{
	hk_error("You died\n", game);
}

void	success_game(t_game *game)
{
	game->player.exit_flag = SUCCESS;
	hk_error("SUCCESS\n", game);
}

void	out_move_cnt(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.cross, 0, 0);
	mlx_string_put(game->mlx, game->win, 28, 32, 0, ft_itoa(game->player.move_count));
}
