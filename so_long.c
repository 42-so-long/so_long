#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

void	hk_make_rsprite(t_game *game)
{
	t_sprite	*tmp;
	
	game->r_sprite = malloc(sizeof(t_sprite));
	tmp = game->r_sprite;
	game->r_sprite->img = ft_make_xpm_img(game, "./map/player0.xpm");
	printf("%p\n", (char *)game->r_sprite->img);
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./map/player1.xpm");
	printf("next %p\n", (char *)game->r_sprite->img);
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./map/player2.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./map/player3.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./map/player4.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./map/player5.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./map/player6.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./map/player7.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./map/player8.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./map/player9.xpm");
	game->r_sprite->next = tmp;
	game->r_sprite = tmp;
}

void	hk_make_lsprite(t_game *game)
{
	t_sprite	*tmp;
	
	game->l_sprite = malloc(sizeof(t_sprite));
	tmp = game->l_sprite;
	game->l_sprite->img = ft_make_xpm_img(game, "./map/player0.xpm");
	printf("%p\n", (char *)game->l_sprite->img);
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./map/player1.xpm");
	printf("next %p\n", (char *)game->l_sprite->img);
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./map/player2.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./map/player3.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./map/player4.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./map/player5.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./map/player6.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./map/player7.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./map/player8.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./map/player9.xpm");
	game->l_sprite->next = tmp;
}

// void	ft_make_sprite(t_game *game, t_sprite **sprite, char *file, int cnt)
// {
// 	t_sprite	*tmp;
// 	int			i;
// 	char		*xpm;
// 	char		*temp;
// 	char		*file_dir;
// 	int			num;

// 	i = 0;
// 	tmp = *sprite;
// 	printf("FILES! :%s\n", file);
// 	while (i < cnt)
// 	{
// 		num = '0' + i;
// 		printf("WHAT IS NUM ? |%d|\n", num);
// 		file_dir = ft_strdup(file);
// 		temp = ft_strjoin(file_dir, (char *)&num);
// 		//printf("HEY THIS IS TMEP : |%s|\n", temp);
// 		printf("TEMP! :%s\n", temp);
// 		xpm = ft_strjoin(temp, ".xpm");
// 		printf("HEY THIS IS XPM : |%s|\n", xpm);
// 		tmp->img = ft_make_xpm_img(game, xpm);
// 		free(xpm);
// 		if (i != cnt - 1)
// 		{
// 			tmp->next = malloc(sizeof(t_sprite));
// 			tmp = tmp->next;
// 		}
// 		i++;
// 		printf("END OF LINES\n");
// 	}
// }

//void	ft_make_sprite_rev(t_game *game, void **img, char *file, int cnt)
//{
//	t_sprite	*tmp;
//	char		*xpm;
//	char		*temp;
//	char		*file_dir;
//	int			num;
//	int			idx;

//	idx = 0;
//	while (cnt--)
//	{
//		num = '0' + idx;
//		printf("WHAT IS NUM ? |%d|\n", num);
//		file_dir = ft_strdup(file);
//		temp = ft_strjoin(file_dir, (char *)&num);
//		//printf("HEY THIS IS TMEP : |%s|\n", temp);
//		xpm = ft_strjoin(temp, ".xpm");
//		//printf("HEY THIS IS XPM : |%s|\n", xpm);
//		tmp->img = ft_make_xpm_img(game, xpm);
//		free(xpm);
//		if (cnt != 0)
//		{
//			tmp->next = malloc(sizeof(t_sprite));
//			tmp = tmp->next;
//		}
//		idx++;
//	}
//}

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
	// game->player.sprite = game->player.r_sprite;
}

void	right(int keycode, t_game *game)
{
	game->player.move_status = RIGHT;
	// game->player.sprite = game->player.r_sprite;
}

void	up(int keycode, t_game *game)
{
	game->player.move_status = TOP;
}

void	down(int keycode, t_game *game)
{
	game->player.move_status = BOTTOM;
}

void	move_player(t_game *game)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = game->player.prev_x;
	j = game->player.prev_y;
	printf("move %p\n", (char *)game->r_sprite->img);
	printf("TURN YOUR HEAD!\n");
	printf("move next %p\n", (char *)game->r_sprite->next->img);
	while(k < 400)
	{
		if (k % 40 == 0)
		{
			//printf(" y : %d : x : %d\n", game->player.y, game->player.x);
			//mlx_put_image_to_window(game->mlx, game->win, game->img.player, game->player.x, game->player.y);
			i += (game->player.x - game->player.prev_x) / 10;
			j += (game->player.y - game->player.prev_y) / 10;
			mlx_put_image_to_window(game->mlx, game->win, game->img.floor, game->player.prev_x, game->player.prev_y);
			mlx_put_image_to_window(game->mlx, game->win, game->img.floor, game->player.x, game->player.y);
			printf("move x : %d | move y : %d \n", i, j);
			mlx_put_image_to_window(game->mlx, game->win, game->r_sprite->img, i, j);
			mlx_put_image_to_window(game->mlx, game->win, game->r_sprite->img, i, j);
			mlx_put_image_to_window(game->mlx, game->win, game->r_sprite->img, i, j);
			mlx_put_image_to_window(game->mlx, game->win, game->r_sprite->img, i, j);
			mlx_put_image_to_window(game->mlx, game->win, game->r_sprite->img, i, j);
			mlx_put_image_to_window(game->mlx, game->win, game->r_sprite->img, i, j);
			mlx_put_image_to_window(game->mlx, game->win, game->r_sprite->img, i, j);
			mlx_put_image_to_window(game->mlx, game->win, game->r_sprite->img, i, j);
			mlx_put_image_to_window(game->mlx, game->win, game->r_sprite->img, i, j);
			mlx_put_image_to_window(game->mlx, game->win, game->r_sprite->img, i, j);
			mlx_put_image_to_window(game->mlx, game->win, game->r_sprite->img, i, j);
			game->r_sprite = game->r_sprite->next;
			//if (!game->player.sprite)
			//game->player.sprite = tmp;
		}
		k++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.floor, game->player.x, game->player.y);
	if (game->map.total_map[game->player.y / 64][game->player.x / 64] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, game->player.x, game->player.y);
	mlx_put_image_to_window(game->mlx, game->win, game->r_sprite->img, i, j);
}


int hk_loop_hook(int keycode, t_game *game)
{
	printf("game status %d\n", game->status);
	static int frame = 0;
	while (++frame % 500)
	{
		if (game->status == ON)
		{
			printf("HEY ! HERE \n");
			update(game);
			out_move_cnt(game);
		}
	}
	frame = 0;
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
	mlx_hook(game.win, 02, 0, hk_hook, &game);
	mlx_loop_hook(game.mlx, hk_loop_hook, &game);
	mlx_loop(game.mlx);
}