/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/19 11:55:22 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/13 15:00:08 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	char *line;
	int ret;
	int count;

	ret = 0;
	count = 0;
	if (argc == 1)
	{
		ft_putstr("usage : ./get_next_line file option\noptions :\n1 : full read\n2 : line 1&2\ncomptage : number of lines\n\0");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_putstr("pb ouverture fichier");
	else
		if (argv[2][0] == '1')
		{
			while ((ret = get_next_line(fd, &line))) //&line = l'adresse du pointeur qui pointe sur une chaine
			{
				printf("ret = %d et line :%s\n", ret, line);
				free(line);
			}
			ret = get_next_line(fd, &line);
			printf("ret = %d\n", ret);
			//free(line);
		}
		else if (argv[2][0] == '2')
		{
			ret = get_next_line(fd, &line);
			printf("ret = %d et line :%s\n", ret, line);
			free(line);
			ret = get_next_line(fd, &line);
			printf("ret = %d et line :%s\n", ret, line);
			free(line);
		}
		else if (ft_strcmp(&argv[2][0],"comptage") == 0)
		{
			while(get_next_line(fd, &line))
			{
				count++;
				free(line);
			}
			printf("nb de lignes = %d", count);
		}

	close(fd);
	return (0);
}
