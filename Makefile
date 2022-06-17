# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 02:48:17 by rkedida           #+#    #+#              #
#    Updated: 2022/06/17 03:20:27 by rkedida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			push_swap
BONUS_NAME =	checker
INCLUDES	=	-I./include
LIBFT		=	./libft/libft.a 
CC = cc
CFLAG = -Wall -Wextra -Werror -g


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
		algorithm.c \
		parsing_utils.c \
		parsing_utils_2.c \
		parsing.c \

SRC_CHECKER =	checker_bonus.c \
				rra_rrb_rrr_operations_bonus.c \
				clear_error_functions_bonus.c \
				sa_sb_ss_operations_bonus.c \
				ra_rb_rr_operations_bonus.c \
				stack_commands_bonus.c \
				pa_pb_operations_bonus.c \
				parsing_bonus.c \
				parsing_utils_bonus.c \
				parsing_utils_2_bonus.c
				
OBJS=$(SRCS:.c=.o)
CHECKER_OBJS=$(SRC_CHECKER:.c=.o)


all: $(NAME)

%.o : %.c
	@$(CC) $(CFLAG) -c $< -o $@
	
$(NAME) : $(OBJS)
	@make -C ./libft --silent
	@$(CC) -o $(NAME) $(CFLAG) $(OBJS) $(LIBFT)

$(BONUS_NAME) : $(CHECKER_OBJS)
	@make -C ./libft --silent
	@$(CC) -o $@ $(CFLAG) $(CHECKER_OBJS) $(LIBFT)

bonus: $(BONUS_NAME)

clean:
	@rm -f $(OBJS) $(CHECKER_OBJS)
	@make clean -C ./libft

norm:
	@norminette *.c *.h

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@make fclean -C ./libft

re: fclean all
.PHONY: all clean fclean re