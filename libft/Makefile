SRC	= garb.c	garb_utils.c	ft_putnbr_fd.c	ft_putendl_fd.c	ft_putstr_fd.c	ft_putchar_fd.c	ft_striteri.c	ft_atoi.c	ft_isascii.c	ft_memcmp.c	ft_strchr.c	ft_strlen.c	ft_strtrim.c	ft_bzero.c	ft_isdigit.c	ft_memcpy.c	ft_strdup.c	ft_strmapi.c	ft_substr.c	ft_isprint.c	ft_memmove.c	ft_strjoin.c	ft_strncmp.c	ft_tolower.c	ft_isalnum.c	ft_itoa.c	ft_memset.c	ft_strlcat.c	ft_strnstr.c	ft_toupper.c	ft_isalpha.c	ft_memchr.c	ft_split.c	ft_strlcpy.c	ft_strrchr.c	ft_arrjoin.c
bonus_SRC = ft_lstnew_bonus.c	ft_lstadd_front_bonus.c	ft_lstsize_bonus.c	ft_lstlast_bonus.c	ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c	ft_lstclear_bonus.c	ft_lstiter_bonus.c	ft_lstmap_bonus.c
OBJS:=	$(SRC:%.c=%.o)
bonus_OBJ = $(bonus_SRC:%.c=%.o)
FLAGS	=	-Wall	-Werror	-Wextra
all_obj:= $(bonus_OBJ) $(OBJS) 
NAME = libft.a

all: $(NAME)

$(NAME):	$(OBJS)
	@ar	rcs	$(NAME)	$(OBJS)

bonus: $(all_obj)
	@ar rcs $(NAME) $(all_obj)

%.o:	%.c
	@cc	$(FLAGS)	-o	$@	-c	$<
	
clean:
	rm	-f	$(all_obj)

fclean:	clean
	rm	-f	$(NAME)

re:	fclean	$(NAME)

.PHONY: all fclean clean bonus re
