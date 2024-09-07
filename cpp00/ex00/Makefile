#Name
NAME= megaphone

#Compiling
CXX= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -pedantic

RM= rm -rf

#FILES
SRCF= megaphone

SRCS= $(addsuffix .cpp, $(SRCF))
OBJS= $(addsuffix .o, $(SRCF))

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

bonus:

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
