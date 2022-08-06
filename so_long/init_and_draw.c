#include "so_long.h"

void	init_game(t_game *game)
{
	game->player.collect = 1;
	game->player.move_count = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.collect_status = FAIL;
	game->player.exit_flag = FAIL;
	game->r_sprite = 0;
	game->l_sprite = 0;
	game->status = OFF;
	game->i = 0;
	init_player(game);
}

void	init_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	init_sprite(game);
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
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

void	draw_wall(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->map.height)
	{
		width = 0;
		while (width < game->map.width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img.floor, \
			width * 64, height * 64);
			if (game->map.total_map[height][width] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img.wall, \
				width * 64, height * 64);
			width++;
		}
		height++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.floor, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->img.cross, 0, 0);
	mlx_string_put(game->mlx, game->win, 28, 32, 0, ft_itoa(0));
}

void	draw_pce2(t_game *game, int height, int width)
{
	if (game->map.total_map[height][width] == 'P' \
	&& game->status == OFF)
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img.player, width * 64, height * 64);
	else if (game->map.total_map[height][width] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img.item, width * 64, height * 64);
	else if (game->map.total_map[height][width] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img.exit, width * 64, height * 64);
	else if (game->map.total_map[height][width] == 'e')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img.enemy, width * 64, height * 64);
}

void	draw_pce(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->map.height)
	{
		width = 0;
		while (width < game->map.width)
		{
			draw_pce2(game, height, width);
			width++;
		}
		height++;
	}
}
