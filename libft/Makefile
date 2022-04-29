FILES = ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c
OBJECT = $(FILES:.c=.o)
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
AR = ar 
AS = -rcs

all : $(NAME)

clean :
	rm -f $(OBJECT) $(OBJECTB)

fclean : clean
	rm -f $(NAME)

re : fclean all

%.o : %.c
	@printf "\033[32;1m+++ Compiling $< - $@ [$(CFLAGS)]\033[0m\n"
	@gcc -c $(CFLAGS) $?

$(NAME) : $(NAME)($(OBJECT))

$(NAME)($(OBJECT))  : $(OBJECT)
	@printf "\033[34;1m&&& linking $@ - $% [$(AS)]\033[0m\n"
	@$(AR) $(AS) $(NAME) $%

.PHONY: all clean fclean save bonus re