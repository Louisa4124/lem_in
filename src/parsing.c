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

static t_room	*create_room(char *line)
{
	t_room	*room;
	char	**split;

	split = ft_split(line, ' ');
	if (!split || !split[0] || !split[1] || !split[2])
		return (NULL);
	room = malloc(sizeof(t_room));
	if (!room)
		return (NULL);
	room->name = ft_strdup(split[0]);
	room->is_start = 0;
	room->is_end = 0;
	room->visited = 0;
	room->next = NULL;
	free(split);
	return (room);
}

static void	add_room(t_lem *lem, t_room *room)
{
	t_room	*current;

	if (!lem->rooms)
		lem->rooms = room;
	else
	{
		current = lem->rooms;
		while (current->next)
			current = current->next;
		current->next = room;
	}
	lem->room_count++;
}

static int	is_tunnel(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '-')
			return (1);
		i++;
	}
	return (0);
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
    write(1, "debut de parsing\n", 18);
	while (get_next_line(fd, &line) == 0 && line != NULL)
	{
		if (line[0] == '#')
		{
			if (!ft_strncmp(line, "##start", 7))
				is_start = 1;
			else if (!ft_strncmp(line, "##end", 5))
				is_end = 1;
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
					return (-1);
				}
			}
            else if (is_tunnel(line))
            {
                // TODO: les tunnels
            }
			else
			{
				room = create_room(line);
                ft_printf("Created room : %s\n", room->name);
                // ft_printf("Is start room : %d\n", room->is_start);
                // ft_printf("Is end room : %d\n", room->is_end);
				if (!room)
				{
					free(line);
					return (-1);
				}
				room->is_start = is_start;
				room->is_end = is_end;
				add_room(lem, room);
				is_start = 0;
				is_end = 0;
			}
		}
		free(line);
	}
	return (lem->nb_ants);
}