# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 17:19:19 by glacroix          #+#    #+#              #
#    Updated: 2023/07/13 19:16:48 by glacroix         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors
# **************************************************************************** #
RESET  		= "\x1B[0m"
RED  		= "\x1B[31m"
GREEN  		= "\x1B[32m"
YELLOW  	= "\x1B[33m"
BLUE 		= "\x1B[34m"
MAGENTA 	= "\x1B[35m"
CAYN  		= "\x1B[36m"
WHITE  		= "\x1B[37m"

#Program name
# **************************************************************************** #
NAME		= fractol

#SRC & OBJS Details
# **************************************************************************** #
SRCS		= srcs/main.c\
			srcs/keyhooks.c\
			srcs/selection.c\
			srcs/fractal.c\
			srcs/init.c\
			srcs/legend.c\

OBJS		= $(SRCS:%.c=objs/%.o)

#Execution
# **************************************************************************** #
LIBFT		= libft/libft.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -Imlx
CFLAGS		+= -I include
CFLAGS		+= -I libft -g3 -O2 -DSTRINGPUTX11
MINI		= -L./mlx -lmlx -framework OpenGL -framework AppKit -g3 #-fsanitize=address
DEGUB		= 

#SRC Execution
# **************************************************************************** #
${NAME}: objs ${OBJS}
	@echo $(YELLOW) "\n .........Compiling lib.........\n" $(RESET)
	@make -sC libft
	@$(CC) $(OBJS) $(LIBFT) $(MINI) -o $(NAME)
	@echo $(GREEN) "\n         Fractol Compiled!       \n" $(RESET)

#Makefile Cmds
# **************************************************************************** #
objs:
	@mkdir -p objs/srcs

objs/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

clean:
	@make clean -sC libft
	@rm -rf objs

fclean: clean
	@make fclean -sC libft
	@rm -f $(NAME)
	@echo $(RED) "\n >>>>>>>> Deleted all *.o and *.a! <<<<<<<< \n" $(RESET)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus bonus