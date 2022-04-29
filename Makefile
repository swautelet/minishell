OBJDIR = object/
SRCDIR = src/
FILES = $(SRCDIR)minishell.c \
	$(SRCDIR)string/find_next_element.c \
	$(SRCDIR)parsing/parse_it.c \
	$(SRCDIR)string/cut_string.c \
	$(SRCDIR)heredoc/creat_heredoc.c
OBJECT = $(FILES:$(SRCDIR)%.c=$(OBJDIR)%.o)
HEADER = minishell.h
NAME = minishell
CFLAGS = -Werror -Wall -Wextra -Iinclude
LIB = $(LIBDIR)libft.a
LIBDIR = libft/
all : $(NAME)

$(NAME) : $(OBJECT) $(LIB)
	@printf "\033[34;1m&&& linking $@ - $? [$(CFLAGS)]\033[0m\n"
	@$(CC) $(CFLAGS) -lreadline $(OBJECT) $(LIB) -o $(NAME)

#$(OBJDIR) :
#	mkdir $(OBJDIR)
$(LIB) :
	$(MAKE) -C $(LIBDIR) $(MAKECMDGOALS)

$(OBJDIR)%.o : $(SRCDIR)%.c
	@printf "\033[32;1m+++ Compiling $< - $@ [$(CFLAGS)]\033[0m\n"
	@mkdir -p $(@D)
	@$(CC) -c $(CFLAGS) $? -o $@

test : all
	@printf "\033[36;1m@@@ launching minishell ...\033[0m\n"
	@./minishell

clean :
	@printf "\033[31;1m--- deleting $(OBJDIR)\033[0m\n"
	@rm -rf $(OBJDIR)

fclean : clean
	@printf "\033[31;1m--- deleting $(NAME)\033[0m\n"
	@rm -f $(NAME)

re : fclean all

save :
	@printf "\033[36;1m@@@ auto saving minishell ...\033[0m\n"
	@git commit -am autosave
	@git push

.phony : all re clean fclean 