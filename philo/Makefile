# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msosnova <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 18:34:01 by msosnova          #+#    #+#              #
#    Updated: 2021/12/28 18:34:06 by msosnova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

OBJ =   srcs/utils.o\
		srcs/ft_init_data.o\
		srcs/ft_destroy_mutex.o\
		srcs/ft_start_thread.o\
		srcs/time_utils.o\
		srcs/finish.o\
		srcs/ft_life_philo.o\
		srcs/ft_timer_death.o\
		srcs/message.o\
		
      

INC = -Iinclude
FLAGS = -g -Wall -Wextra -Werror
CC        =     gcc

PHILO = -pthread  
 %.o: %.c
		@echo "\033[93m>> so_long obj $@\033[0m"
		$(CC) $(FLAGS) $(INC) -o $@ -c $<
 
all: $(NAME)

$(NAME): $(OBJ)
		echo "$(OBJ)"
		@echo "\033[93m>> philosophers compilation\033[0m"
		$(CC) $(FLAGS) $(INC) $(OBJ) main.c -o $(NAME) $(PHILO) 

clean:
		@echo "\033[93m>> Cleaning objects (.obj)\033[0m"
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:
		make fclean
		make all
 
bonus: $(NAME)

.PHONY: all, clean, fclean, re, bonus
                                                      
