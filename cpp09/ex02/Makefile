#NAME
NAME= PmergeMe

#COMPILING
CXX= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -pedantic
RM= rm -rf
MEM= valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes
GDB= gdb --tui

#FILES
SRCF= main PmergeMe

SRCS= $(addsuffix .cpp, $(SRCF))
OBJS= $(addsuffix .o, $(SRCF))

ifdef DEBUG
	CXXFLAGS += -g3
endif

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

5000: re
	./${NAME} `shuf -i 1-100000 -n 5000 | tr "\n" " "`

3000: re
	./${NAME} `shuf -i 1-100000 -n 3000 | tr "\n" " "`

500: re
	./${NAME} `shuf -i 1-100000 -n 500 | tr "\n" " "`

100: re
	./${NAME} `shuf -i 1-100000 -n 100 | tr "\n" " "`

10: re
	./${NAME} `shuf -i 1-100000 -n 10 | tr "\n" " "`

run: re
	./${NAME} `shuf -i 1-100000 -n 3 | tr "\n" " "`

mem:
	make re DEBUG=1
	${MEM} ./${NAME} `shuf -i 1-100000 -n 3000 | tr "\n" " "`

debug:
	make re DEBUG=1

.PHONY: all clean fclean re debug mem

