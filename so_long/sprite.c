#include "so_long.h"

void	hk_make_rsprite2(t_game *game)
{
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./map/player5.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./map/player7.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./map/player8.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./map/player9.xpm");
}

void	hk_make_rsprite(t_game *game)
{
	t_sprite	*tmp;

	game->r_sprite = malloc(sizeof(t_sprite));
	tmp = game->r_sprite;
	game->r_sprite->img = ft_make_xpm_img(game, "./map/player0.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./map/player1.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./map/player3.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./map/player4.xpm");
	hk_make_rsprite2(game);
	game->r_sprite->next = tmp;
	game->r_sprite = tmp;
}

void	hk_make_lsprite2(t_game *game)
{
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./map/player5.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./map/player4.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./map/player3.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./map/player1.xpm");
}

void	hk_make_lsprite(t_game *game)
{
	t_sprite	*tmp;

	game->l_sprite = malloc(sizeof(t_sprite));
	tmp = game->l_sprite;
	game->l_sprite->img = ft_make_xpm_img(game, "./map/player0.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./map/player9.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./map/player8.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./map/player7.xpm");
	hk_make_lsprite2(game);
	game->l_sprite->next = tmp;
	game->l_sprite = tmp;
}

void	init_sprite(t_game *game)
{
	hk_make_rsprite(game);
	hk_make_lsprite(game);
}
