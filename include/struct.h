#ifndef STRUCT
# define STRUCT

# include "libft.h"

// Lien entre les salles
typedef struct s_link
{
    struct s_room   *room;
    struct s_link   *next;
}                   t_link;

// Salles
typedef struct s_room
{
    char            *name;
    int             is_start; // 1 si c'est la room start
    int             is_end;   // 1 si c'est la room end
    int             visited;
    t_link          *links; // toutes les rooms connectees a ma room
    struct s_room   *next; // prochaine room 
}                   t_room;

// structure principale
typedef struct s_lem
{
    int             nb_ants; // nombre de fourmis
    t_room          *rooms;
    int             room_count; // nombre total de salle
}                   t_lem;

#endif
