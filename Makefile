# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 13:16:39 by karisti-          #+#    #+#              #
#    Updated: 2021/09/05 13:25:23 by karisti-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	push_swap
LIBFT_A 	=	libft.a

COMPILE 	=	gcc -Wall -Werror -Wextra $(PUSH_SWAP_H) $(LIBFT_H) -c -o 

PUSH_SWAP_H =	-I includes/
LIBFT_H 	= 	-I srcs/libft/includes

OBJ_DIR 	=	obj/
SRC_DIR 	=	srcs/
LIB_DIR 	=	srcs/libft/

CFILE		=	push_swap.c \
				checks.c \
				parser.c \
				op_swap.c \
				op_push.c \
				op_rotate.c \
				op_reverse_rotate.c \
				sort.c \
				helpers_stacks.c \
				helpers_sort.c

CFIND 		=	$(CFILE:%=$(SRC_DIR)%)

OFILE 		=	$(CFILE:%.c=%.o)

OBJ 		=	$(addprefix $(OBJ_DIR), $(OFILE))

all: $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: push_swap Object directory

$(NAME): $(OBJ_DIR) $(OBJ)
		@echo LIBFT START
		@make bonus -C $(LIB_DIR)
		@echo Copying $(LIBFT_A) to root.
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)
		@echo Merged: $(NAME) with $(LIBFT_A)
		@echo PUSH_SWAP COMPLETE

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo Create: $(@:obj/%=%)
		@$(COMPILE) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean
		@echo Cleaned ft_printf object files

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean
		@echo Cleaned $(NAME)

re: fclean all

# FOR TESTNGS
retest: cleantest
	gcc -g -Wall -Werror -Wextra srcs/*.c srcs/libft/srcs/*.c srcs/libft/srcs/bonus/*.c -I includes/ -I srcs/libft/includes -o test && ./test 2 3 5 12 10 6 9 7 4 1 8 11

cleantest:
	@/bin/rm -rf test test.dSYM

.PHONY: all clean flcean re
