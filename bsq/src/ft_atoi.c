static int		ignored_space(char s)
{
	if (s == ' ' || s == '\n' || s == '\t')
		return (1);
	if (s == '\r' || s == '\v' || s == '\f')
		return (1);
	return (0);
}

static int		ft_generate_number(char *str)
{
	int nr;
	int i;

	nr = 0;
	i = 0;
	while (i <= 19 && str[i] >= '0' && str[i] <= '9')
	{
		nr = nr * 10 + str[i] - '0';
		i++;
	}
	if (i == 20)
		return (-1);
	else
		return (nr);
}

int		ft_atoi(char *str)
{
	int i;
	int nbr;
	int sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (ignored_space(str[i]))
		++i;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		i++;
	nbr = ft_generate_number(str + i);
	if (nbr == -1)
		return (nbr);
	return (nbr * sign);
}
