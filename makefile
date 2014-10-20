CC = g++
FLAG_DEBUG = -DDEBUG
CFLAGS = -Wno-deprecated-declarations
LFLAGS = -framework GLUT -framework OpenGL -framework Cocoa \
-I/usr/local/include -I/opt/X11/include -I/opt/X11/lib
PARTS = Controllers/Window.cpp

all: main.cpp
	$(CC) $(FLAG_DEBUG) $(CFLAGS) $(PARTS) main.cpp -o main $(LFLAGS)
	./main