# Project compilation files and directories

NAME			= 	server

C_CLIENT		=	client.c \
					libft.c \

C_SERVER		=	server.c \
					libft.c \

SRCSFD			=	srcs/
OBJSFD			=	objs/
HDR_INC			=	-I./includes

OBJS_CLIENT 	=	$(addprefix $(OBJSFD), $(C_CLIENT:.c=.o))
OBJS_SERVER 	=	$(addprefix $(OBJSFD), $(C_SERVER:.c=.o))
# # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Compilation
COMP	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
# # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Colors
RED 			= \033[0;31m
GREEN 			= \033[0;32m
NONE 			= \033[0m
# # # # # # # # # # # # # # # # # # # # # # # # # # # # #

all: project $(NAME)
	@echo "... project ready"

project:
	@echo "Checking project ..."

projectb:
	@echo "Checking project bonus ..."

$(OBJSFD):
	@mkdir $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(OBJSFD)%.o: $(SRCSFD)%.c
	@$(COMP) $(CFLAGS) $(HDR_INC) -c $< -o $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ object"

$(NAME): $(OBJSFD) $(OBJS_SERVER) $(OBJS_CLIENT)
	@$(COMP) $(CFLAGS) $(OBJS_SERVER) -o server
	@echo "\t[ $(GREEN)✔$(NONE) ] server executable"
	@$(COMP) $(CFLAGS) $(OBJS_CLIENT) -o client
	@echo "\t[ $(GREEN)✔$(NONE) ] client executable"

bonus: projectb $(NAME)
	@echo "... bonus project ready"

clean:
	@echo "Cleaning project ..."
	@/bin/rm -rf $(OBJSFD)
	@echo "\t[ $(RED)✗$(NONE) ] Objects directory"

fclean: clean
	@/bin/rm -f server
	@echo "\t[ $(RED)✗$(NONE) ] server executable"
	@/bin/rm -f client
	@echo "\t[ $(RED)✗$(NONE) ] client executable"

re: fclean all

.PHONY: project all clean fclean re
