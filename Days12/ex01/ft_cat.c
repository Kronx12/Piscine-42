/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cat.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 08:20:48 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/17 10:58:33 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 4096

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	int		i;
	int		j;
	char	buf[BUF_SIZE + 1];

	if (ac < 2)
		ft_putstr("File name missing.\n");
	else
	{
		j = 0;
		while (++j < ac)
		{
			fd = open(av[j], O_RDONLY);
			if (fd == -1)
			{
				ft_putstr("cat: ");
				ft_putstr(av[j]);
				ft_putstr(": No such file or directory\n");
			}
			else
			{
				ret = read(fd, buf, BUF_SIZE);
				buf[ret] = '\0';
				i = -1;
				while (buf[++i])
					write(1, &buf[i], 1);
				if (close(fd) == -1)
					ft_putstr("Cannot read file.\n");
			}
		}
	}
	return (0);
}
