# lem_in
#

#===# project
NAME	= lem_in

#===# file location
INC_D	= include

SRC_D	= src
SRC		= $(wildcard $(SRC_D)/*.c)

OBJ_D	= .obj
OBJ		= $(SRC:$(SRC_D)/%.c=$(OBJ_D)/%.o)

#===# local lib
LLIB_P	=
LLIB_D	= libft
LLIB	= $(addprefix $(LLIB_P), $(LLIB_D))
LLIB_A	= $(addprefix $(LLIB_P), $(foreach lib, $(LLIB_D), $(addsuffix /$(lib).a, $(lib))))

INC_D += $(LLIB)

# lib rules
LLIB_fclean= $(addprefix rule-llib-fc-, $(LLIB))

#===# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra#-Werror
IFLAGS	= $(addprefix -I, $(INC_D))
LFLAGS	= $(addprefix -L, $(LLIB)) $(addprefix -l, $(patsubst lib%, %, $(notdir $(LLIB))))

#
#===#
#===#===#
#===#===#===# Rules
#===#===#
#===#
#

.PHONY: all clean fclean re

#? Build the project
all: $(NAME)

#? re build with a clean state
re: fclean all

#? clean build artifact but keep binary
clean:
	rm -rf $(OBJ_D)

#? full clean
fclean: clean
	rm -f $(NAME)

#? clean lib
prune: fclean $(LLIB_fclean)

#
#===#
#===#===#
#===#===#===# Internals
#===#===#
#===#
#

#===# compilation
$(NAME): $(LLIB_A) $(OBJ)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

$(OBJ_D)/%.o: $(SRC_D)/%.c | $(OBJ_D)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@


#==# lib
lib%:
	make -sC $(dir $@)

rule-llib-fc-%:
	make -sC $* fclean

#==# dirs
$(OBJ_D):
	@mkdir -p $(OBJ_D)
