#include "base_funs.h"
#include <stdlib.h>
#include "map.h"

int		legend_check(char *legend, int length)
{
	int		i;
	int 	min;
	int 	max;

	min = 4;
	max = 12;
	if (length < min || length > max)
		return (0);
	i = length - min;
	while (i >= 0)
	{
		if (legend[i] < '0' || legend[i] > '9')
			return (0);
		i--;
	}
	if (legend[length - 1] == legend[length - 2]
			|| legend[length - 1] == legend[length - 3]
			|| legend[length - 2] == legend[length - 3])
		return (0);
	return (1);
}

int		line_check(char *line, t_map_info *map_info)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != map_info->obstacle_char && line[i] != map_info->empty_char)
			return (0);
		i++;
	}
	if (i != map_info->fl_length)
		return (0);
	return (1);
}
