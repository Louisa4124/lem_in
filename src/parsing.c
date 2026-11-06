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

int	parse_ant_farm(int fd, t_lem *lem)
{
	char	*line;
	int		ants;

	ants = -1;
    write(1, "debut de parsing\n", 18);
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
            if (is_valid_number(line))
			{
				ants = ft_atoi(line);
                lem->nb_ants = ants;
                ft_printf("Nb de fourmis : %d\n", lem->nb_ants);
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
	return (lem->nb_ants);
}