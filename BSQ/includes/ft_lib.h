/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lib.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 05:12:25 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 15:52:44 by jedelfos    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUF_SIZE	20000
# define ERROR()	write(2, "map error\n", 10)

typedef struct	s_point
{
	char				*grid;
	char				void_value;
	char				wall_value;
	char				square_value;
	char				first_line;
	int					*last_grid_result;
	int					*grid_result;
	int					result_value;
	char				*result_pose;
	unsigned long		height;
	unsigned long		width;
	unsigned long		check_height;
	unsigned long long	i;
	unsigned long long	u;
	int					j;
}				t_point;

char			*ft_resolve(char *grid);
int				read_top(int fd);
unsigned long	get_h(char *grid);
unsigned long	get_w(char *grid);
t_point			char_value_calculation(char *grid, t_point var);
char			chek_first_line(char *grid);
t_point			var_init(char *grid, t_point var);
t_point			ft_resolve_2(t_point var);
t_point			ft_resolve_3(t_point var);
t_point			ft_resolve_4(t_point var);
t_point			ft_write_grid(t_point var);
void			ft_putmap(char *str);
int				main(int ac, char **av);

#endif
