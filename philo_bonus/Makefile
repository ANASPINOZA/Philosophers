# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaspinoza <anaspinoza@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 11:54:10 by aadnane           #+#    #+#              #
#    Updated: 2022/11/20 13:15:36 by anaspinoza       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror 
SRCS = parsing.c philo.c utils.c philos_utils.c time_utils.c \
 aux_philos_utils.c#mandatory files

SRCB = #bonus files

OBJS = $(SRCS:.c=.o)
OBJB = $(SRCB:.c=.o)
NAME = philo
BONUS = philo_bonus
HEADER = philosophers.h

all : $(NAME)

$(BONUS) : $(OBJB)
	$(CC)  $^ -o $@

$(NAME) : $(OBJS)
	$(CC) -lpthread $^ -o $@

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