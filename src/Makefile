SRCS = test.c insert.c queue.c match.c print_list.c erase.c
OBJS = ${SRCS:.c=.o}

normal: CC = gcc
normal: project

html: CC = emcc
html:
	${CC} ${SRCS} -o project.html -s WASM=1 

project: ${OBJS}
	${CC} -o project ${OBJS}

.c.o:
	${CC} -c $< -o $@