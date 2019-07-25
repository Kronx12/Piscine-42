/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/08 17:59:07 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/12 06:04:24 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_valid(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if ((base[i] == base[j] && i != j)
					|| base[i] == '+' || base[i] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return ((i == 0 || i == 1) ? 0 : i);
}

int		ft_pow(int v, int p)
{
	if (p == 0)
		return (1);
	else if (p == 1)
		return (v);
	else
		return (v * ft_pow(v, p - 1));
}

int		get_max(long nbr, int base_size)
{
	int i;

	i = 0;
	while (ft_pow(base_size, i) < nbr)
		i++;
	return (i);
}

void	ft_putnbr_base(long nbr, char *base)
{
	int			base_size;
	int			max;
	int			last;
	long	int	nb;
	
	nb = nbr;
	base_size = is_valid(base);
	if (base_size)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		max = get_max(nb, base_size) - 1;
		while (max > 0)
		{
			last = nb / ft_pow(base_size, max);
			ft_putchar(base[last]);
			nb = nb - ft_pow(base_size, max) * last;
			max--;
		}
		ft_putchar(base[nb / ft_pow(base_size, max)]);
	}
}

int main ()
{

	ft_putnbr_base(7483648, "01");
	write(1, "\n", 1);
	ft_putnbr_base(5030, "0123456789abcdef");
	write(1, "\n", 1);
	ft_putnbr_base(483648, "ponevif");
	write(1, "\n", 1);
	ft_putnbr_base(-214648, "toyu");
	write(1, "\n", 1);
	ft_putnbr_base(147483648, "01234567");
	write(1, "\n", 1);
	return 0;
}
