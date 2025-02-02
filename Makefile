SRC= main.c push_swap_utiles2.c  push_swap_utiles5.c push_swap_utiles3.c push_swap_utiles4.c push_swap_utiles.c quick_sort.c push_swap_utiles6.c push_swap_utiles7.c
OBJ= $(SRC:.c=.o)
SRCB= ./checker_bonus/checker_bonus.c ./checker_bonus/get_next_line.c ./checker_bonus/get_next_line_utils.c  ./checker_bonus/utiles.c ./checker_bonus/utiles2.c ./checker_bonus/utiles3.c push_swap_utiles2.c push_swap_utiles.c ./checker_bonus/utiles4.c
OBJB= $(SRCB:.c=.o)
LDIR= ./libft
libft= $(LDIR)/libft.a
BONUS= checker
CHDIR= ./checker_bonus
NAME= push_swap
CC= cc
CFLAGS= -Wall -Wextra -Werror -ggdb3
RM= rm -f

all: make_libs $(NAME)

make_libs	:
	@$(MAKE) -C $(LDIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(libft)

bonus: make_libs $(OBJB)
	@$(CC) $(CFLAGS) -o $(BONUS) $(OBJB) $(libft)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJB)
	$(MAKE) -C $(LDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LDIR) fclean
	$(RM) $(BONUS)

re: fclean all

