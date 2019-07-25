/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/07 07:43:19 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/07 09:45:41 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	s;
	unsigned int	c;
	int				f;

	f = size;
	c = 0;
	while (src[c] != '\0')
		c++;
	s = 0;
	while (dest[s] != '\0')
		s++;
	return (s + c);
}
