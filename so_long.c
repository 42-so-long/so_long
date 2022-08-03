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
	game->img.exit = ft_make_xpm_img(game, "./map/church.xpm");
	game->img.item = ft_make_xpm_img(game, "./map/item.xpm");
	game->img.floor = ft_make_xpm_img(game, "./map/floor.xpm");
	game->img.wall = ft_make_xpm_img(game, "./map/wall.xpm");
	game->img.player = ft_make_xpm_img(game, "./map/player0.xpm");
	game->img.cross = ft_make_xpm_img(game, "./map/cross.xpm");
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

void draw_wall(t_game *game)
{
	int	height;
	int width;

	height = 0;
	while (height < game->map.height)
	{
		width = 0;
		while (width < game->map.width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img.floor, width * 64, height * 64);
			if (game->map.total_map[height][width] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img.wall, width * 64, height * 64);
			width++;
		}
		height++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.floor, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->img.cross, 0, 0);
	mlx_string_put(game->mlx, game->win, 28, 32, 0, ft_itoa(0));	
}

void draw_PCE(t_game *game)
{
	int	height;
	int width;

	height = 0;
	while (height < game->map.height)
	{
		width = 0;
		while (width < game->map.width)
		{
			if (game->map.total_map[height][width] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img.player, width * 64, height * 64);
			else if (game->map.total_map[height][width] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img.item, width * 64, height * 64);
			else if (game->map.total_map[height][width] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img.exit, width * 64, height * 64);
			width++;
		}
		height++;
	}
}


void	init_game(t_game *game)
{
	game->player.collect = 0;
	game->player.move_count = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.collect_status = FAIL;
	game->player.exit_flag = FAIL;
	init_player(game);
	
}
void	start_game(t_game *game)
{
	init_game(game);
	init_img(game);
	draw_wall(game);
	draw_PCE(game);
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

void	left(int keycode, t_game *game)
{
	game->player.move_status = LEFT;
	game->player.sprite = game->player.l_sprite;
}

void	right(int keycode, t_game *game)
{
	game->player.move_status = RIGHT;
	game->player.sprite = game->player.r_sprite;
}

void	up(int keycode, t_game *game)
{
	game->player.move_status = TOP;
}

void	down(int keycode, t_game *game)
{
	game->player.move_status = BOTTOM;
}

int hk_key_hook(int keycode, t_game *game)
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

void	move(t_game *game)
{
	printf(" y : %d : x : %d\n", game->player.y, game->player.x);
	game->player.prev_y = game->player.y;
	game->player.prev_x = game->player.x;
	if (game->player.move_status == LEFT && game->map.total_map[game->player.y / 64][game->player.x / 64 - 1] != '1')
			game->player.x -= 64;
	else if (game->player.move_status == RIGHT && game->map.total_map[game->player.y / 64][game->player.x / 64 + 1] != '1')
			game->player.x += 64;
	else if (game->player.move_status == TOP && game->map.total_map[game->player.y / 64 - 1][game->player.x / 64] != '1')
			game->player.y -= 64;
	else if (game->player.move_status == BOTTOM && game->map.total_map[game->player.y / 64 + 1][game->player.x / 64] != '1')
			game->player.y += 64;
	else
		return ;
	game->player.move_count++;
}

void	init_player(t_game *game)
{

	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while(j < game->map.width)
		{
			if (game->map.total_map[i][j] == 'P')
			{
				game->player.x = j * 64;
				game->player.y = i * 64;
			}
			j++;
		}
		i++;
	}
}

void	success_game(t_game *game)
{
	game->player.exit_flag = SUCCESS;
	hk_error("SUCCESS\n", game);
}
void	update(t_game *game)
{
	//mlx_destroy_image(game->mlx, game->img.player);
	// draw_wall(game);
	// draw_PCE(game);
	// mlx_destroy_image(game->mlx, game->img.player);
	mlx_put_image_to_window(game->mlx, game->win, game->img.floor, game->player.prev_x, game->player.prev_y);
	if (game->map.total_map[game->player.prev_y / 64][game->player.prev_x / 64] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, game->player.prev_x, game->player.prev_y);
	if (game->map.total_map[game->player.y / 64][game->player.x / 64] == 'C')
	{
		game->player.collect++;
		if (game->player.collect == game->map.c_cnt)
			game->player.collect_status = SUCCESS;
		mlx_put_image_to_window(game->mlx, game->win, game->img.floor, game->player.x, game->player.y);
		game->map.total_map[game->player.y / 64][game->player.x / 64] = 'c';
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.player, game->player.x, game->player.y);
	if (game->map.total_map[game->player.y / 64][game->player.x / 64] == 'E' && game->player.collect_status == SUCCESS)
		success_game(game);
}

void	out_move_cnt(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.cross, 0, 0);
	mlx_string_put(game->mlx, game->win, 28, 32, 0, ft_itoa(game->player.move_count));
}

int	hk_loop_hook(int keycode, t_game *game)
{
	hk_key_hook(keycode, game);
	move(game);
	update(game);
	out_move_cnt(game);
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
	mlx_hook(game.win, KEY_EXIT, 0, &destroy_win, &game);
	mlx_key_hook(game.win, hk_key_hook, &game);
	mlx_hook(game.win, 02, 0, hk_loop_hook, &game);
	mlx_loop(game.mlx);
}