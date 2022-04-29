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
			ft_toupper.c
OBJECT = $(FILES:.c=.o)
NAME = libft.a
BONUS = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c
OBJECTB = $(BONUS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all : $(OBJECT) $(NAME)($(OBJECT))

clean :
	rm -f $(OBJECT) $(OBJECTB)

fclean : clean
	rm -f $(NAME)

re : fclean all

save : fclean
	git add $(FILES) $(BONUS) libft.h Makefile
	git commit -m autosave
	git push git@vogsphere-v2.s19.be:vogsphere/intra-uuid-9255c91c-fe38-4871-93e0-cc59b0b7a5a0-3851762

bonus : all $(OBJECTB) $(NAME)($(OBJECTB))

%.o : %.c
	gcc -c $(CFLAGS) $?

$(NAME)($(OBJECT)) :
	$(AR) $(NAME) $%

$(NAME)($(OBJECTB)) : 
	$(AR) $(NAME) $%

.PHONY: all clean fclean save bonus re