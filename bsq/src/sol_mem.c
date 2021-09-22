#include "sol_posit.h"
#include "map.h"
#include <stdlib.h>
#include "base_funs.h"

void	uninit_fun(t_sol_posit *sol_posit)
{
	free(sol_posit->line);
	free(sol_posit->prev_line);
	free(sol_posit->current_line);
}

void	init_fun(t_sol_posit *sol_posit, t_map_info *map_info)
{
	int i;

	sol_posit->prev_line = (int*)malloc(sizeof(int) * (map_info->fl_length + 1));
	sol_posit->current_line = (int*)malloc(sizeof(int) * (map_info->fl_length +
				1));
	sol_posit->line = (char*)malloc(sizeof(char) * (ft_max(map_info->fl_length,
					map_info->legend_length) + 2));
	i = 0;
	while (i < map_info->fl_length)
	{
		(sol_posit->current_line)[i] = 0;
		(sol_posit->prev_line)[i++] = 0;
	}
	sol_posit->current_i = 0;
}