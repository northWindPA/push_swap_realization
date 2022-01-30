
// <====> COLORS <====>
NCLR        = \033[0m
BLACK       = \033[0;30m
RED         = \033[0;31m
GREEN       = \033[0;32m
BROWN       = \033[0;33m
BLUE        = \033[0;34m
PURPLE      = \033[0;35m
CYAN        = \033[0;36m
BOLD_GRAY   = \033[0;37m
DARK_GRAY   = \033[1;30m
BOLD_GREEN  = \033[1;31m
BOLD_GREEN  = \033[1;32m
YELLOW      = \033[1;33m
BOLD_BLUE   = \033[1;34m
BOLD_PURPLE = \033[1;35m
BOLD_CYAN   = \033[1;36m
WHITE       = \033[1;37m
// <====> COLORS <====>

NAME = push_swap

NAME_BONUS = checker

LIBFT= 	libft/libft.a

CC = gcc -Wall -Wextra -Werror

SRCS = main.c error_manage.c lists_rotates_reverses.c lists_swaps.c minimum_maximum.c push_rotate.c sortings.c support_utils.c take_find_commands.c take_use_commands.c

SRCS_BONUS = checker_main.c error_manage.c lists_rotates_reverses.c lists_swaps.c minimum_maximum.c push_rotate.c sortings.c support_utils.c take_find_commands.c take_use_commands.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

.c.o:
	@ $(CC) -o $@ -c $^
	@ echo "$(BLUE)[$^ $(BROWN) ⬅ ...is compiled ✅]$(NCLR)"

all: $(NAME)
	@ echo "$(GREEN)[🎉🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰 SUCCESS 🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰 📣] $(NCLR)"

bonus: $(NAME_BONUS)
	@ echo "$(GREEN)[🎉🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰 SUCCESS 🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰🀰 📣] $(NCLR)"

$(NAME): $(OBJS)
	@ rm -rf $(NAME)
	@ $(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	@ rm -rf $(NAME_BONUS)
	@ $(CC) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean:
	@ rm -f $(OBJS)
	@ rm -f $(OBJS_BONUS)
	@ echo "$(BROWN)[🔄 Objects: $(PURPLE)$(OBJS)$(BROWN) have been removed 🗑 ]$(NCLR)"
	@ echo "$(BROWN)[🔄 Objects: $(PURPLE)$(OBJS_BONUS)$(BROWN) have been removed 🗑 ]$(NCLR)"

fclean: clean
	@ rm -f $(NAME)
	@ rm -f $(NAME_BONUS)
	@ echo "$(BROWN)[🚮 Binary: $(PURPLE)$(NAME)$(BROWN) has been removed 🗑 ]$(NCLR)"
	@ echo "$(BROWN)[🚮 Binary: $(PURPLE)$(NAME_BONUS)$(BROWN) has been removed 🗑 ]$(NCLR)"

re: fclean all

.PHONY: all clean fclean re