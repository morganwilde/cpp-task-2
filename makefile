CC = g++
PARTS = Controllers/Window.cpp
FLAG_DEBUG = -DDEBUG

all: main.cpp
	$(CC) $(FLAG_DEBUG) $(PARTS) main.cpp -o main
	./main