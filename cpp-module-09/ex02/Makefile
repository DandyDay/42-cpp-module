# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/03 14:15:39 by jinhchoi          #+#    #+#              #
#    Updated: 2024/08/29 09:52:21 by jinhchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDE = .
SRCS = main.cpp PmergeMe.cpp
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
