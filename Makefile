# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 02:48:17 by rkedida           #+#    #+#              #
#    Updated: 2022/06/16 03:06:41 by rkedida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			push_swap
INCLUDES	=	-I./include
LIBFT		=	./libft/libft.a 


SRCS=	push_swap.c \
		rra_rrb_rrr_operations.c \
		clear_error_functions.c \
		sa_sb_ss_operations.c \
		ra_rb_rr_operations.c \
		stack_commands.c \
		pa_pb_operations.c \
		sorting_1.c \
		sorting_2.c \
		sorting_3.c \
		call_sort_algos.c \
		utils.c \
		parsing.c 

OBJS=$(SRCS:.c=.o)

CC = cc
CFLAG = -Wall -Wextra -Werror -g

all: $(NAME)

bonus: all

$(NAME) : $(OBJS)
	@make -C ./libft --silent
	@$(CC) -o $(NAME) $(CFLAG) $(OBJS) $(LIBFT)

%.o : %.c
	@$(CC) $(CFLAG) -c $^ -o $@ 
clean:
	@rm -f $(OBJS)
	@make clean -C ./libft

norm:
	@norminette *.c *.h

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
.PHONY: all clean fclean re