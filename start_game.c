#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>


void	start_game(t_game *game)
{
	init_game(game);
	init_img(game);
	draw_wall(game);
	draw_PCE(game);
}

void	init_game(t_game *game)
{
	game->player.collect = 0;
	game->player.move_count = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.collect_status = FAIL;
	game->player.exit_flag = FAIL;
	game->r_sprite = 0;
	game->l_sprite = 0;
	game->status = OFF;
	init_player(game);
	//init_enemy(game);	
}

void	init_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	init_sprite(game, PLAYER);
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

void	init_sprite(t_game *game, int	flag)
{
	
	//game->player.r_sprite = (t_sprite *)malloc(sizeof(t_sprite));
	//game->player.l_sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (flag == PLAYER)
	{
		//str = ft_strdup("./map/player1");
		hk_make_rsprite(game);
		hk_make_lsprite(game);
		//game->player.r_sprite->img = ft_make_xpm_img(game, "./map/player1");
		//ft_make_sprite_rev(game, &game->player.l_sprite, str, 10);
	}
}

void	init_enemy(t_game *game)
{
	int	i;
	int	j;
	int k;

	i = 0;
	k = 0;
	// init_sprite(game, ENEMY);
	game->enemy.x = (int *)malloc(sizeof(int) * game->map.enemy_cnt);
	game->enemy.y = (int *)malloc(sizeof(int) * game->map.enemy_cnt);
	while (i < game->map.height)
	{
		j = 0;
		while(j < game->map.width)
		{
			if (game->map.total_map[i][j] == 'e')
			{
				game->enemy.x[k] = j * 64;
				game->enemy.y[k] = i * 64;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	init_img(t_game *game)
{
	game->img.exit = ft_make_xpm_img(game, "./map/church.xpm");
	game->img.item = ft_make_xpm_img(game, "./map/item.xpm");
	game->img.floor = ft_make_xpm_img(game, "./map/floor.xpm");
	game->img.wall = ft_make_xpm_img(game, "./map/wall.xpm");
	game->img.player = ft_make_xpm_img(game, "./map/player0.xpm");
	game->img.cross = ft_make_xpm_img(game, "./map/cross.xpm");
	game->img.enemy = ft_make_xpm_img(game, "./map/enemy1.xpm");
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
			else if (game->map.total_map[height][width] == 'e')
				mlx_put_image_to_window(game->mlx, game->win, game->img.enemy, width * 64, height * 64);
			width++;
		}
		height++;
	}
}