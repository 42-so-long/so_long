#include "so_long.h"

void	move_player(t_game *game)
{
	if (game->flag == LEFT)
		move_left(game);
	else if (game->flag == RIGHT)
		move_right(game);
	else if (game->flag == TOP)
		move_up(game);
	else if (game->flag == BOTTOM)
		move_down(game);
}

int	hk_loop_hook(t_game *game)
{
	if (game->status == ON)
	{
		update(game);
		out_move_cnt(game);
	}
	return (0);
}

void check_leaks() { system("leaks a.out"); }

int	main(int argc, char **argv)
{
	atexit(check_leaks);
	t_game	game;

	if (argc != 2)
	{
		ft_putendl_fd("WRONG ARUG", 2);
		exit(0);
	}
	hk_window(&game, argv);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.width * 64, \
	game.map.height * 64, "JUNHYUKI IS CHRISTIAN!!");
	start_game(&game);
	mlx_hook(game.win, KEY_EXIT, 0, &destroy_win, &game);
	mlx_key_hook(game.win, hk_key_hook, &game);
	mlx_hook(game.win, 02, 0, hk_hook, &game);
	mlx_loop_hook(game.mlx, hk_loop_hook, &game);
	mlx_loop(game.mlx);
	free_node(&game);
	return (0);
}