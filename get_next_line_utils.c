/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:20:27 by hchang            #+#    #+#             */
/*   Updated: 2022/08/02 17:10:29 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_lstfclean(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		idx;
	char	*result;

	idx = 0;
	while (s1[idx])
		idx++;
	result = malloc(sizeof(char) * (idx + 1));
	if (!(result))
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		result[idx] = s1[idx];
		idx++;
	}
	result[idx] = '\0';
	return (result);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	idx;

	idx = 0;
	dst_len = 0;
	src_len = 0;
	while (dst[dst_len])
		dst_len++;
	while (src[src_len])
		src_len++;
	if (dst_len + 1 > dstsize)
		return (dstsize + src_len);
	while ((dst_len + idx < dstsize - 1) && src[idx])
	{
		dst[dst_len + idx] = src[idx];
		if (src[idx++] == '\n')
			break ;
	}
	dst[dst_len + idx] = '\0';
	return (dst_len + src_len);
}

t_list	*ft_lstnew_add_back(t_list **lst, void *content)
{
	t_list	*new;
	t_list	*tmp;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	if (!lst)
		return (NULL);
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
