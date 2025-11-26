SRC = main.cpp  

NAME = Template_functions

CC = c++

HEADER =  iter.hpp 

FLAG =  -Wall -Wextra -Werror -std=c++98

OBJ = ${SRC:.cpp=.o}


%.o : %.cpp ${HEADER}
	${CC} ${FLAG}  -c $< -o $@

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${FLAG} ${OBJ} -o ${NAME}

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}

re : fclean all