#include "rooms.h"


t_room	*create_room(char *line)
{
	t_room	*room;
	char	**split;

	split = ft_split(line, ' ');
	if (!split || !split[0] || !split[1] || !split[2])
	{
		free_split(split);
		return (NULL);
	}
	room = malloc(sizeof(t_room));
	if (!room)
	{
		free_split(split);
		return (NULL);
	}
	room->name = ft_strdup(split[0]);
	free_split(split);
	if (!room->name)
	{
		free(room);
		return (NULL);
	}
	room->is_start = 0;
	room->is_end = 0;
	room->visited = 0;
	room->links = NULL;
	room->next = NULL;
	return (room);
}

void	add_room(t_lem *lem, t_room *room)
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

t_room	*find_room(t_lem *lem, char *name)
{
	t_room	*current;

	current = lem->rooms;
	while (current)
	{
		if (!ft_strncmp(current->name, name,
				ft_strlen(current->name) + 1))
			return (current);
		current = current->next;
	}
	return (NULL);
}
