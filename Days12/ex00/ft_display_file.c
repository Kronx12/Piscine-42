/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display_file.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 05:01:09 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/17 05:48:55 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 4096

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	int		i;
	char	buf[BUF_SIZE + 1];

	if (ac < 2)
		write(1, "File name missing.\n", 19);
	else if (ac > 2)
		write(1, "Too many arguments.\n", 20);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			write(1, "Cannot read file.\n", 18);
		if (fd == -1)
			return (0);
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		i = -1;
		while (buf[++i])
			write(1, &buf[i], 1);
		if (close(fd) == -1)
			write(1, "Cannot read file.\n", 18);
	}
	return (0);
}
