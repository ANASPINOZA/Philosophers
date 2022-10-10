# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 11:54:10 by aadnane           #+#    #+#              #
#    Updated: 2022/10/10 16:21:41 by aadnane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra
SRCS = parsing.c philo.c utils.c philos_utils.c time_utils.c #mandatory files

SRCB = #bonus files

OBJS = $(SRCS:.c=.o)
OBJB = $(SRCB:.c=.o)
NAME = philo
BONUS = philo_bonus
HEADER = philosophers.h

all : $(NAME)

$(BONUS) : $(OBJB)
	$(CC) $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $^ -o $@

%.o  : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS) $(OBJB)

fclean : clean
	rm -rf $(NAME) $(BONUS)

deyoo :all clean
	clear

b:
	make bonus && make clean && clear
bonus : $(BONUS)

re : fclean all