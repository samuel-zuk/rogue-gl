CC=gcc
CFLAGS=-g -Wall -I include
LFLAGS=-lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
OBJ=main.o glad.o
EXE=main

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) $(LFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

glad.o: src/glad.c
	$(CC) $(CFLAGS) -c src/glad.c

.PHONY: clean
clean:
	rm $(EXE) $(OBJ) 2>/dev/null >/dev/null; exit 0
