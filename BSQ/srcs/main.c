/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/19 09:26:50 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 21:29:21 by jedelfos    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_lib.h"

int		error(void)
{
	write(1, "map error\n", 10);
	return (0);
}

void	ft_putmap(char *str)
{
	int i;

	if (ft_resolve(str) == 0)
		ERROR();
	else
	{
		i = 0;
		while (str++[0] != '\n')
			;
		while (str[++i])
			;
		write(1, &str[0], i);
	}
}

int		malloc_top(char *map, unsigned long i, char *tmp, int fd)
{
	long long		r;

	if (!(map = malloc(sizeof(char) * (get_w(tmp) + 10) * (get_h(tmp) + 10))))
		return (error());
	i = -1;
	while (tmp[++i])
		map[i] = tmp[i];
	while ((r = read(fd, map + i, 8300000)))
		i += r;
	map[i] = '\0';
	free(tmp);
	ft_putmap(map);
	return (0);
}

int		read_top(int fd)
{
	unsigned long	i;
	int				b;
	char			*tmp;
	char			*map;

	map = 0;
	if (!(tmp = malloc(sizeof(char) * 20000)))
		return (error());
	i = -1;
	b = 0;
	read(fd, &tmp[++i], 1);
	if (tmp[0] == '0' || tmp[0] == '\0')
		return (error());
	while (read(fd, &tmp[++i], 1) && b != 2)
	{
		if (b == 1 && tmp[i - 1] == '\n' && tmp[i] == '\n')
			return (error());
		if (tmp[i] == '\n')
			b++;
	}
	malloc_top(map, i, tmp, fd);
	return (0);
}

int		main(int ac, char **av)
{
	int i;
	int fd;

	i = 0;
	if (ac == 1)
	{
		fd = STDIN_FILENO;
		read_top(fd);
		close(fd);
	}
	else
		while (++i < ac)
		{
			fd = open(av[i], O_RDONLY);
			read_top(fd);
			close(fd);
			if (i != ac - 1)
				write(1, "\n", 1);
		}
	return (0);
}
