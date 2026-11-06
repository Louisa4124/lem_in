#include "parsing.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_ant_count(int fd)
{
	char	*line;
	int		ants;

	ants = -1;
	while (get_next_line(fd, &line) != 1)
	{
        if (line[0] == '#')
		{
            // TODO : gerer ##start et ##end ici
			free(line);
			continue ;
		}
		else if (line[0] != '\0')
		{
            write(1, "debut de parsing\n", 18);
			if (is_valid_number(line))
			{
				ants = ft_atoi(line);
                ft_printf("Nb de fourmis : %d\n", ants);
				free(line);
				break ;
			}
			else
			{
				free(line);
				return (-1);
			}
		}
		free(line);
	}
	return (ants);
}