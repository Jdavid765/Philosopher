CC = gcc
NAME = philo
SRC = src/philo.c\
	src/free.c\
	src/parsing.c\
	src/routine.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

# --------------------------------------------------------
#        BARRE DE PROGRESSION (ROSE) POUR COMPILATION
# --------------------------------------------------------

NB := $(words $(SRC))
BARLEN = 30
CNT = 0

%.o: %.c
	$(eval CNT=$(shell echo $$(($(CNT)+1))))
	$(eval PROG=$(shell echo $$(($(CNT) * 100 / $(NB)))))
	$(eval FILLED=$(shell echo $$(($(PROG) * $(BARLEN) / 100))))
	$(eval EMPTY=$(shell echo $$(($(BARLEN) - $(FILLED)))))
	@printf "\r\033[35m[%s%s] %3s%%\033[0m  \033[90m(%s)\033[0m" \
		"$$(printf '#%.0s' $$(seq 1 $(FILLED)))" \
		"$$(printf '.%.0s' $$(seq 1 $(EMPTY)))" \
		"$(PROG)" "$<"
	@$(CC) $(CFLAGS) -c $< -o $@

# --------------------------------------------------------

all : $(NAME)


$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re