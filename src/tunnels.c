#include "tunnels.h"
#include "free.h"
#include "rooms.h"

int	add_link(t_room *room, t_room *connected_room)
{
	t_link	*link;
	t_link	*current;

	link = malloc(sizeof(t_link));
	if (!link)
		return (-1);
	link->room = connected_room;
	link->next = NULL;
	if (!room->links)
		room->links = link;
	else
	{
		current = room->links;
		while (current->next)
			current = current->next;
		current->next = link;
	}
	return (0);
}

int	create_tunnel(t_lem *lem, char *line)
{
	char	**split;
	t_room	*room1;
	t_room	*room2;

	split = ft_split(line, '-');
	if (!split || !split[0] || !split[1] || split[2])
	{
		free_split(split);
		return (-1);
	}
	room1 = find_room(lem, split[0]);
	room2 = find_room(lem, split[1]);
	free_split(split);
	if (!room1 || !room2)
		return (-1);
	if (add_link(room1, room2) == -1)
		return (-1);
	if (add_link(room2, room1) == -1)
		return (-1);
	return (0);
}

int	is_tunnel(char *line)
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