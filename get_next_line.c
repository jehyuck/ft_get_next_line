/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyou <jeyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:20:43 by jeyou             #+#    #+#             */
/*   Updated: 2022/05/18 21:18:50 by jeyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_del_line(char *stock)
{
	int		i;
	int		j;
	char	*rtn;

	i = 0;
	if (stock[0] == 0)
		return (0);
	while (stock[i] && stock[i] != '\n')
		i++;
	rtn = (char *)malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (!rtn)
		return (0);
	if (stock[i] == '\n')
		i++;
	j = 0;
	while (stock[i + j])
	{
		rtn[j] = stock[i + j];
		j++;
	}
	rtn[j] = 0;
	free(stock);
	return (rtn);
}

char	*ft_get_line(char *stock)
{
	char	*rtn;
	int		i;

	if (!stock[0])
	{
		free(stock);
		return (0);
	}
	i = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	rtn = (char *)malloc(sizeof(char) * (i + 2));
	i = 0;
	while (stock[i] != '\n' && stock[i])
	{
		rtn[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
	{
		rtn[i] = '\n';
		i++;
	}
	rtn[i] = 0;
	return (rtn);
}

char	*ft_read_stock_char(int fd, char *stock_char, char *buf)
{
	int		read_v;
	char	*rtn;

	if (stock_char == 0)
	{
		stock_char = (char *)malloc(sizeof(char));
		stock_char[0] = 0;
	}
	rtn = stock_char;
	read_v = read(fd, buf, BUFFER_SIZE);
	while (read_v)
	{
		if (read_v <= 0)
			return (rtn);
		buf[read_v] = 0;
		rtn = ft_strjoin(rtn, buf);
		if (!ft_strchr((const char *)buf, '\n'))
			read_v = read(fd, buf, BUFFER_SIZE);
		else
			read_v = 0;
	}
	return (rtn);
}

char	*get_next_line(int fd)
{
	char		*rtn;
	char		*buf;
	static char	*stock_char;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	stock_char = ft_read_stock_char(fd, stock_char, buf);
	free(buf);
	if (!stock_char)
		return (0);
	rtn = ft_get_line(stock_char);
	stock_char = ft_del_line(stock_char);
	return (rtn);
}
