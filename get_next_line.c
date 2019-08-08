/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:54:48 by dbubnov           #+#    #+#             */
/*   Updated: 2019/06/19 15:38:38 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array	*list_create(const int fd)
{
	t_array		*head;

	if ((head = (t_array*)malloc(sizeof(t_array))) == NULL)
		return (NULL);
	head->fd_counter = fd;
	head->left_over_str = ft_strnew(BUFF_SIZE);
	head->next = NULL;
	return (head);
}

int		ft_read(int fd, char *buff, char **str, char *left_over)
{
	int						fd_number;
	char					*cp;
	int						t;

	t = 0;
	fd_number = -42;
	if (!(cp = ft_strchr(left_over, '\n')))
	{
		while (fd_number != 0 && (cp = ft_strchr(*str, '\n')) == 0 && t != 1)
		{
			fd_number = read(fd, buff, BUFF_SIZE);
			if (fd_number == -1)
				return (-1);
			buff[fd_number] = '\0';
			*str = ft_check(*str, left_over, buff, &t);
		}
	}
	else
	{
		*str = ft_strsub(left_over, 0, (cp - left_over));
		ft_strcpy(left_over, ++cp);
	}
	if (fd_number == 0)
		ft_strclr(left_over);
	return (((ft_strlen(*str) > 0 || fd_number) ? 1 : 0));
}

char	*ft_check(char *str, char *left_over, char *buff, int *t)
{
	char			*cp;
	char			*tmp;

	tmp = NULL;
	if ((cp = ft_strchr(buff, '\n')))
	{
		ft_strcpy(left_over, ++cp);
		ft_strclr(--cp);
	}
	ft_strcat(str, buff);
	tmp = str;
	str = ft_strnew(ft_strlen(tmp) + (BUFF_SIZE + 1));
	ft_strcat(str, tmp);
	ft_strdel(&tmp);
	ft_strclr(buff);
	if (cp != NULL)
		*t = 1;
	return (str);
}

int		get_line(const int fd, char **line, char *left_over)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;

	*line = ft_strnew(ft_strlen(left_over) + BUFF_SIZE + 1);
	ft_strcat(*line, left_over);
	if (((ret = ft_read(fd, buff, line, left_over)) < 0) || fd < 0)
		return (-1);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static	t_array	*data_list;
	t_array			*tmp;
	int				ret;

	if (fd < 0 || line == 0)
		return (-1);
	if (data_list == NULL)
		data_list = list_create(fd);
	tmp = data_list;
	while (tmp->fd_counter != fd)
	{
		if (tmp->next == NULL)
			tmp->next = list_create(fd);
		tmp = tmp->next;
	}
	ret = get_line(fd, line, tmp->left_over_str);
	return (ret);
}
