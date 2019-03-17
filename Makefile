#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 01:16:47 by dgallagh          #+#    #+#              #
#    Updated: 2019/03/09 15:02:09 by dgallagh         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
.PHONY: all clean fclean re

$(NAME): *.c
	gcc $(FLAGS) -c $^
	ar rcs $@ *.o

clean:
	rm -f *.o \#*\# *~

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all