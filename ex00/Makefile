# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuzmin <vkuzmin@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 02:59:54 by vkuzmin           #+#    #+#              #
#    Updated: 2023/10/27 07:53:42 by vkuzmin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++
CFLAGS = -Wall -Wextra -Werror --std=c++11 -fsanitize=address
TARGET = btc
SRCS = main.cpp BitcoinExchange.cpp
OBJS = $(SRCS:.cpp=.o) 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re