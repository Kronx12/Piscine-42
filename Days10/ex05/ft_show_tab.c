/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_show_tab.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/16 05:58:34 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/18 00:20:16 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

void				ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
	ft_putchar('\n');
}

int					ft_pow(int v, int p)
{
	int	res;

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

void				ft_putnbr(int nb)
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

void				ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = -1;
	while (par[++i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
	}
}
