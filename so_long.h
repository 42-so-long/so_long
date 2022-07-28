#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
//# include "libft/libft.h"
# include "get_next_line_bonus.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	int			row;
	int			col;
}				t_map;

typedef struct s_img
{
	void		*wall;
	void		*floor;
	void		*coin;
}				t_img;

typedef struct s_player
{
	int			walk;
	int			collect;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map1;
	t_img		img;
	t_map		map;
	t_player	player;
}				t_game;

void	hk_window(t_game *game, char **argv);
char	*ft_strnstr(const char *hay, const char *nid, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *p, int c, size_t len);


#endif