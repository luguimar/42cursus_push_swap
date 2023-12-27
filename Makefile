# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 16:42:05 by luguimar          #+#    #+#              #
#    Updated: 2023/12/25 13:27:33 by luguimar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

SRC = main.c operations.c exec_operations.c sort.c struct_fields.c lst_utils.c struct_fields_utils.c calculators.c struct_fields_extra.c sort_extra.c exec_operations_extra.c exec_operations_extra1.c

BONUS_SRC = main_bonus.c exec_operations_bonus.c operations_bonus.c struct_fields_bonus.c struct_fields_extra_bonus.c struct_fields_utils_bonus.c lst_utils_bonus.c sort_bonus.c sort_extra_bonus.c exec_operations_extra_bonus.c exec_operations_extra1_bonus.c calculators_bonus.c read_utils_bonus.c

OBJS = ${SRC:.c=.o}

BONUS_OBJS = ${BONUS_SRC:.c=.o}

CC = cc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .
MAKE = make -C
LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${LIBFT}
		${CC} ${OBJS} ${LIBFT} -o ${NAME}

$(LIBFT):
		${MAKE} ${LIBFT_PATH}

all: ${NAME}

bonus: ${BONUS_OBJS} ${LIBFT}
		${CC} ${BONUS_OBJS} ${LIBFT} -o ${BONUS}

clean:
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} ${NAME} ${BONUS}

re: fclean all

.PHONY: all clean fclean re
