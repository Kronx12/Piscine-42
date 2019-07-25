/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_comb2.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 02:19:21 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/06 16:59:56 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = -1;
	b = -2;
	while (++a <= 98)
	{
		while (++b <= 99)
		{
			if (a < b)
			{
				ft_putchar(a / 10 + '0');
				ft_putchar(a % 10 + '0');
				ft_putchar(' ');
				ft_putchar(b / 10 + '0');
				ft_putchar(b % 10 + '0');
				if (a != 98 || b != 99)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
		b = -2;
	}
}
