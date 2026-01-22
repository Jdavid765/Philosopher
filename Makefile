CC = gcc
NAME = philo
DIRPRINTF = ft_printf
PRINTF = $(DIRPRINTF)/libftprintf.a
SRC = philo.c
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

all : $(PRINTF) $(NAME)

$(PRINTF) :
	$(MAKE) -C $(DIRPRINTF) --no-print-directory > /dev/null

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(PRINTF) $(CFLAGS) -o $(NAME)

clean :
	$(RM) $(OBJ)
	$(MAKE) -C $(DIRPRINTF) clean --no-print-directory > /dev/null

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(DIRPRINTF) fclean --no-print-directory > /dev/null

re : fclean all

.PHONY : all clean fclean re