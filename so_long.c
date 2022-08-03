#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>


void	*ft_make_xpm_img(t_game *game, char *xpmFile)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(game->mlx, xpmFile, &width, &height);
	if (!img)
	{
		printf ("xpm PATH: %s\n", xpmFile);
		hk_error("check xpm PATH or file name", game);
	}
	else if (width != 64 || height != 64)
		hk_error("img size incorrect", game);
	return (img);
}	



void	init_img(t_game *game)
{
	game->img.exit = ft_make_xpm_img(game->mlx, "./map/church.xpm");
	//game->img.item = ft_make_xpm_img(game->mlx, "./map/item.xpm");
	//game->img.floor = ft_make_xpm_img(game->mlx, "./map/floor.xpm");

	//game->img. = ft_make_xpm_img(game->mlx, "./map/floor.xpm");
}

void	ft_make_sprite(t_game *game, t_sprite **sprite, char *file, int cnt)
{
	t_sprite	*tmp;
	int			i;
	char		*xpm;
	char		*temp;
	int			num;

	i = 0;
	while (i < cnt)
	{
		num = '0' + i;
		temp = ft_strjoin(file, (char *)&num);
		xpm = ft_strjoin(temp, ".xpm");
		tmp->img = ft_make_xpm_img(game, xpm);
		free(temp);
		free(xpm);
		if (i != cnt - 1)
		{
			tmp->next = malloc(sizeof(t_sprite));
			tmp = tmp->next;
		}
		i++;
	}
}


void	init_sprite(t_game *game)
{
	ft_make_sprite(game, &game->player.r_sprite, "player", 10);
}

void draw_img(t_game *game, int target)
{
	int	height;
	int width;

	height = 0;
	printf("game width : %d || game height : %d\n", game->map.width, game->map.height);
	while (height < game->map.height)
	{
		width = 0;
		while (width < game->map.width)
		{
			if (game->map.total_map[height][width] == target)
				mlx_put_image_to_window(game->mlx, game->win, game->img.wall, width * 64, height * 64);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->img.floor, width * 64, height * 64);
			width++;
		}
		height++;
	}
}


void	init_game(t_game *game)
{
	game->player.collect = 0;
	game->player.walk = 0;
}
void	start_game(t_game *game)
{
	init_game(game);
	init_img(game);
	//draw_img(game, 1);
}

//void	valid_map()
//{

//}

//void	parse_map(t_game *game, char **argv)
//{
	// valid_map(argv);
	
//}

int destroy_win(t_game *game)
{
	hk_error("The End", game);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int hk_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		destroy_win(game);
	//else if (keycode == KEY_A)
	//	//left
	//else if (keycode == KEY_S)
	//	//down
	//else if (keycode == KEY_D)
	//	//right
	//else if (keycode == KEY_W)
	//	//up
	return (0);
}

int main(int argc, char **argv)
{
	t_game	game;
	if (argc != 2)
		hk_error("Wrong Argument", &game);
	hk_window(&game, argv);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.width * 64, game.map.height * 64, "JUNHYUKI IS CHRISTIAN!!");
	start_game(&game);
	//parse_map(&game, argv);
	// game.map.row *= 1000;
	// game.map.col *= 1000;
	// game.img.floor = mlx_xpm_file_to_image(game.mlx, "./map/player.xpm", &game.map.row, &game.map.col);
	//mlx_put_image_to_window(game.mlx, game.win, game.img.floor, 1000 , 500);
	//init_game(&game);
	mlx_hook(game.win, KEY_EXIT, 0, &destroy_win, &game);
	mlx_key_hook(game.win, hk_key_hook, &game);
	mlx_loop(game.mlx);
}