prog:background.o main.o
	gcc background.o main.o -o prog -lSDL -lSDL_image -lSDL_mixer 
main.o:main.c
	gcc -c main.c -g
background.o:background.c
	gcc -c background.c -g
