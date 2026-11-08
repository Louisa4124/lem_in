#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include "parsing.h"
#include "utils.h"

int main(int argc, char **argv)
{
    int         fd;
    t_lem	    lem;

    lem.nb_ants = 0;
    lem.rooms = NULL;
    lem.room_count = 0;

    if (argc > 2)
    {
        ft_putendl_fd("Error: Too many arguments", 2);
        return (1);
    }

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd < 0)
        {
            ft_putendl_fd("Error: Could not open file", 2);
            return (1);
        }
        ft_printf("Ant farm : %s\n", argv[1]);
        parse_ant_farm(fd, &lem);
        close(fd);
    }

    // est ce que on fait un truc la ??? jsp.. a mimi d'en decider

    return (0);
}
