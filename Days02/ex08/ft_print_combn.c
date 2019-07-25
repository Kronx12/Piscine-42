/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_combn.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/05 01:24:26 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/06 15:55:59 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

int		is_valid(char *str, int n)
{
	int b2;
	int i;

	n--;
	b2 = 1;
	i = 0;
	while (i < n)
	{
		if (str[i] >= str[i + 1])
			b2 = 0;
		i++;
	}
	return (b2);
}

int		is_last(char *str, int n)
{
	if ((str[0] == '0' + 10 - n) && is_valid(str, n))
		return (1);
	if (is_valid(str, n))
		write(1, ", ", 2);
	return (0);
}

void	ft_print(char *str, int n)
{
	int b;
	int l;
	int i;

	b = 1;
	l = n;
	i = 0;
	n--;
	while (i < n)
	{
		if (str[i] >= str[i + 1])
			b = 0;
		i++;
	}
	if (b)
	{
		write(1, str, l);
	}
}

void	change(int *p, char *str)
{
	str[*p]++;
	while (str[*p] > '9')
	{
		str[*p] = '0';
		*p -= 1;
		str[*p]++;
	}
}

void	ft_print_combn(int n)
{
	char	str[n];
	int		i;
	int		p;
	int		b;

	b = 1;
	i = 0;
	while (i != n)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	while (b > 0)
	{
		p = n - 1;
		change(&p, str);
		ft_print(str, n);
		if (is_last(str, n))
			b--;
	}
}
