/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mnataf <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 20:44:26 by mnataf       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/21 22:44:05 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"
#include "ft_struct.h"
#include "lib.h"

#define BUF_SIZE 4096

int		main(int argc, char **argv)
{
	char			*file;
	char			*content;
	struct s_value	*tab;
	char			*str;

	if (argc == 1)
		return (0);
	str = malloc(sizeof(char) * 10000);
	file = malloc(sizeof(char) * 100);
	content = malloc(sizeof(char) * BUF_SIZE);
	file = "numbers.dict";
	if (argc == 3)
		file = argv[2];
	content = get_dict(file);
	tab = transform_dict_tab_to_struct(content);
	ft_aff_struct(tab, argv[1], str);
}
