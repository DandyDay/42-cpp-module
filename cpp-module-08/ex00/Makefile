# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/03 14:15:39 by jinhchoi          #+#    #+#              #
#    Updated: 2024/06/24 11:25:30 by jinhchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easyfind

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDE = .
SRCS = main.cpp
OBJS = ${SRCS:.cpp=.o}

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I $(INCLUDE)

clean :
	@$(RM) $(OBJS)

fclean :
	@make clean
	@$(RM) $(NAME)

re :
	@make fclean
	@make all

.PHONY : all clean fclean re
