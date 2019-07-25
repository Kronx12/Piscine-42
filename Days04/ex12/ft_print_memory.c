/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_memory.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/12 01:08:40 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/15 21:18:42 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (str++[0])
		write(1, &str[-1], 1);
}

void	ft_print_address(long int addr)
{
	char *base;

	base = "0123456789abcdef";
	if (addr < 0)
		ft_putchar('.');
	if (addr > 15)
	{
		ft_print_address(addr / 16);
		ft_putchar(base[addr % 16]);
	}
	else
	{
		ft_putchar(base[addr % 16]);
	}
}

void	ft_print_hex(void *addr, int size)
{
	int i;
	int value;

	i = 0;
	while (i < size)
	{
		value = *(char *)(addr + i);
		if (value < 16)
			ft_putchar('0');
		ft_print_address(value);
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
	while (i < 16)
	{
		ft_putstr("  ");
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				value;

	i = 0;
	while (i < size)
	{
		value = *(char *)(addr + i);
		if (i % 16 == 0)
		{
			ft_print_address((long)addr + i);
			ft_putstr(": ");
			if (size - i > 15)
				ft_print_hex(addr + i, 16);
			else
				ft_print_hex(addr + i, size - i);
		}
		if (value > 31 && value < 127)
			ft_putchar(*(char *)(addr + i));
		else
			ft_putchar('.');
		i++;
		if (i % 16 == 0 || i == size)
			ft_putchar('\n');
	}
	return (addr);
}
