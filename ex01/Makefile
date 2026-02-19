# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 19:46:44 by mmitkovi          #+#    #+#              #
#    Updated: 2026/02/19 19:46:45 by mmitkovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= form

CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98

SRCS    := main.cpp \
			Bureaucrat.cpp \
			Form.cpp

OBJS    := $(SRCS:.cpp=.o)

DEPS    := Bureaucrat.hpp \
			Form.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re