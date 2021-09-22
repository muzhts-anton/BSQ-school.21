#include "utils.h"

int		main(int argc, char **argv)
{
	int			*result;
	t_map_info	map_info;
	int			i;

	result = 0;
	i = 1;
	if (argc > 1)
		while (i < argc)
			check_file(argv[i++], &result, &map_info);
	else
	{
		get_input();
		check_file(g_toolmapfilename, &result, &map_info);
	}
	return (0);
}