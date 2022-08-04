ALL :
	cc -L./mlx -lmlx -framework OpenGL -framework AppKit *.c -fsanitize=address
