CC = g++
CFLAGS = -std=c++11 -Wall
LIBS = -lGL -lGLU -lglut -L/usr/lib64 -lstdc++

OBJS = main.o polygon.o matrix.o

drawer: ${OBJS}
	${CC} ${CFLAGS} -o drawer ${OBJS} ${LIBS}

main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp ${LIBS}

polygon.o: polygon.cpp polygon.h
	${CC} ${CFLAGS} -c polygon.cpp

matrix.o: matrix.cpp matrix.h
	${CC} ${CFLAGS} -c matrix.cpp

clean:
	rm -f drawer ${OBJS}
	@echo "all cleaned up!"