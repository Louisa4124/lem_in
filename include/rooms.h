#ifndef ROOMS_H
# define ROOMS_H

#include "struct.h"
# include "libft.h"

t_room	*create_room(char *line);
void	    add_room(t_lem *lem, t_room *room);
t_room	*find_room(t_lem *lem, char *name);

#endif