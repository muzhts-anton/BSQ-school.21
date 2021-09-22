#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "map.h"
#include "map_checker.h"
#include "sol_posit.h"
#include "base_funs.h"
#include "sol_mem.h"

int		read_next_line(int fd, t_sol_posit *sol_posit, t_map_info *map_info)
{
	int		ret;
	char	c;

	c = ' ';
	ret = read(fd, sol_posit->line, map_info->fl_length);
	sol_posit->line[ret] = '\0';
	ret = read(fd, &c, 1);
	if (c != '\n')
		return (0);
	return (line_check(sol_posit->line, map_info));
}

void	calc_bsq_ln(t_map_info *map_info, t_sol_posit *sol_posit,
		int **result)
{
	int minim;

	sol_posit->current_j = 0;
	while (sol_posit->current_j < map_info->fl_length)
	{
		if (sol_posit->line[sol_posit->current_j] != map_info->obstacle_char)
		{
			if (sol_posit->current_j == 0)
				minim = 0;
			else
				minim = ft_min(sol_posit->prev_line[sol_posit->current_j],
						sol_posit->prev_line[sol_posit->current_j - 1],
						sol_posit->current_line[sol_posit->current_j - 1]);
			sol_posit->current_line[sol_posit->current_j] = minim + 1;
			if (minim + 1 > (*result)[0])
			{
				(*result)[0] = minim + 1;
				(*result)[1] = sol_posit->current_i;
				(*result)[2] = sol_posit->current_j;
			}
		}
		else
			sol_posit->current_line[sol_posit->current_j] = 0;
		sol_posit->current_j++;
	}
}

void	init_prev(t_sol_posit *sol_posit, t_map_info *map_info)
{
	sol_posit->current_j = 0;
	while (sol_posit->current_j < map_info->fl_length)
	{
		sol_posit->prev_line[sol_posit->current_j] =
			sol_posit->current_line[sol_posit->current_j];
		sol_posit->current_j++;
	}
}

int		return_message(int fd, int error, t_sol_posit *sol_posit)
{
	close(fd);
	uninit_fun(sol_posit);
	return (error);
}

int		apply_solution(char *file_name, int legend_length, t_map_info *map_info,
		int **result)
{
	int			fd;
	t_sol_posit	sol_posit;

	sol_posit.current_i = 0;
	init_fun(&sol_posit, map_info);
	fd = open(file_name, O_RDONLY);
	read(fd, sol_posit.line, legend_length + 1);
	while (map_info->line_num > 0)
	{
		if (!read_next_line(fd, &sol_posit, map_info))
			return (return_message(fd, 0, &sol_posit));
		calc_bsq_ln(map_info, &sol_posit, result);
		init_prev(&sol_posit, map_info);
		map_info->line_num--;
		sol_posit.current_i++;
	}
	if (read(fd, sol_posit.line, 1))
		return (return_message(fd, 0, &sol_posit));
	return (return_message(fd, 1, &sol_posit));
}
