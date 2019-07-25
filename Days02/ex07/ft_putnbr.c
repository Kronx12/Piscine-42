/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 03:59:13 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/06 14:07:40 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_pow(int v, int p)
{
	int res;

	if (p == 0)
		return (1);
	else if (p == 1)
		return (v);
	else
	{
		res = v;
		while (p > 1)
		{
			res = res * v;
			p--;
		}
		return (res);
	}
}

void	ft_putnbr(int nb)
{
	int		l;
	long	tmp;
	long	nbbis;

	l = 0;
	tmp = nb;
	if (tmp < 0)
	{
		tmp *= -1;
		ft_putchar('-');
	}
	nbbis = tmp;
	while (tmp > 9)
	{
		tmp /= 10;
		l++;
	}
	while (l > 0)
	{
		ft_putchar(nbbis / ft_pow(10, l) + '0');
		nbbis = nbbis % ft_pow(10, l);
		l--;
	}
	ft_putchar(nbbis + '0');
}
