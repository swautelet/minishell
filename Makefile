OBJDIR = object/
SRCDIR = src/
FILES = $(SRCDIR)minishell.c 
OBJECT = $(FILES:$(SRCDIR)%.c=$(OBJDIR)%.o)
HEADER = minishell.h
NAME = minishell
CFLAGS = -Werror -Wall -Wextra

all : $(NAME)

$(NAME) : $(OBJECT) 
	@printf "\033[34;1m&&& linking $@ - $? [$(CFLAGS)]\033[0m\n"
	@$(CC) $(CFLAGS) $(OBJECT) -o $(NAME)

#$(OBJDIR) :
#	mkdir $(OBJDIR)

$(OBJDIR)%.o : $(SRCDIR)%.c
	@printf "\033[32;1m+++ Compiling $< - $@ [$(CFLAGS)]\033[0m\n"
	@mkdir -p $(@D)
	@$(CC) -c $(CFLAGS) $? -o $@

clean :
	@printf "\033[31;1m--- deleting $(OBJDIR)\033[0m\n"
	@rm -rf $(OBJDIR)

fclean : clean
	@printf "\033[31;1m--- deleting $(NAME)\033[0m\n"
	@rm -f $(NAME)

re : fclean all

.phony : all re clean fclean 