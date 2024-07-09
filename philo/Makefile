NAME = philo
SRCS = philo.c parsing.c print_and_error.c philo_utils.c t_philo.c time.c action.c
OBJS=$(SRCS:.c=.o)
RM=rm -rf
CC= cc
CFLAGS= -Wall -Wextra -Werror -g

CYAN='\033[1;36m'
BLUE='\033[1;34m'
GREEN='\033[6;32m'
WHITE='\033[0;m'

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@clear
	@if [ $$? -eq 0 ]; then \
		echo ${GREEN}">-Compilation successful-<"${WHITE}; \
	fi
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 
clean:
	@clear
	@$(RM) $(OBJS)
	@echo ${BLUE}">------Files clean-------<\n"${WHITE}
fclean: clean
	@$(RM) $(NAME)
	@clear
	@echo ${BLUE}">------Files clean-------<\n"${WHITE}
	@echo ${CYAN}">-------Name clean-------<\n"${WHITE}
re: fclean all
	@clear
	@echo ${BLUE}">------Files clean-------<\n"${WHITE}
	@echo ${CYAN}">-------Name clean-------<\n"${WHITE}
	@echo ${GREEN}">-Compilation successful-<"${WHITE}

.PHONY: all clean fclean re
