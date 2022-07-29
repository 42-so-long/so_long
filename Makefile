ALL :
	arch -arm64 gcc -L./mlx -lmlx -framework OpenGL -framework AppKit *.c
