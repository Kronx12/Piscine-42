/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 21:59:20 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 14:21:58 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

#define BUF_SIZE 4096

char			*get_dict(char *file)
{
	char	*data;
	int		fd;

	data = malloc(sizeof(char) * BUF_SIZE);
	fd = open(file, O_RDONLY);
	if (read(fd, data, BUF_SIZE) < 0)
	{
		write(2, "Dict Error", 10);
		return (0);
	}
	close(fd);
	return (data);
}

int				get_strlen(int i, char *str)
{
	int start;

	start = i;
	while (str[i] != '\n' && str[i])
		i++;
	return (i - start + 1);
}

int				*get_int_tab_from_dict(char *data, int size)
{
	int		*tab;
	int		i;
	int		j;
	int		k;
	char	str[20];

	i = -1;
	j = -1;
	k = -1;
	tab = malloc(sizeof(int) * size);
	while (data[++i])
	{
		if (data[i] != '\n' && data[i] >= '0' && data[i] <= '9')
			str[++j] = data[i];
		else if (data[i] == '\n')
		{
			tab[++k] = ft_atoi(str);
			j = -1;
			while (str[++j])
				str[j] = 0;
			j = -1;
		}
	}
	return (tab);
}

char			**get_str_tab_from_dict(char *data, char **tab, int size)
{
	int i;
	int j;
	int k;

	j = 0;
	i = -1;
	while (++i < size)
	{
		while (data[j] != ':')
			j++;
		while (data[++j] == ' ')
			;
		if (!(tab[i] = malloc(sizeof(char *) * get_strlen(i, data))))
			return (0);
		k = 0;
		while (data[j] != '\n')
		{
			tab[i][k] = data[j];
			k++;
			j++;
		}
	}
	return (tab);
}

struct s_value	*transform_dict_tab_to_struct(char *val)
{
	struct s_value	*tab;
	int				*int_tab;
	char			**str_tab;
	int				size;
	int				i;

	size = 0;
	i = -1;
	while (val[++i])
		if (val[i] == '\n')
			size++;
	int_tab = get_int_tab_from_dict(val, size);
	if (!(str_tab = malloc(sizeof(str_tab) * size))
			|| !(tab = malloc(sizeof(tab) * (size + 1))))
		return (0);
	get_str_tab_from_dict(val, str_tab, size);
	tab[size].str = 0;
	i = -1;
	while (++i < size)
	{
		tab[i].val = int_tab[i];
		tab[i].count = 0;
		tab[i].str = ft_strdup(str_tab[i]);
	}
	return (tab);
}
