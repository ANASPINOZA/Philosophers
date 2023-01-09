# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 11:54:10 by aadnane           #+#    #+#              #
#    Updated: 2023/01/06 22:47:41 by aadnane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror 
SRCS = parsing.c philo.c utils.c philos_utils.c time_utils.c \
 aux_philos_utils.c#mandatory files

OBJS = $(SRCS:.c=.o)
NAME = philo
HEADER = philosophers.h

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -lpthread $^ -o $@

%.o  : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

deyoo :all clean
	clear

re : fclean all