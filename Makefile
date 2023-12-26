NAME = libft.a

HEADER = libft.h

FUN = ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strlcpy.c ft_strrchr.c ft_bzero.c ft_itoa.c ft_putendl_fd.c \
ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_tolower.c ft_split.c ft_strmapi.c ft_striteri.c ft_putnbr_fd.c \
ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strdup.c ft_strncmp.c ft_toupper.c ft_strtrim.c ft_putchar_fd.c \
ft_isalnum.c ft_isprint.c ft_memmove.c ft_strlcat.c ft_strnstr.c ft_substr.c ft_strjoin.c ft_putstr_fd.c \
ft_putstr.c ft_putchar.c ft_putnbr.c ft_putunbr.c ft_puthexa.c ft_putaddress.c ft_printf.c \
str_join.c get_next_line.c get_next_line_fd.c

FBONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
REMOVE = rm -f
COMPILER = cc
SOBJECT = $(FUN:.c=.o)
BOBJECT = $(FBONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror

%.o: %.c $(HEADER)
	$(COMPILER) $(FLAGS) -c $<

all: $(NAME) bonus

$(NAME): $(SOBJECT)  
	ar -rc $(NAME) $(SOBJECT) 

bonus: $(BOBJECT)
	ar -rc $(NAME) $(BOBJECT)

clean:
	$(REMOVE) $(SOBJECT) $(BOBJECT)

fclean: clean
	$(REMOVE) $(NAME)

re:  fclean all
