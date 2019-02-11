C = gcc
CFLAGS = -std=c99
CFLAGS += -g
CFLAGS += -Wall

SRCES = testme.c 
OBJS = testme.o 

testme: ${OBJS} 
	${C} ${CFLAGS} ${OBJS} -o testme -ggdb

testme.o: testme.c 
	${C} ${CFLAGS} -c testme.c 

clean: 
	 rm *.o testme 
