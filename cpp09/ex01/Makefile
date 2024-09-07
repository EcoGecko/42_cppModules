#NAME
NAME= RPN

#COMPILING
CXX= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -pedantic
RM= rm -rf
MEM= valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes
GDB= gdb --tui

#FILES
SRCF= main RPN

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

run: re
	./${NAME} "8 9 * 9 - 9 - 9 - 4 - 1 +"

mem:
	make re DEBUG=1
	${MEM} ./${NAME} "8 9 * 9 - 9 - 9 - 4 - 1 +"

debug:
	make re DEBUG=1
	#${GDB} ./${NAME} "8 9 * 9 - 9 - 9 - 4 - 1 +"

.PHONY: all clean fclean re debug mem
