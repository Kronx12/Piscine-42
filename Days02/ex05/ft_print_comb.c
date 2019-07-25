/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_comb.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 00:19:34 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/03 02:16:33 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_u_comb(char *i, char *j, char *k)
{
	ft_putchar(*i);
	ft_putchar(*j);
	ft_putchar(*k);
	if (*i != '7' || *j != '8' || *k != '9')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char i;
	char j;
	char k;

	i = '0';
	while (i != '9' + 1)
	{
		j = '0';
		while (j != '9' + 1)
		{
			k = '0';
			while (k != '9' + 1)
			{
				if (i < j && j < k)
					ft_print_u_comb(&i, &j, &k);
				k++;
			}
			j++;
		}
		i++;
	}
}
