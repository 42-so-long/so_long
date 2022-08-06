#include "so_long.h"

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

void	ft_put(char *str, int len, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		str[i] = 48;
	while (n != 0)
	{
		str[len - i - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
}

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (10);
		else
			n = -n;
	}
	else if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		minus;
	int		len;

	minus = (n < 0);
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + minus + 1));
	if (str == 0)
		return (NULL);
	str[len + minus] = '\0';
	if (n == -2147483648)
	{
		str[10] = '8';
		n = 214748364;
		str[0] = '-';
		len--;
	}
	else if (minus == 1)
	{
		str[0] = '-';
		n = -n;
	}
	ft_put(&str[minus], len, n);
	return (&str[0]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}
