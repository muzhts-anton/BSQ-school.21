#ifndef UTILS_H
# define UTILS_H

#include "map.h"

extern char g_toolmapfilename[];

void	check_file(char *file_name, int **result, t_map_info *map_info);
void	get_input(void);

#endif