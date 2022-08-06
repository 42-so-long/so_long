#include "so_long.h"

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
	game->img.enemy = ft_make_xpm_img(game, "./map/enemy1.xpm");
}
