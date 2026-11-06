#include "free.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_rooms(t_room *rooms)
{
	t_room	*next_room;
	t_link	*link;
	t_link	*next_link;

	while (rooms)
	{
		next_room = rooms->next;
		link = rooms->links;
		while (link)
		{
			next_link = link->next;
			free(link);
			link = next_link;
		}
		free(rooms->name);
		free(rooms);
		rooms = next_room;
	}
}

void	free_lem(t_lem *lem)
{
	if (!lem)
		return ;
	free_rooms(lem->rooms);
	lem->rooms = NULL;
	lem->room_count = 0;
	lem->nb_ants = 0;
}
