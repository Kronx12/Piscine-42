/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rush01.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jelakeha <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/06 23:20:04 by jelakeha     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/07 00:17:24 by jelakeha    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_x(int x, int y, int x1, int y1)
{
	while (x <= x1)
	{
		if (x == 1 && y == 1)
			ft_putchar('/');
		else if (x == 1 && y == y1)
			ft_putchar('\\');
		else if (x == x1 && y == 1)
			ft_putchar('\\');
		else if (x == x1 && y == y1)
			ft_putchar('/');
		else if ((x == 1 || x == x1) || (y == 1 || y == y1))
			ft_putchar('*');
		else
			ft_putchar(' ');
		x++;
	}
}

int		rush(int x, int y)
{
	int x1;
	int y1;

	x1 = x;
	y1 = y;
	y = 1;
	if (x1 <= 0 || y1 <= 0)
		return (0);
	while (y <= y1)
	{
		x = 1;
		ft_x(x, y, x1, y1);
		y++;
		ft_putchar('\n');
	}
	return (0);
}
