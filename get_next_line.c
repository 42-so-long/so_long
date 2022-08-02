/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:20:02 by hchang            #+#    #+#             */
/*   Updated: 2022/05/13 17:43:02 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	check_enter_len(const char *s, int c, size_t *len)
{
	int	idx;

	idx = 0;
	while (s[*len])
		(*len)++;
	while (s[idx])
	{
		if (s[idx] == (unsigned char)c)
			return (idx);
		idx++;
	}
	return (-1);
}

size_t	check_line(int fd, t_list **res_lst, size_t *res_len)
{
	t_list	*curr;
	ssize_t	rd;
	size_t	enter_pos;
	size_t	content_len;

	curr = *res_lst;
	while (1)
	{
		content_len = 0;
		if (curr)
		{
			enter_pos = check_enter_len((curr)->content, '\n', &content_len);
			if (enter_pos != (size_t) - 1)
			{
				*res_len += (enter_pos + 1);
				return (rd);
			}
			*res_len += content_len;
		}
		curr = read_line(fd, res_lst, &rd);
		if (!curr)
			return (rd);
	}
	return (rd);
}

t_list	*read_line(int fd, t_list **t_back, ssize_t *rd)
{
	char		*tmp;

	tmp = (char *)malloc(BUFFER_SIZE + 1);
	*rd = read(fd, tmp, BUFFER_SIZE);
	if (*rd <= 0)
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	tmp[*rd] = '\0';
	return (ft_lstnew_add_back(t_back, tmp));
}

char	*make_line(t_list **res_lst, size_t res_len)
{
	size_t	tmp;
	char	*save;
	size_t	enter_pos;
	t_list	*clean_lst;
	char	*res;

	res = (char *)malloc(sizeof(char) * (res_len + 1));
	if (!res)
		return (NULL);
	tmp = 0;
	res[0] = 0;
	clean_lst = *res_lst;
	while (*res_lst)
	{
		ft_strlcat(res, (*res_lst)->content, res_len + 1);
		if ((*res_lst)->next == NULL)
			save = (*res_lst)->content;
		*res_lst = (*res_lst)->next;
	}
	enter_pos = check_enter_len(save, '\n', &tmp);
	if ((enter_pos != (size_t)-1) && *(save + enter_pos + 1) != '\0')
		*res_lst = ft_lstnew(ft_strdup(save + (enter_pos + 1)));
	ft_lstfclean(&clean_lst);
	return (res);
}

char	*get_next_line(int fd)
{
	static t_list	*res_lst[FD_MAX];
	size_t			res_len;
	ssize_t			rd;

	res_len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || FD_MAX <= 0 || fd >= FD_MAX)
		return (NULL);
	rd = check_line(fd, &res_lst[fd], &res_len);
	if ((!rd && !res_len) || rd == -1)
		return ((char *)ft_lstfclean(&res_lst[fd]));
	return (make_line(&res_lst[fd], res_len));
}
