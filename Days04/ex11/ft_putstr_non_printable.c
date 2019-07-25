/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr_non_printable.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/12 02:26:15 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/12 22:52:09 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*base;
	int		tmp;

	base = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		tmp = str[i];
		if (str[i] < 0)
			tmp += 256;
		if (tmp < 32 || tmp > 126)
		{
			ft_putchar('\\');
			ft_putchar(base[tmp / 16]);
			ft_putchar(base[tmp % 16]);
		}
		else
			ft_putchar(tmp);
		i++;
	}
}
