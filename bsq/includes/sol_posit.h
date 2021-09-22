#ifndef SOL_POSIT_H
# define SOL_POSIT_H

typedef	struct	s_sol_posit
{
	char	*line;
	int		*prev_line;
	int		*current_line;
	int		current_i;
	int		current_j;
}				t_sol_posit;

#endif