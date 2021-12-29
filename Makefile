# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 12:54:01 by sgmira            #+#    #+#              #
#    Updated: 2021/12/08 20:39:29 by sgmira           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CC_FLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

SRCS =  ft_printf.c \
		ft_printf_utils.c \
		ft_printf_utils2.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS) 	

fclean: clean
	$(RM) $(NAME)

re: fclean all