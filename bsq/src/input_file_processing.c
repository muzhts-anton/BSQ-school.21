#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "map_checker.h"
#include "solution.h"
#include "map.h"
#include "base_funs.h"

int		map_length(char *file_name, int *legend_length, int *fl_length)
{
	int		fd;
	int		line_count;
	char	c;

	*legend_length = 0;
	*fl_length = 0;
	line_count = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, &c, 1) && line_count < 2)
	{
		if (c == '\n')
			line_count++;
		else
		{
			if (line_count == 0)
				*legend_length += 1;
			else
				*fl_length += 1;
		}
	}
	close(fd);
	if (line_count == 0)
		return (0);
	return (1);
}

char	*read_legend(char *file_name, int length)
{
	int		fd;
	char	*legend;

	fd = open(file_name, O_RDONLY);
	legend = (char*)malloc(sizeof(char) * (length + 1));
	read(fd, legend, length);
	legend[length] = '\0';
	close(fd);
	return (legend);
}

int		start_bsq(t_map_info *map_info, int **result, char *file_name,
		int legend_length)
{
	int		res;

	*result = (int*)malloc(sizeof(int) * 3);
	(*result)[0] = 0;
	(*result)[1] = 0;
	(*result)[2] = 0;
	res = apply_solution(file_name, legend_length, map_info, result);
	return (res);
}

void	update_legend(int legend_length, char *legend, t_map_info *map_info)
{
	char	*no;

	map_info->full_char = legend[legend_length - 1];
	map_info->obstacle_char = legend[legend_length - 2];
	map_info->empty_char = legend[legend_length - 3];
	no = (char*)malloc(sizeof(char) * (legend_length - 2));
	no = ft_strncpy(no, legend, legend_length - 3);
	no[legend_length - 3] = '\0';
	map_info->line_num = ft_atoi(no);
	free(no);
}

int		calc_file(char *file_name, int **result, t_map_info *map_info)
{
	int		legend_length;
	int		fl_length;
	char	*legend;

	if (!map_length(file_name, &legend_length, &fl_length))
		return (-1);
	map_info->fl_length = fl_length;
	map_info->legend_length = legend_length;
	legend = read_legend(file_name, legend_length);
	if (!legend_check(legend, legend_length))
		return (-1);
	update_legend(legend_length, legend, map_info);
	if (!start_bsq(map_info, result, file_name, legend_length))
		return (-1);
	return (0);
}
