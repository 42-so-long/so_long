/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankyuhong <hankyuhong@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:44:10 by kyhan             #+#    #+#             */
/*   Updated: 2022/07/29 19:18:14 by hankyuhong       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
