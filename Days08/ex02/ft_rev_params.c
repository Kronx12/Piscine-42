/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_rev_params.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/09 15:44:25 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/09 15:51:48 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (str++[0])
		write(1, str - 1, 1);
}

int		main(int argc, char **argv)
{
	while (argc-- > 1)
	{
		ft_putstr(argv[argc]);
		write(1, "\n", 1);
	}
	return (0);
}
