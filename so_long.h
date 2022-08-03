#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
//# include "libft/libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>

# define KEY_EXIT 17
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_A 0
# define KEY_ESC 53
# define KEY_SPACE 49

# define NONE 0
# define LEFT 1
# define RIGHT 2
# define BOTTOM 3
# define TOP 4

typedef struct s_sprite
{
	void			*img;
	struct s_sprite	*next;
}					t_sprite;


typedef struct s_map
{
	char		**total_map;
	int			width;
	int			height;
	int			p_cnt;
	int			c_cnt;
	int			e_cnt;
}				t_map;

typedef struct s_img
{
	void		*wall;
	void		*floor;
	void		*item;
	void		*player;
	void		*exit;
}				t_img;

typedef struct s_player
{
	int			walk;
	int			collect;
	t_sprite	*r_sprite;
	t_sprite	*l_sprite;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map;
	t_player	player;
}				t_game;

void	hk_window(t_game *game, char **argv);
char	*ft_strnstr(const char *hay, const char *nid, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *p, int c, size_t len);
void	hk_error(char *str, t_game *game);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif