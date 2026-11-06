#ifndef TUNNELS_H
# define TUNNELS_H

#include "struct.h"
# include "libft.h"

int	add_link(t_room *room, t_room *connected_room);
int	create_tunnel(t_lem *lem, char *line);
int	is_tunnel(char *line);

#endif