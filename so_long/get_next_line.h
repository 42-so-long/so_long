/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:20:19 by hchang            #+#    #+#             */
/*   Updated: 2022/08/02 17:10:22 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef FD_MAX
#  define FD_MAX 256
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*make_line(t_list **res_lst, size_t res_len);
size_t	check_line(int fd, t_list **t_back, size_t *res_len);
t_list	*read_line(int fd, t_list **t_back, ssize_t *rd);
void	*ft_lstfclean(t_list **lst);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	check_enter_len(const char *s, int c, size_t *len);
t_list	*ft_lstnew_add_back(t_list **lst, void *content);
t_list	*ft_lstnew(void *content);

#endif