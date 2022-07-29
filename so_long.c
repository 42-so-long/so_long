#include "so_long.h"

void	init_game(t_game *game)
{
	game->player.collect = 0;
	game->player.walk = 0;
}

//void	valid_map()
//{

//}

//void	parse_map(t_game *game, char **argv)
//{
	// valid_map(argv);
	
//}

int main(int argc, char **argv)
{
	t_game game;
	if (argc != 2)
		hk_error("Too many argument", &game);
	hk_window(&game, argv);
	//parse_map(&game, argv);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 500, 500, "JUNHYUKI IS CHRISTIAN!!");
	// game.map.row *= 1000;
	// game.map.col *= 1000;
	// game.img.floor = mlx_xpm_file_to_image(game.mlx, "./map/player.xpm", &game.map.row, &game.map.col);
	//mlx_put_image_to_window(game.mlx, game.win, game.img.floor, 1000 , 500);
	init_game(&game);
	//mlx_hook(game.win, )
	mlx_loop(game.mlx);
}