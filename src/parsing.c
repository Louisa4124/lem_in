#include "parsing.h"
#include "free.h"
#include "rooms.h"
#include "tunnels.h"
# include "libft.h"

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

static void	remove_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	parse_ant_farm(int fd, t_lem *lem)
{
	char	*line;
	int		ants;
	int		is_start;
	int		is_end;
	t_room	*room;

	ants = -1;
	is_start = 0;
	is_end = 0;
	ft_printf("debut de parsing\n");
	while (get_next_line(fd, &line) == 0 && line != NULL)
	{
		remove_newline(line);
		if (line[0] == '#')
		{
			if (!ft_strncmp(line, "##start", 7))
			{
				ft_printf("start room detected\n");
				is_start = 1;
			}
			else if (!ft_strncmp(line, "##end", 5))
			{
				ft_printf("end room detected\n");
				is_end = 1;
			}
			free(line);
			continue ;
		}
		else if (line[0] != '\0')
		{
			if (ants == -1)
			{
				if (is_valid_number(line))
				{
					ants = ft_atoi(line);
					lem->nb_ants = ants;
					ft_printf("Nb de fourmis : %d\n", lem->nb_ants);
				}
				else
				{
					free(line);
					free_lem(lem);
					return (-1);
				}
			}
			else if (is_tunnel(line))
			{
				ft_printf("tunnel recuperer: %s\n", line);
				if (create_tunnel(lem, line) == -1)
				{
					free(line);
					free_lem(lem);
					return (-1);
				}
			}
			else
			{
				room = create_room(line);
				if (!room)
				{
					free(line);
					free_lem(lem);
					return (-1);
				}
				ft_printf("Created room : %s\n", room->name);
				room->is_start = is_start;
				room->is_end = is_end;
				add_room(lem, room);
				is_start = 0;
				is_end = 0;
				if (room->is_start == 1)
					ft_printf("Start room !\n");
				if (room->is_end == 1)
					ft_printf("End room !\n");
			}
		}
		free(line);
	}
	return (lem->nb_ants);
}
