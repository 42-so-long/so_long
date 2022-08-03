#include "so_long.h"

void	hk_error(char *str, t_game *game)
{
	// map_destroy(game);
	ft_putendl_fd(str, 2);
	exit(1);
}

void	map_destroy(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.total_map[i])
		free(game->map.total_map[i++]);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	chr;
	size_t	i;

	last = (char *)s;
	chr = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (last[i] == chr)
			return (last + i);
		i--;
	}
	if (last[i] == chr)
		return (last);
	return (0);
}

char	*ft_strnstr(const char *hay, const char *nid, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*nid == '\0')
	{
		return ((char *)hay);
	}
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (hay[i + j] == nid[j] && (i + j) < len)
		{
			j++;
			if (nid[j] == '\0')
			{
				return ((char *)(&hay[i]));
			}
		}
		i++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] != '\0' && i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	if (str1[i] == '\0' && i < n)
	{
		return (str1[i] - str2[i]);
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

void	*ft_memset(void *p, int c, size_t len)
{
	size_t	i;
	char	*arr;

	i = 0;
	arr = (char *)p;
	while (i < len)
	{
		arr[i] = (unsigned char)c;
		i++;
	}
	return ((void *)arr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_str;
	unsigned int	total_len;
	unsigned int	idx;

	if (!s1 || !s2)
		return (NULL);
	idx = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(sizeof(char) * (total_len + 1));
	if (!(new_str))
		return (NULL);
	ft_memcpy(new_str, s1, ft_strlen(s1));
	ft_memcpy(new_str + ft_strlen(s1), s2, ft_strlen(s2));
	new_str[total_len] = '\0';
	return (new_str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int					idx;
	unsigned char		*dst2;
	const unsigned char	*src2;

	idx = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	dst2 = dst;
	src2 = src;
	while (n)
	{
		dst2[idx] = src2[idx];
		n--;
		idx++;
	}
	return (dst2);
}
