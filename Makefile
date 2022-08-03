ALL :
	arch -X86_64 gcc -L./mlx -lmlx -framework OpenGL -framework AppKit *.c -g
