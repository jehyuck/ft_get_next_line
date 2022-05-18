/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyou <jeyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:31:53 by jeyou             #+#    #+#             */
/*   Updated: 2022/04/22 19:07:45 by jeyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtn;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	rtn = (char *)malloc(s1_len + s2_len + 1);
	if (!rtn)
		return (0);
	i = -1;
	while (s1[++i])
		rtn[i] = s1[i];
	i = -1;
	while (s2[++i])
		rtn[s1_len + i] = s2[i];
	rtn[s1_len + i] = 0;
	free((char *)s1);
	return (rtn);
}
