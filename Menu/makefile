prog:main.o menu.o
	gcc main.o menu.o  -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lm -o prog -g

main.o:main.c
	gcc -c main.c -g

menu.o:menu.c
	gcc -c menu.c -g