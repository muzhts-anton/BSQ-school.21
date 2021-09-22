#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "input_file_processing.h"
#include "show_result.h"


void	get_input(void)
{
	int		ret;
	char	*buf;
	int		fd;

	fd = open("./std_input.txt", O_RDWR | O_CREAT, 0644);
	buf = (char*)malloc(51 * sizeof(char));
	while ((ret = read(0, buf, 50)))
		write(fd, buf, ret);
	close(fd);
	free(buf);
}

int		file_exists_check(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

void	check_file(char *file_name, int **result, t_map_info *map_info)
{
	if (file_exists_check(file_name))
	{
		if (calc_file(file_name, result, map_info) == -1)
			write(2, "map error\n", 10);
		else if ((*result)[0] == 0)
			write(2, "map error\n", 10);
		else
			show_result(file_name, *result, map_info);
		if (*result != 0)
		{
			free(*result);
			*result = 0;
		}
	}
	else
		write(2, "map error\n", 10);
}

int		main(int argc, char **argv)
{
	int			*result;
	t_map_info	map_info;
	int			i;

	result = 0;
	i = 1;
	if (argc > 1)
		while (i < argc)
		{
			check_file(argv[i], &result, &map_info);
			i++;
		}
	else
	{
		get_input();
		check_file("./std_input.txt", &result, &map_info);
	}
	return (0);
}