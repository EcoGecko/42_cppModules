#NAME
NAME= Animals

#COMPILING
CXX= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -pedantic
RM= rm -rf
MEM= valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes
GDB= gdb --tui

#FILES
SRCF= main Animal Dog Cat WrongAnimal WrongCat

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
	./${NAME}

mem:
	make re DEBUG=1
	${MEM} ./${NAME}

debug:
	make re DEBUG=1
	${GDB} ./${NAME}

.PHONY: all clean fclean re debug mem
